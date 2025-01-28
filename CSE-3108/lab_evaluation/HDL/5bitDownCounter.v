module DownCounter (
    input wire clk,
    input wire reset,
    output wire [4:0] output_count
);
    
    reg [4:0] count;

    always @(posedge clk or posedge reset) begin
        if (reset)
            count <= 5'b11111;
        else
            count <= count - 1;
    end

    assign output_count = count;

endmodule