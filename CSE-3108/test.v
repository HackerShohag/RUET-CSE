
module Tests (
    input A,
    input B,
    output S,
    output C
);

HalfAdder UUT (
    .A(A),
    .B(B),
    .S(S),
    .C(C)
);

initial begin
    A = 0;
    B = 0;
    #20
    A = 0;
    B = 1;
    #20
    A = 1;
    B = 0;
    #20
    A = 1;
    B = 1;
end

initial begin
    $monitor("A=%b,B=%b,S=%b,C=%b\n", A, B, S, C);
end

endmodule