`timescale 1ns/1ps

module DownCounter_tb;
    
    reg clk;
    reg reset;
    wire [4:0] count;

    DownCounter dut(clk, reset, count);

    initial begin
        $dumpfile("5bitDownCounter.vcd");
        $dumpvars(0, DownCounter_tb);

        clk = 0;
        reset = 1;
        #10 reset = 0;
    end

    initial begin
        $monitor("count = %b", count);
    end

    always #5 clk = ~clk;

    initial begin
        #100 $finish;
    end

endmodule