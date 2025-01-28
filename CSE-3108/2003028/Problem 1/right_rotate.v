// HDL program to perfrom the right rotate operation on a 4 bit operand

module right_rotate (
    input [3:0] data_in,
    input rotate_en,
    output reg [3:0] data_out
);
    always @(*) begin
        if (rotate_en)
            data_out = {data_in[0], data_in[3:1]};
        else
            data_out = data_in;
    end
endmodule