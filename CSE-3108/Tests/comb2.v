module comb2
(
    input [3:0] A,
    input [3:0] B,
    input [3:0] C,
    input [3:0] D,
    output [3:0] Arithmetic,
    output [3:0] Shift,
    output [3:0] Relational,
    output [3:0] Equality,
    output [3:0] Bitwise,
    output [3:0] Reduction,
    output [3:0] Logical,
    output [3:0] Concatenation,
    output [3:0] Conditional
);
    assign Arithmetic = B+C;
    assign Shift = B>>C;
    assign Relational = A > B;
    assign Equality = A == D;
    assign Bitwise = B & C;
    assign Reduction = |B;
    assign Logical = (A > B) || (A > D);
    assign Concatenation = {C[1:0], D[3:2]};
    assign Conditional = (A>B) ? A : B;
endmodule
