module HalfAdder (
    input A,
    input B,
    output S,
    output C
);

assign C = A & B;
assign S = A ^ B;
    
endmodule