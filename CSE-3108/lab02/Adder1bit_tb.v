`timescale 1ns/1ps
module Adder1bit_tb;

    // Inputs
    reg A;
    reg B;
    reg Cin;

    // Outputs
    wire S;
    wire Cout;

    // Instantiate the Unit Under Test (UUT)
    Adder1bit uut (A, B, Cin, S, Cout);

    initial begin

        $dumpfile("Adder1bit_tb_test.vcd");
        $dumpvars(0, Adder1bit_tb);


        // Initialize Inputs
        A = 1'b0;
        B = 1'b0;
        Cin = 1'b0;

        #20
        A = 1'b0;
        B = 1'b0;
        Cin = 1'b1;

        #20
        A = 1'b0;
        B = 1'b1;
        Cin = 1'b0;

        #20
        A = 1'b0;
        B = 1'b1;
        Cin = 1'b1;

        #20
        A = 1'b1;
        B = 1'b0;
        Cin = 1'b0;

        #20
        A = 1'b1;
        B = 1'b0;
        Cin = 1'b1;

        #20
        A = 1'b1;
        B = 1'b1;
        Cin = 1'b0;

        #20
        A = 1'b1;
        B = 1'b1;
        Cin = 1'b1;

        #20
        $finish;
    end

    initial begin
        $monitor("A=%b, B=%b, Cin=%b, S=%b, Cout=%b\n", A, B, Cin, S, Cout);
    end

endmodule