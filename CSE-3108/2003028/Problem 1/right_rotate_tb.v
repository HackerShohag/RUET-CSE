// HDL module to test the right_rotate module

module Tests_right_rotate;

    reg A;
    reg B;
    reg C;
    reg D;
    wire [3:0] S;

    right_rotate UUT (
        .data_in({A, B, C, D}),
        .rotate_en(1'b1),
        .data_out(S)
    );

    initial begin
        A = 0;
        B = 0;
        C = 0;
        D = 0;
        #20
        A = 0;
        B = 0;
        C = 0;
        D = 1;
        #20
        A = 0;
        B = 0;
        C = 1;
        D = 0;
        #20
        A = 0;
        B = 0;
        C = 1;
        D = 1;
        #20
        A = 0;
        B = 1;
        C = 0;
        D = 0;
        #20
        A = 0;
        B = 1;
        C = 0;
        D = 1;
        #20
        A = 0;
        B = 1;
        C = 1;
        D = 0;
        #20
        A = 0;
        B = 1;
        C = 1;
        D = 1;
        #20
        A = 1;
        B = 0;
        C = 0;
        D = 0;
        #20
        A = 1;
        B = 0;
        C = 0;
        D = 1;
        #20
        A = 1;
        B = 0;
        C = 1;
        D = 0;
        #20
        A = 1;
        B = 0;
        C = 1;
        D = 1;
        #20
        A = 1;
        B = 1;
        C = 0;
        D = 0;
        #20
        A = 1;
        B = 1;
        C = 0;
        D = 1;
        #20
        A = 1;
        B = 1;
        C = 1;
        D = 0;
        #20
        A = 1;
        B = 1;
        C = 1;
        D = 1;
    end

    initial begin
        $monitor("A=%b,B=%b,C=%b,D=%b,S=%b\n", A, B, C, D, S);
    end

endmodule
