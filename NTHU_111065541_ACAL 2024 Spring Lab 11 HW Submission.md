(NTHU_111065541_張騰午) ACAL 2024 Spring Lab 11 HW Submission 
===


###### tags: `AIAS Spring 2024` `Submission Template`



[TOC]

## 作業說明

You can check out different branches to represent various assignments or organize specific assignments using folders. You can decide on the branch names yourselves.


## Homework 11-1 SoC Integration with CPU

> Please paste the link close to the parentheses
- [Hw 11-1 Branch link](https://course.playlab.tw/git/Tiger_Chang/lab11.git)

1. Revise system configuration and design address mapping scheme(Explain how you design)
2. Integrate CPU, bus and memory
```scala=
//top_SoC.scala
//system configuration
object SystemConfig {
        val nMasters: Int = 1
        val nSlaves: Int = 1
        val LocalMemBaseAddr: Int = 0x8000
        val LocalMemSize: Map[String, Int] = Map(
          "Size" -> 2048, // Height x Width
          "Height" -> 64, // The Number of bytes
          "Width" -> 32 // unit: 32 bits
        )
        val LocalMemLatency: Int = 1
        val LocalMemInitFilePath: String = "./src/main/resource/data1.hex" // Provide the file path
    }

    val cpu = Module(new PipelinedCPU(15, 32))
    val im = Module(new InstMem(15))
    
    val bus = Module(
        new AXILiteXBar(
          SystemConfig.nMasters,
          SystemConfig.nSlaves,
          idWidth,
          addrWidth,
          dataWidth,
          Seq(
            (SystemConfig.LocalMemBaseAddr, SystemConfig.LocalMemSize("Size")),
          )
        )
      )

    val localMem = Module(
            new DataMem(
              SystemConfig.LocalMemSize("Width"),
              SystemConfig.LocalMemSize("Height"),
              idWidth,
              addrWidth,
              dataWidth,
              SystemConfig.LocalMemBaseAddr,
              SystemConfig.LocalMemLatency,
              SystemConfig.LocalMemInitFilePath
            )
          )
    
    
    // Bus Interface
    bus.io.masters(0) <> cpu.io.master
    bus.io.slaves(0) <> localMem.io.slave
    
    // Data Memory
    localMem.io.dump := io.Dump_Mem
    cpu.io.DataMem.rdata := localMem.io.slave.r.bits.data 
```
```scala=
//PiplinedCPU.scala
//design FSM to complete handshake between master/slave in write/read
//......
 // control write/read mask,loc
    val r_mask = Wire(UInt(32.W))
    val write_shift_bit = Wire(UInt(5.W))

    var w_choose_byte = io.DataMem.waddr & "b11".U(32.W)
    var w_choose_half = io.DataMem.waddr & "b10".U(32.W)
    
    io.master.w.bits.strb := MuxLookup(io.DataMem.Length,"b1111".U,Seq(
        Byte -> MuxLookup(w_choose_byte, "b0001".U,Seq(
            0.U -> "b0001".U,
            1.U -> "b0010".U,
            2.U -> "b0100".U,
            3.U -> "b1000".U
        )),
        Half -> MuxLookup(w_choose_half, "b0011".U,Seq(
            0.U -> "b0011".U,
            1.U -> "b1100".U
        )),
        Word -> "b1111".U
    ))
    //data之後要shift
    write_shift := MuxLookup(io.DataMem.Length, 0.U, Seq(
        Byte -> MuxLookup(w_choose_byte, 0.U, Seq(
            0.U -> 0.U,
            1.U -> 8.U,
            2.U -> 16.U,
            3.U -> 24.U
        )),
        Half -> MuxLookup(w_choose_half, 0.U, Seq(
            0.U -> 0.U,
            1.U -> 16.U
        )),
        Word -> 0.U
    ))
    var r_choose_byte = io.DataMem.raddr & "b11".U(32.W)
    var r_choose_half = io.DataMem.raddr & "b10".U(32.W)
    
    //決定取words(4bytes)哪個部分的mask
    val r_mask = Wire(UInt(32.W))

    r_mask := MuxLookup(io.DataMem.Length,"hffffffff".U, Seq(
        Byte -> MuxLookup(r_choose_byte, "h000000ff".U, Seq(
            0.U -> "h000000ff".U(32.W),
            1.U -> "h0000ff00".U(32.W),
            2.U -> "h00ff0000".U(32.W),
            3.U -> "hff000000".U(32.W)
        )),
        Half -> MuxLookup(r_choose_half, "h0000ffff".U(32.W), Seq(
            0.U -> "h0000ffff".U(32.W),
            1.U -> "hffff0000".U(32.W)
        )),
        Word -> "hffffffff".U(32.W)
    ))
    //取data後要shift
    val read_shift = Wire(UInt(5.W))
    read_shift := MuxLookup(io.DataMem.Length, 0.U, Seq(
        Byte -> MuxLookup(r_choose_byte, 0.U, Seq(
            0.U -> 0.U,
            1.U -> 8.U,
            2.U -> 16.U,
            3.U -> 24.U
        )),
        Half -> MuxLookup(r_choose_half, 0.U, Seq(
            0.U -> 0.U,
            1.U -> 16.U
        )),
        Word -> 0.U
    ))


    
//......
// write state
    val wIdle :: wAddr :: wWaitResp :: Nil = Enum(3)
    val wState = RegInit(wIdle)

    switch(wState) {
        is(wIdle) {
            when (io.DataMem.Mem_W) {
                wState := wAddr
            }
        } 
        is(wAddr) {
            when (io.master.w.ready && io.master.aw.ready) {
                wState := wWaitResp
            }
        }
        is(wWaitResp) {
            when(io.master.b.valid) {
                wState := wIdle
            }
        }
    }
    
    when(wState === wAddr) {
        io.master.aw.valid     := true.B
        io.master.w.valid      := true.B
        io.master.aw.bits.addr := io.DataMem.waddr
        io.master.w.bits.data  := io.DataMem.wdata << write_shift//取下來的data必須平移最左
        io.master.b.ready      := true.B
    }

    when(wState === wWaitResp) {
        io.master.b.ready      := true.B
    }

    // read state
    val rIdle :: rAddr :: rWaitValid :: Nil = Enum(3)
    val rState = RegInit(rIdle)

    switch(rState) {
        is(rIdle) {
            when (io.DataMem.Mem_R) {
                rState := rAddr
            }
        } 
        is(rAddr) {
            when (io.master.ar.ready) {
                rState := rWaitValid
            }
        }
        is(rWaitValid) {
            when(io.master.r.valid) {
                rState := rIdle
            }
        }
    }

    when(rState === rAddr) {
        io.master.ar.valid      := true.B
        io.master.ar.bits.addr  := io.DataMem.raddr
        io.master.r.ready       := true.B
    }
    when(rState === rWaitValid) {
        io.master.r.ready       := true.B
    }
    //......
    //MEM Block Datapath 取read data的值也要通過mask並平移
    datapath_MEM.io.Mem_Data := (io.master.r.bits.data & r_mask) >> read_shift
```

 
    
3. Run the **Emulator/test_code/scalar_Convolution_2D.S** and paste the result(Screenshot)
![](https://course.playlab.tw/md/uploads/1dd8fe03-fa74-4a2d-a795-a7efca058294.png)

## Homework 11-2 Performance Enhancement Using DMA

> Please paste the link close to the parentheses
- [Hw 11-2 Branch link](https://course.playlab.tw/git/Tiger_Chang/lab11/-/tree/11-2/Hardware/src/test/scala/lab11/AXI_lite?ref_type=heads)

1. Revise system configuration and design address mapping scheme(Explain how you design)
```scala=
//top_SoC.scala
//2 masters: CPU,DMA. 3 slavers: DMA,gloalMem,localMem.
 object SystemConfig {
        val nMasters: Int = 2
        val nSlaves: Int = 3
        val LocalMemBaseAddr: Int = 0x8000
        val LocalMemSize: Map[String, Int] = Map(
          "Size" -> 2048, // Height x Width
          "Height" -> 64, // The Number of bytes
          "Width" -> 32 // unit: 32 bits
        )
        val DMABaseAddr: Int = 0
        val DMASize: Int = 100

        val LocalMemLatency: Int = 1
        val LocalMemInitFilePath: String = "./src/main/resource/data0.hex"
        val GlobalMemBaseAddr: Int = 0x10000 // Provide the base address
        val GlobalMemSize: Map[String, Int] = Map(
          "Size" -> 2048, // Height x Width
          "Height" -> 64, // The Number of bytes
          "Width" -> 32 // unit: 32 bits
        )
        val GlobalMemLatency: Int = 80//set to 80
        val GlobalMemInitFilePath: String = "./src/main/resource/data1.hex"

    }
    val dma = Module(new DMA(idWidth, addrWidth, dataWidth, SystemConfig.DMABaseAddr))
    val cpu = Module(new PipelinedCPU(32, 32))
    val im = Module(new InstMem(15))
    
    val bus = Module(
        new AXILiteXBar(
          SystemConfig.nMasters,
          SystemConfig.nSlaves,
          idWidth,
          addrWidth,
          dataWidth,
          Seq(
            (SystemConfig.DMABaseAddr, SystemConfig.DMASize),
            (SystemConfig.LocalMemBaseAddr, SystemConfig.LocalMemSize("Size")),
            (SystemConfig.GlobalMemBaseAddr, SystemConfig.GlobalMemSize("Size")),
          )
        )
      )

    val localMem = Module(
      new DataMem(
        SystemConfig.LocalMemSize("Width"),
        SystemConfig.LocalMemSize("Height"),
        idWidth,
        addrWidth,
        dataWidth,
        SystemConfig.LocalMemBaseAddr,
        SystemConfig.LocalMemLatency,
        SystemConfig.LocalMemInitFilePath
      )
    )
    val globalMem = Module(
        new DataMem(
          SystemConfig.GlobalMemSize("Width"),
          SystemConfig.GlobalMemSize("Height"),
          idWidth,
          addrWidth,
          dataWidth,
          SystemConfig.GlobalMemBaseAddr,
          SystemConfig.GlobalMemLatency,
          SystemConfig.GlobalMemInitFilePath
        )
    )

```
2. Integrate CPU, bus, memory and dma 
```scala=
//top_SoC.scala
// Bus Interface
    bus.io.masters(0) <> cpu.io.master
    bus.io.masters(1) <> dma.io.master
    
    bus.io.slaves(0) <> dma.io.slave
    bus.io.slaves(1) <> localMem.io.slave
    bus.io.slaves(2) <> globalMem.io.slave

    
    //data Memory
    cpu.io.DataMem.rdata := localMem.io.slave.r.bits.data

    localMem.io.dump := io.Dump_Mem//false.B
    globalMem.io.dump := false.B
    // Ins Memory
    cpu.io.InstMem.rdata := im.io.inst
    im.io.raddr := cpu.io.InstMem.raddr
    
    
    //system
    cpu.io.InstMem.Valid := true.B
    cpu.io.DataMem.Valid := true.B
    io.DMA_Hcf := dma.io.Hcf
    io.regs := cpu.io.regs
    io.Hcf := cpu.io.Hcf
    io.rdata := cpu.io.master.r.bits.data
    io.wdata :=  cpu.io.master.w.bits.data
    cpu.io.DMA_Hcf := dma.io.Hcf
    io.inst := im.io.inst
```
3. Revise software program and generate binary files using emulator(Explain how you revise the program)
先把所有global mem一次性搬到local，使用DMA指令，將dest,src,cfg,等資訊存到DMA memory-mapped register中，然後enable，來執行DMA搬運指令，之後個別save,load指令就不用再用到DMA了。
```mipsasm=
#scalar_Convolution2.S
.data
## input data size = 2x8x8
input_data:
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7

.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7
.byte 0 1 2 3 4 5 6 7

## kernel size 2x3x3
kernel_data:
.byte 0 1 2
.byte 0 1 2
.byte 0 1 2

.byte 0 1 2
.byte 0 1 2
.byte 0 1 2

## output data size 1x5x5
output_data:
.byte 0 0 0 0 0 0
.byte 0 0 0 0 0 0
.byte 0 0 0 0 0 0
.byte 0 0 0 0 0 0
.byte 0 0 0 0 0 0
.byte 0 0 0 0 0 0


.text
main:

li sp,0x10000
li a2,8
li a3,3
li a4,6
la a5,input_data
la a6,kernel_data
la a7,output_data

#move all mem from global to local
# src addr-4
li  t0, 0x10000
sw  t0, 4(x0)
# dest addr-8
li  t0, 0x8000
sw  t0, 8(x0)
# CFG-12  SS-DS-TH-TW
li  t0, 0x04040425
sw  t0, 12(x0)
#ENABLE-0
li  t0, 1
sw  t0, 0(x0)
#=============================

jal ra, Conv2D
addi a5,a5,64
addi a6,a6,9
jal ra,Conv2D

lw s6,0(a7)
lw s7,6(a7)
lw s8,12(a7)
lw s9,18(a7)
lw s10,24(a7)
lw s11,30(a7)

nop
nop
nop
nop
nop
hcf

Conv2D:
srli s0,a3,1
li t0,0
bge t0,a4,endLoop1
Loop1:
li t1,0
bge t1,a4,endLoop2
Loop2:
li t2,0
bge t2,a3,endLoop3
Loop3:
li t3,0
bge t3,a3,endLoop4
Loop4:
sub s1,t2,s0
add s1,s1,t0
addi s1,s1,1
sub s2,t3,s0
add s2,s2,t1
addi s2,s2,1

mul s3,s1,a2
add s3,s3,s2
add s3,s3,a5
lb s3,0(s3)

mul s4,t2,a3
add s4,s4,t3
add s4,s4,a6
lb s4,0(s4)

mul s3,s3,s4

mul s4,t0,a4
add s4,s4,t1
add s4,s4,a7
lb s5,0(s4)

add s5,s5,s3
sb s5,0(s4)

addi t3,t3,1
blt t3,a3,Loop4
endLoop4:
addi t2,t2,1
blt t2,a3,Loop3
endLoop3:
addi t1,t1,1
blt t1,a4,Loop2
endLoop2:
addi t0,t0,1
blt t0,a4,Loop1
endLoop1:
    ret

```
4. Run the **Emulator/test_code/scalar_Convolution_2D.S** and paste the result(Screenshot)
![](https://course.playlab.tw/md/uploads/9f4d1a13-5ecf-4b01-b3e9-51dcd111d145.png)





## Homework 11-3 Support and AXI Bus Implemention with Burst Mode

> Please paste the link close to the parentheses
- [Hw 11-3 Branch link](https://course.playlab.tw/git/Tiger_Chang/lab11/-/tree/11-3/Hardware/src/test/scala/lab11/AXI_lite?ref_type=heads)

1. My burst mode testbench:
    將master還有slave都接在testbench上模擬burst mode
    傳一個read request，slave連續回傳兩筆data，第一筆last為0下一筆是最後一筆才是1
    ![](https://course.playlab.tw/md/uploads/06ad079c-bd19-474c-b220-f9a3877ae432.png)


```scala=
class AXILiteXBarBurstTest
    extends AnyFlatSpec
    with ChiselScalatestTester
    with AXITester {

  "Masters" should "send/read data to each Slaves according to addr" in {
    test(
      new AXILiteXBar(
        AXI_Config2.master_num,
        AXI_Config2.slave_num,
        AXI_Config2.s_id_width,
        AXI_Config2.addr_width,
        AXI_Config2.data_width,
        AXI_Config2.addr_map
      )
    ).withAnnotations(
      Seq(
        WriteVcdAnnotation
      )
    ) { dut =>
      /* Initialize IO ports */
      // * masters
      for (i <- 0 until AXI_Config2.master_num) {
        // input port
        dut.io.masters(i).ar.initSource().setSourceClock(dut.clock)
        dut.io.masters(i).aw.initSource().setSourceClock(dut.clock)
        dut.io.masters(i).w.initSource().setSourceClock(dut.clock)

        // output ports
        dut.io.masters(i).r.initSink().setSinkClock(dut.clock)
        dut.io.masters(i).b.initSink().setSinkClock(dut.clock)
      }
      // * slaves
      for (i <- 0 until AXI_Config2.slave_num) {
        // input port
        dut.io.slaves(i).r.initSource().setSourceClock(dut.clock)
        dut.io.slaves(i).b.initSource().setSourceClock(dut.clock)

        // output ports
        dut.io.slaves(i).ar.initSink().setSinkClock(dut.clock)
        dut.io.slaves(i).aw.initSink().setSinkClock(dut.clock)
        dut.io.slaves(i).w.initSink().setSinkClock(dut.clock)
      }

      println("----START TEST----")

      println("[Test] AXI READ test")
      println("[Test]: Masters read from slave according to addr")
      println("[Test]: Slaves respond burst data ")

      dut.io.masters(0).ar.valid.poke(true.B)
      dut.io.masters(0).r.ready.poke(true.B)
      fork {//master傳出一個read data request給一個addr
        dut.io.masters(0).ar.enqueue(genAXIAddr(BigInt("9000", 16).toInt))

      }.fork {//slave連續給兩筆data(依據fixed burst len)
        dut.io.slaves(0).r.enqueue(genAXIReadData(0, BigInt("00010203", 16).toInt, false))
        dut.io.slaves(0).r.enqueue(genAXIReadData(0, BigInt("0c0d0e0f", 16).toInt, true))
      }.fork.withRegion(Monitor){//等待rvalid轉正
        while(!(dut.io.masters(0).r.valid.peek().litToBoolean)){
          dut.clock.step(1)
        }
        println("[Test] First try")
        
        println("[Test]: Slave observe address 0x" + dut.io.slaves(0).ar.bits.addr.peek().litValue.toString(16))
          //print出收到的data還有是否是last第一筆last為false
        println("[Test]: Master 0 observe data 0x" + dut.io.masters(0).r.bits.data.peek().litValue.toString(16)+", r.last: " + dut.io.masters(0).r.bits.last.peek().litValue.toString(16))
        dut.clock.step(1)
        //master將自己的ready拉正等下一筆data
        dut.io.masters(0).r.ready.poke(true.B)
        //等待rvalid轉正
        while(!(dut.io.masters(0).r.valid.peek().litToBoolean)){
          dut.clock.step(1)
        }
          //print出收到的data還有是否是last第二筆last為true
        println("[Test]: Master 0 observe data 0x" + dut.io.masters(0).r.bits.data.peek().litValue.toString(16)+", r.last: " + dut.io.masters(0).r.bits.last.peek().litValue.toString(16))

      }.joinAndStep(dut.clock)
      //join()

      dut.clock.step(1)

      println("----END----")
      
    }
  }
}
```

> 測試指令  
```
sbt 'testOnly AXILite.AXILiteXBarBurstTest'
```


2. Modify **Data memory**, and **DMA controller (Interface)** to support **AXI Burst Mode**.

做FIXED burst mode但增加要傳輸的length
```scala=
//DMA.scala
//修改要傳的length
io.master.ar.bits.len    := 2.U//0.U
//......
// Mater State Controller
  switch(mState) {
    is(mIdle) {
      // when the Enable register is set, the DMA starts to issue read request
      when(mmio_enable === 1.U) {
        mState := mReadSend
      }
    }
    is(mReadSend) {
      // When the ARREady signal is asserted, the slave accepts the
      // request and the master will move the the mReadResp state
      // and wait for read response
      when(io.master.ar.ready) {
        mState := mReadResp
      }
    }
    is(mReadResp) {
      // whe tne RValid is assert, the data response returns and
      // DMA starts to write the data to the desitnation, issuing
      // write request
      when(io.master.r.valid) {
        mState := mWriteSend
      }
    }
    is(mWriteSend) {
      // when all the write data are sent, wait for write response
      when(mWriteAddrSent && mWriteDataSent) {
        mState := mWriteResp
      }
    }
    is(mWriteResp) {
      // When receiving write response (BValid is assert), complete the DMA operation and return the mIDLE state
      when(io.master.b.valid && mReadlast) {
        mState := mIdle//go to send read request again
      }.elsewhen(io.master.b.valid && !mReadlast){
        mState := mReadResp//if not last go get next data to write
      }
    }
  }

  // Slave State Controller
  switch(sReadState) {
    is(sReadIdle) {
      when(io.slave.ar.valid) {
        sReadState := sReadResp
      }
    }
    is(sReadResp) {
      when(io.slave.r.ready) {
        sReadState := sReadIdle
      }
    }
  }

// master port datapath
  when(mState === mWriteSend) {
    when(io.master.aw.fire) {
      // count how many write requests are sent
      request_counter := request_counter + 1.U
    }
  }
  when(mState === mIdle){mReadlast := false.B}//modified=============
  when(mState === mReadSend) {
    // calculate read request address
    // base address = n * stride
    io.master.ar.bits.addr := mmio_source_info + (request_counter * mmio_size_cfg(31,24))

    // Due to 32-byte alignment in memory,
    // it is necessary to record the offset to determine the starting address of the data we want.
    source_offset := io.master.ar.bits.addr(1,0)
  }

  when(mState === mReadResp && io.master.r.valid) {
    // get read response byte mask
    // mask_width is determined by "width" field(source)
    mask_width := MuxLookup(mmio_size_cfg(15,8),"b1111".U,Seq(
      1.U -> "b0001".U,
      2.U -> "b0011".U,
      3.U -> "b0111".U,
      4.U -> "b1111".U
    ))

    mReadlast := io.master.r.bits.last//whether this's the last in one burst mode sending

    // When we read data back in 32-byte chunks, we design rData_mask to mask out the data we don't need
    rData_mask := mask_width << source_offset

    // get read data value
    List.range(0, 4).map { x =>
      when(rData_mask(x) === 1.U) {
        rData(x) := io.master.r.bits.data(x * 8 + 7, x * 8)
      }
      .otherwise {
        rData(x) := 0.U(8.W)
      }
    }

    // adjust the data order to shift souce_offset * 1 byte
    data_buffer := rData.asUInt >> (source_offset << 3.U)
  }

  when(mState === mWriteSend) {
    // calculate write request address
    // base address = n * stride
    io.master.aw.bits.addr := mmio_dest_info + (request_counter * mmio_size_cfg(23,16))

    // mask_width is determined by "width" field(destination)
    mask_width := MuxLookup(mmio_size_cfg(15,8),"b1111".U,Seq(
      1.U -> "b0001".U,
      2.U -> "b0011".U,
      3.U -> "b0111".U,
      4.U -> "b1111".U
    ))
    // calculate byte mask to mask out the data we don't write
    io.master.w.bits.strb := mask_width << dest_offset

    // adjust data to match write config(destination width)
    io.master.w.bits.data := data_buffer << (dest_offset << 3.U)

  }

  // check DMA operation completion and set signals accordingly
  when(mState === mWriteResp && request_counter === mmio_size_cfg(7,0)) {
    request_counter := 0.U
    mmio_enable := 0.U
    mmio_done   := 1.U
  }

  // check Write Addr and Data status
  when(mState === mWriteSend) {
    when(io.master.w.ready) {
      mWriteDataSent := true.B
    }
    when(io.master.aw.ready) {
      mWriteAddrSent := true.B
    }
  }.otherwise {
    mWriteAddrSent := false.B
    mWriteDataSent := false.B
  }
```

```scala=
//DataMem.scala
// for burst mode supporting
val rlength        = RegInit(0.U(4.W))
val rburst_counter = RegInit(0.U(4.W))
val readLast      = WireDefault(rburst_counter === rlength)
//if counter equal len means it's last one to read

//......
io.slave.r.bits.last := readLast
//......
//add new state sRSending
val sRead :: sRLatency :: sRSending :: sResp :: Nil = Enum(4)
switch(readState) {
    is(sRead) {
      when(io.slave.ar.valid) {//get addr first
        when(latency.U === 1.U) {
          readState := sRSending
        }
        .otherwise {
          readState := sRLatency
        }
      }
    }
    is(sRLatency) {
      when(rLatencyCounter === (latency - 1).U) {
        readState := sRSending
      }
    }
    is(sRSending){//new state to wait rready signal
      when(io.slave.r.ready){
        readState := sResp
      }
    }
    is(sResp) {
      when(readLast){
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

    //sRead state get total length of data to read
    rlength := Mux(io.slave.ar.valid, io.slave.ar.bits.len, rlength)
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
    //使用count計算是否到last
    rburst_counter := Mux(io.slave.r.ready & (~readLast),
      rburst_counter + 1.U,
      Mux(io.slave.r.ready & readLast,//if readlast reset counter
        0.U, // reset counter
        rburst_counter
      )
    )
    rAddrOffset := Mux(io.slave.r.ready, rAddrOffset + 4.U, rAddrOffset)//addr+4
  }


```
4. Do performance analysis to explain why the AXI Burst mode helps the performance.
    ![](https://course.playlab.tw/md/uploads/d824b323-fcff-4727-873f-1d243dad7afb.png)

    ![](https://course.playlab.tw/md/uploads/432edd20-a53b-4ea2-a782-257410e4ce9a.png)




 
    :::warning
    Run the **Emulator/test_code/scalar_Convolution_2D.S** test on your CPU and 
    paste the result Here (Screenshot).
    :::

## Homework 11-4 Performance Analysis and Comparison

> This section requires you to answer the questions in the document. You can directly analyze the results or experiment with different hardware configurations or software programs to analyze the results and then write down your thoughts.

11-1
![](https://course.playlab.tw/md/uploads/bfc52ec1-42a0-4d1e-8960-529631ba9c33.png)
11-2
![](https://course.playlab.tw/md/uploads/4acdba65-615b-4eb1-a23d-9f901a9da856.png)
11-3
![](https://course.playlab.tw/md/uploads/d824b323-fcff-4727-873f-1d243dad7afb.png)

> Do you think the results are reasonable? Does it match your expectation?
> A : 效果有點不如預期，照理來說11-1~3增加DMA, burst mode好像應該要越來越快，但實際上cycle反而變多了，推測11-2是因為assembly檔在開頭加了指令導致指令變多，但整個code要搬運的mem規模其實並沒有很大因此DMA效果出不來。而11-3則是因為只在DMA對datamem間使用burst mode，並為了使用burst mode在datamem的FSM中增加了state，同樣因為整個code要搬運的mem規模其實並沒有很大，而在普通的CPU取用datamem時反而因為state變多增加了cycle，以後應該可以嘗試減少state數量來改善這件事情。
> Are you satisfied with the performance enhancement or not? If not, what can you do to further improve the performance?
> A : 如剛剛所述以後應該可以嘗試減少state數量來改善效能，另外現在burst mode基本只在DMA對datamem read request時才觸發，若進一步設計成write時也觸發減少傳addr的cycle或許可以再改善一些。


一點小小的建言:
這次lab真的做得很辛苦...太多搞不清楚的東西，還有例如emulator產生檔案資料長度和硬體架構不同，和同學討論很久才去改translate檔案把產生data變成4bytes一組才能讓硬體讀，感覺這種本來並不在lab相關敘述的問題好像並非這lab要學的東西。或許有些事情真的搞清楚作法後會發現並不是那麼難，但我覺得這次lab大家都花很多時間想"要怎麼做"，很多時候即使弄懂了原理還是難以實作，可能第一時間想到的做法太過複雜難以實行或是仍無法將理論與實作連結，因此卡在毫無頭緒的狀況下，有時也不是大家不願意問問題，而是不知該怎麼問，有幾次我問了TA很多沒有切中重點的問題，反而會問了之後依然毫無頭緒(還是很謝謝TA在我越問越多時願意花費時間和我約好幾次線上meeting)。我明白這堂課會讓大家體驗現實工作中一些自己survey自己摸索的情況，但還是會希望畢竟我們仍在學習階段多點引導能幫助同學少點冤枉路。



