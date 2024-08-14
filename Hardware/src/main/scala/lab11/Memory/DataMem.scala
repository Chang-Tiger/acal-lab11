package Memory

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFileInline
import AXI._

class DataMem(
    width: Int,
    height: Int,
    idWidth: Int,
    addrWidth: Int,
    dataWidth: Int,
    baseAddr: BigInt,
    latency: Int,
    filePath: String
) extends Module {
  val io = IO(new Bundle {
    val slave = new Axi4SlaveIF(idWidth, addrWidth, dataWidth, 2)
    val dump = Input(Bool())
  })

  val memory = Mem(height, UInt(width.W))
  loadMemoryFromFileInline(memory, filePath)

  

  val readID = RegInit(0.U(idWidth.W))
  val rAddrOffset = RegInit(0.U(addrWidth.W))
  val wAddrOffset = WireDefault(
    ((io.slave.aw.bits.addr - baseAddr.U) & ~(3.U(width.W))) >> 2.U
  )
  val writeAddressReg = RegInit(0.U(addrWidth.W))
  val writeID = RegInit(0.U(idWidth.W))
  val sIdle :: sReady :: sWLatency :: sFinish :: sWaitData :: sGetData :: Nil = Enum(6)
  val sRead :: sRLatency :: sRSending :: sResp :: Nil = Enum(4)
  val writeState = RegInit(sIdle)
  val readState = RegInit(sRead)
  val rLatencyCounter = RegInit(0.U(8.W))
  val wLatencyCounter = RegInit(0.U(8.W))

  // for burst mode supporting
  val rlength        = RegInit(0.U(4.W))
  val rburst_counter = RegInit(0.U(4.W))
  val wburst_counter = RegInit(0.U(4.W))
  //val rcurrentAddr   = RegInit(0.U(addrWidth.W))
  val readLast      = WireDefault(rburst_counter === rlength)



  // aw channel
  io.slave.aw.ready := false.B

  // w channel
  io.slave.w.ready := false.B

  // b channel
  io.slave.b.bits.id := 0.U
  io.slave.b.bits.resp := 0.U
  io.slave.b.valid := false.B

  // ar channel
  io.slave.ar.ready := false.B

  // r channel
  io.slave.r.bits.id := 0.U
  io.slave.r.bits.data := 0.U
  io.slave.r.bits.resp := 0.U
  io.slave.r.bits.last := readLast//false.B  //modified====
  io.slave.r.valid := false.B
  //=============================


  switch(readState) {
    is(sRead) {
      when(io.slave.ar.valid) {
        when(latency.U === 1.U) {
          readState := sRSending//modified===sResp
        }
        .otherwise {
          readState := sRLatency
        }
      }
    }
    is(sRLatency) {
      when(rLatencyCounter === (latency - 1).U) {
        readState := sRSending//modified===sResp
      }
    }
    is(sRSending){
      when(io.slave.r.ready){
        readState := sResp
      }
    }
    is(sResp) {
      when(readLast){//modified
        readState := sRead
      }.otherwise{
        readState := sRSending
      }
    }
  }

  when(readState === sRead) {
    io.slave.ar.ready := true.B
    io.slave.r.valid := false.B
    rAddrOffset := ((io.slave.ar.bits.addr - baseAddr.U) & ~(3.U(width.W))) >> 2.U
    readID := io.slave.ar.bits.id

    //modified============
    rlength := Mux(io.slave.ar.valid, io.slave.ar.bits.len, rlength)
    //rcurrentAddr := Mux(io.slave.ar.valid, io.slave.ar.bits.addr, rcurrentAddr)
    //====================
  }
  .elsewhen(readState === sRLatency) {
    rLatencyCounter := rLatencyCounter + 1.U
  }
  .elsewhen(readState === sRSending) {
    //blank
  }
  .elsewhen(readState === sResp) {
    rLatencyCounter := 0.U
    io.slave.ar.ready := false.B
    io.slave.r.valid := true.B
    io.slave.r.bits.data := memory(rAddrOffset)
    io.slave.r.bits.id := readID
    io.slave.r.bits.resp := 0.U
    //modified====================
    rburst_counter := Mux(io.slave.r.ready & (~readLast),
      rburst_counter + 1.U,
      Mux(io.slave.r.ready & readLast,
        0.U, // reset counter
        rburst_counter
      )
    )
    rAddrOffset := Mux(io.slave.r.ready, rAddrOffset + 4.U, rAddrOffset)//??????????
    //============================
  }
  //modified==============
  switch(writeState) {
    is(sIdle) {
      writeState := sReady
    }
    is(sReady) {
      //when(aw.valid && burst mode!=0)//*************
      when(io.slave.w.valid || (io.slave.aw.valid && io.slave.w.valid)) {
        when(latency.U === 1.U & io.slave.w.bits.last) {
          writeState := sFinish 
        }.elsewhen(latency.U === 1.U){
          writeState := sGetData
        }
        .otherwise {
          writeState := sWLatency
        }
      }
      .elsewhen(io.slave.aw.valid) {
        writeState := sWaitData
      }
    }
    is(sWaitData) {//wait for w.valid
      when(io.slave.w.valid) {
        when(latency.U === 1.U & io.slave.w.bits.last) {
          writeState := sFinish 
        }.elsewhen(latency.U === 1.U){
          writeState := sGetData
        }.otherwise {
          writeState := sWLatency
        }
      }
    }
    is(sWLatency) {
      when(wLatencyCounter === (latency - 1).U & io.slave.w.bits.last){
        writeState := sFinish
      }.elsewhen(wLatencyCounter === (latency - 1).U){
        writeState := sGetData
      }
    }
    is(sGetData) {
      writeState := sReady
    }
    is(sFinish) {
      when(io.slave.b.ready) {
        writeState := sReady
      }
    }
  }

  val writeData = WireDefault(VecInit(Seq.fill(dataWidth / 8)(0.U(8.W))))
  List.range(0, dataWidth / 8).map { x =>
    when(io.slave.w.bits.strb(x) === 1.U) {
      writeData(x) := io.slave.w.bits.data(x * 8 + 7, x * 8)
    }.otherwise {
      writeData(x) := memory(wAddrOffset)(x * 8 + 7, x * 8)
    }
  }

  when(writeState === sIdle) {
    io.slave.aw.ready := false.B
    io.slave.w.ready := false.B
    io.slave.b.bits.resp := 0.U
    io.slave.b.valid := false.B
  }
  .elsewhen(writeState === sReady) {
    io.slave.aw.ready := true.B
    io.slave.w.ready := true.B
    when(io.slave.w.valid) {
      memory(wAddrOffset) := writeData.asUInt()
      writeAddressReg := wAddrOffset
      writeID := io.slave.aw.bits.id
    }
    .elsewhen(io.slave.aw.valid) {
      writeAddressReg := wAddrOffset
      writeID := io.slave.aw.bits.id
    }
    io.slave.b.bits.resp := 0.U
    io.slave.b.valid := false.B


    //================
    wburst_counter := Mux(
        io.slave.w.valid,
        wburst_counter + 1.U,
        wburst_counter
      )


    
  }
  .elsewhen(writeState === sWaitData) {
    io.slave.aw.ready := false.B
    io.slave.w.ready := true.B
    io.slave.b.bits.resp := 0.U
    io.slave.b.valid := false.B
    when(io.slave.w.valid) {
      memory(writeAddressReg) := writeData.asUInt()
    }

    
  }
  .elsewhen(writeState === sWLatency) {
    wLatencyCounter := wLatencyCounter + 1.U
  }
  .elsewhen(writeState === sGetData) {
    wLatencyCounter := 0.U
    io.slave.aw.ready := false.B
    io.slave.w.ready := false.B
    io.slave.b.bits.resp := 0.U
    io.slave.b.bits.id := writeID
    //wAddrOffset := wAddrOffset + 4.U//??????????
    //wAddrOffset := Mux(io.slave.w.valid, wAddrOffset + 4.U, wAddrOffset)//??????????
  }
  .elsewhen(writeState === sFinish) {
    wLatencyCounter := 0.U
    io.slave.aw.ready := false.B
    io.slave.w.ready := false.B
    io.slave.b.bits.resp := 0.U
    io.slave.b.bits.id := writeID
    io.slave.b.valid := true.B

    wburst_counter := 0.U//
  }

  when(io.dump) {
    /* Dump Memory */
    printf("\t\t======== Data Memory Dump ========\n")
    printf(p"\t\tFrom base address ${baseAddr}\n")
    for (i <- 0 until 64) {
      val indexAddr = (baseAddr + i * 4).asUInt
      val data = memory(i.U).asSInt
      printf(
        p"\t\tDataMem[${i}] (address = ${Hexadecimal(indexAddr)}) = 0x${Hexadecimal(data)} (${data})\n"
      )
    }
    printf("\n")
  }

}


