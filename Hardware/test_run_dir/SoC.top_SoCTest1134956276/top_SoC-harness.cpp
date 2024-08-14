
#include "Vtop_SoC.h"
#include "verilated.h"
#include "veri_api.h"
#if VM_TRACE
#include "verilated_vcd_c.h"
#endif
#include <iostream>
class top_SoC_api_t: public sim_api_t<VerilatorDataWrapper*> {
    public:
    top_SoC_api_t(Vtop_SoC* _dut) {
        dut = _dut;
        main_time = 0L;
        is_exit = false;
#if VM_TRACE
        tfp = NULL;
#endif
    }
    void init_sim_data() {
        sim_data.inputs.clear();
        sim_data.outputs.clear();
        sim_data.signals.clear();

        sim_data.inputs.push_back(new VerilatorCData(&(dut->clock)));
        sim_data.inputs.push_back(new VerilatorCData(&(dut->reset)));
        sim_data.inputs.push_back(new VerilatorCData(&(dut->io_Dump_Mem)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_DMA_Hcf)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_EXE_Branch)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_EXE_Jump)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_WB_wdata)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_WB_rd)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_raddr)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_ALU_src2)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_ALU_src1)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_EXE_src2)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_EXE_src1)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_EXE_alu_out)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_WB_PC)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_MEM_PC)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_EXE_PC)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_ID_PC)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_IF_PC)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_Stall_DH)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_Stall_MA)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_Flush)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_E_Branch_taken)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_wdata)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_rdata)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_inst)));
        sim_data.outputs.push_back(new VerilatorCData(&(dut->io_Hcf)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_0)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_1)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_2)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_3)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_4)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_5)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_6)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_7)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_8)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_9)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_10)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_11)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_12)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_13)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_14)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_15)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_16)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_17)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_18)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_19)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_20)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_21)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_22)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_23)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_24)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_25)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_26)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_27)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_28)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_29)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_30)));
        sim_data.outputs.push_back(new VerilatorIData(&(dut->io_regs_31)));
        sim_data.signals.push_back(new VerilatorCData(&(dut->reset)));
        sim_data.signal_map["top_SoC.reset"] = 0;
    }
#if VM_TRACE
     void init_dump(VerilatedVcdC* _tfp) { tfp = _tfp; }
#endif
    inline bool exit() { return is_exit; }

    // required for sc_time_stamp()
    virtual inline double get_time_stamp() {
        return main_time;
    }

    private:
    Vtop_SoC* dut;
    bool is_exit;
    vluint64_t main_time;
#if VM_TRACE
    VerilatedVcdC* tfp;
#endif
    virtual inline size_t put_value(VerilatorDataWrapper* &sig, uint64_t* data, bool force=false) {
        return sig->put_value(data);
    }
    virtual inline size_t get_value(VerilatorDataWrapper* &sig, uint64_t* data) {
        return sig->get_value(data);
    }
    virtual inline size_t get_chunk(VerilatorDataWrapper* &sig) {
        return sig->get_num_words();
    }
    virtual inline void reset() {
        dut->reset = 1;
        step();
    }
    virtual inline void start() {
        dut->reset = 0;
    }
    virtual inline void finish() {
        dut->eval();
        is_exit = true;
    }
    virtual inline void step() {
        dut->clock = 0;
        dut->eval();
#if VM_TRACE
        if (tfp) tfp->dump(main_time);
#endif
        main_time++;
        dut->clock = 1;
        dut->eval();
#if VM_TRACE
        if (tfp) tfp->dump(main_time);
#endif
        main_time++;
    }
    virtual inline void update() {
        // This seems to force a full eval of circuit, so registers with alternate clocks are update correctly
        dut->eval();
        // This was the original call, did not refresh registers when some  other clock transitioned
        // dut->_eval_settle(dut->__VlSymsp);
    }
};

// The following isn't strictly required unless we emit (possibly indirectly) something
// requiring a time-stamp (such as an assert).
static top_SoC_api_t * _Top_api;
double sc_time_stamp () { return _Top_api->get_time_stamp(); }

// Override Verilator definition so first $finish ends simulation
// Note: VL_USER_FINISH needs to be defined when compiling Verilator code
void vl_finish(const char* filename, int linenum, const char* hier) {
  Verilated::flushCall();
  exit(0);
}

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vtop_SoC* top = new Vtop_SoC;
    std::string vcdfile = "test_run_dir/SoC.top_SoCTest1134956276/top_SoC.vcd";
    std::vector<std::string> args(argv+1, argv+argc);
    std::vector<std::string>::const_iterator it;
    for (it = args.begin() ; it != args.end() ; it++) {
        if (it->find("+waveform=") == 0) vcdfile = it->c_str()+10;
    }
#if VM_TRACE
    Verilated::traceEverOn(true);
    VL_PRINTF("Enabling waves..");
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open(vcdfile.c_str());
#endif
    top_SoC_api_t api(top);
    _Top_api = &api; /* required for sc_time_stamp() */
    api.init_sim_data();
    api.init_channels();
#if VM_TRACE
    api.init_dump(tfp);
#endif
    while(!api.exit()) api.tick();
#if VM_TRACE
    if (tfp) tfp->close();
    delete tfp;
#endif
    delete top;
    exit(0);
}
