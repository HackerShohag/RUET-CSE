module Adder4bit (
    input [3:0] A,
    input [3:0] B,
    input Cin,
    output [3:0] S,
    output Cout
);

wire [3:0] C;

Adder1bit U0(.A(A[0]), .B(B[0]), .Cin(Cin), .S(S[0]), .Cout(C[0]));
Adder1bit U1(.A(A[1]), .B(B[1]), .Cin(C[0]), .S(S[1]), .Cout(C[1]));
Adder1bit U2(.A(A[2]), .B(B[2]), .Cin(C[1]), .S(S[2]), .Cout(C[2]));
Adder1bit U3(.A(A[3]), .B(B[3]), .Cin(C[2]), .S(S[3]), .Cout(Cout));

endmodule