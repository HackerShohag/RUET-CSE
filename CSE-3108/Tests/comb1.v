module comb1 (
    input D,
    input X,
    input A,
    output L
);

    assign L = (~D) & (~X) & A | (~D) & X & A + D & (~X) & (~A) + D & X & A;
endmodule
