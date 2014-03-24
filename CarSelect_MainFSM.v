`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Organization:       The University of Edinburgh
// Student:            Mihail Mitev s1032574
//  
//
//////////////////////////////////////////////////////////////////////////////////
module CarSelect_MainFSM(
    input CLK,
    input RST,

    input [7:0] BUS_DATA,
	 input [7:0] BUS_ADDR,
    output reg IR_LED/*,
//Simulation Only Outputs    
    output r_Sequence_Indicate_LED, //connected to LED above car switch, 
    output g_Sequence_Indicate_LED, //used as an indication for which car
    output b_Sequence_Indicate_LED, //is currently controlled
    output y_Sequence_Indicate_LED
    output r_Packet_Sequence_Done,
    output g_Packet_Sequence_Done,
    output [3:0] r_i_2,
    output [3:0] g_i_2,
    output r_Pulse_Strobe_2,
    output g_Pulse_Strobe_2,
    output Packet_Send_Strobe_2 */
    );
parameter RED = 4'b1000, GREEN = 4'b0100, BLUE = 4'b0010, YELLOW = 4'b0001; //Selected Car State Definitions
reg IDLE=0; // register to indicate whether any car has been selected or not- acts as an enable switch for 10Hz Counter

wire Packet_Send_Strobe; //output of 10Hz counter

reg r_pack_gen_EN;       //Enable switch(input) for PulseGen for car 
reg r_pack_strobe;       //Strobe to initiate the sending of a packet
wire r_IR_LED;           //Pulse for IR LED, output from IR_Transmitter_SM module

reg g_pack_gen_EN;
reg g_pack_strobe;
wire g_IR_LED;

reg b_pack_gen_EN;
reg b_pack_strobe;
wire b_IR_LED;

reg y_pack_gen_EN;
reg y_pack_strobe;
wire y_IR_LED;


//10Hz counter
Counter  	# 		(.Counter_Width(23),
						.Counter_Max(5000000)
						)
						Packet_Counter
					  (.CLK(CLK),
						.Reset(RST),
						.ENABLE_IN(!IDLE),
						.COUNT(),
						.TRIG_OUT(Packet_Send_Strobe)
					);
//end of 10Hz Counter

//registers for controlling car behaviour
reg [3:0]COMMAND; //direction command
reg [3:0]Car_Sel; //selected car

//read command and car_sel from memory location dictated by the processor
parameter BaseAddr 	= 8'h90;
wire CS;
assign CS 	= (BUS_ADDR == BaseAddr) ? 1'b1 : 1'b0; // single byte -> ADDR MUST match
   
always@(posedge CLK)
   begin							
      if (CS)
         begin
            Car_Sel = BUS_DATA[3:0];
            COMMAND = BUS_DATA[7:4];
         end
      else
         begin
            Car_Sel = Car_Sel;
            COMMAND = 4'h0;
         end
end
//end of read

//Selected Car State Machine
//connects 10Hz counter to a specific car module according to which switch is ON(Car Select)
//connects IR LED to output of selected car's IR_Transmitter_SM module output
//disables all IR_Transmitter_SM modules besides the one for the selected car
always@(posedge CLK) begin
   case(Car_Sel)
      RED:   begin   r_pack_strobe<=  Packet_Send_Strobe; r_pack_gen_EN<= 1; IR_LED= r_IR_LED;
                     g_pack_strobe<= 0; g_pack_gen_EN<= 0;
                     b_pack_strobe<= 0; b_pack_gen_EN<= 0;
                     y_pack_strobe<= 0; y_pack_gen_EN<= 0;
                     IDLE<=0; end    
      GREEN: begin   g_pack_strobe<=  Packet_Send_Strobe; g_pack_gen_EN<= 1; IR_LED= g_IR_LED;
                     r_pack_strobe<= 0; r_pack_gen_EN<= 0;
                     b_pack_strobe<= 0; b_pack_gen_EN<= 0;
                     y_pack_strobe<= 0; y_pack_gen_EN<= 0;
                     IDLE<=0; end   
      BLUE:  begin   b_pack_strobe<=  Packet_Send_Strobe; b_pack_gen_EN<= 1; IR_LED= b_IR_LED;
                     r_pack_strobe<= 0; r_pack_gen_EN<= 0;
                     g_pack_strobe<= 0; g_pack_gen_EN<= 0;
                     y_pack_strobe<= 0; y_pack_gen_EN<= 0; 
                     IDLE<=0; end    
      YELLOW:begin   y_pack_strobe<=  Packet_Send_Strobe; y_pack_gen_EN<= 1; IR_LED= y_IR_LED;
                     r_pack_strobe<= 0; r_pack_gen_EN<= 0;
                     g_pack_strobe<= 0; g_pack_gen_EN<= 0;
                     b_pack_strobe<= 0; b_pack_gen_EN<= 0;
                     IDLE<=0; end  
      default: begin IDLE <= 1; r_pack_strobe<= 0; r_pack_gen_EN<= 0; IR_LED = 0;
                                g_pack_strobe<= 0; g_pack_gen_EN<= 0;
                                b_pack_strobe<= 0; b_pack_gen_EN<= 0;
                                y_pack_strobe<= 0; y_pack_gen_EN<= 0;
                                end 
   endcase   
end


//instantiation of all the IR_Transmitter modules for each car

IR_Transmitter_SM # (.Counter_Width(10),     //36kHz
                     .Counter_Max(694),
                     .Pulse_Counter_Width(8),
                     .StartBurstSize(192),
                     .CarSelectBurstSize(24),
                     .Gap(24),
                     .AssertBurstSize(48),
                     .DeAssertBurstSize(24)
                     )
                     RED_CAR
                    (.CLK(CLK), 
                     .RST(RST), 
                     .COMMAND(COMMAND), 
                     .pack_strobe(r_pack_strobe), 
                     .pack_gen_EN(r_pack_gen_EN), 
                     .IR_LED(r_IR_LED)
                     );
                     
IR_Transmitter_SM # (.Counter_Width(10),     //37.5kHz
                     .Counter_Max(667),
                     .Pulse_Counter_Width(8),
                     .StartBurstSize(88),
                     .CarSelectBurstSize(44),
                     .Gap(40),
                     .AssertBurstSize(44),
                     .DeAssertBurstSize(22)
                     )
                     GREEN_CAR
                    (.CLK(CLK), 
                     .RST(RST), 
                     .COMMAND(COMMAND), 
                     .pack_strobe(g_pack_strobe), 
                     .pack_gen_EN(g_pack_gen_EN), 
                     .IR_LED(g_IR_LED)
                     );
IR_Transmitter_SM # (.Counter_Width(10),     //36kHz
                     .Counter_Max(694),
                     .Pulse_Counter_Width(8),
                     .StartBurstSize(191),
                     .CarSelectBurstSize(47),
                     .Gap(25),
                     .AssertBurstSize(47),
                     .DeAssertBurstSize(22)
                     )
                     BLUE_CAR
                    (.CLK(CLK), 
                     .RST(RST), 
                     .COMMAND(COMMAND), 
                     .pack_strobe(b_pack_strobe), 
                     .pack_gen_EN(b_pack_gen_EN), 
                     .IR_LED(b_IR_LED)
                     );     

IR_Transmitter_SM # (.Counter_Width(10),     //40kHz
                     .Counter_Max(625),
                     .Pulse_Counter_Width(8),
                     .StartBurstSize(88),
                     .CarSelectBurstSize(22),
                     .Gap(40),
                     .AssertBurstSize(44),
                     .DeAssertBurstSize(22)
                     )
                     YELLOW_CAR
                    (.CLK(CLK), 
                     .RST(RST), 
                     .COMMAND(COMMAND), 
                     .pack_strobe(y_pack_strobe), 
                     .pack_gen_EN(y_pack_gen_EN), 
                     .IR_LED(y_IR_LED)
                     );                      
                     
                     
endmodule
