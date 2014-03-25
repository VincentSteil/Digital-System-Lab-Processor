`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Organization:       The University of Edinburgh
// Student:            Mihail Mitev s1032574
//  
//
//////////////////////////////////////////////////////////////////////////////////
module IR_Transmitter_SM(
    input CLK,
    input RST,
    input [3:0] COMMAND,
    input pack_strobe,
    input pack_gen_EN,
    output IR_LED/*,         
    output Sequence_Show   //USED ONLY WHEN IR MODULE IS ON ITS OWN
    output Packet_Sequence_Done, 
    output [3:0]i_2, //ONLY FOR SIM REMOVE AFTER SIM
    output Pulse_Strobe_2
    output Pulse_Sim, //ONLY FOR SIM REMOVE AFTER SIM
    output [9:0]j_2,//ONLY FOR SIM REMOVE AFTER SIM
    output Packet_Finished_Flag_2,//ONLY FOR SIM REMOVE AFTER SIM
    output [3:0] command_reg_next_state_2,//ONLY FOR SIM REMOVE AFTER SIM
    output [3:0] command_reg_state_2 //ONLY FOR SIM REMOVE AFTER SIM */
    );
    
//Pulse Generator parameters
parameter Counter_Width=10;
parameter Counter_Max=694; 


//Packet Generator parameters
parameter Pulse_Counter_Width = 8;
parameter StartBurstSize = 192;
parameter CarSelectBurstSize = 24;
parameter Gap = 24;
parameter AssertBurstSize = 48;
parameter DeAssertBurstSize = 24;


					
//defining Direction States
parameter IDLE = 4'b0000, Forwards = 4'b1000, Backwards = 4'b0100, Left = 4'b0010, Right = 4'b0001, ForwardLeft = 4'b1010, ForwardRight = 4'b1001, BackwardLeft = 4'b0110, BackwardRight = 4'b0101;					

reg [3:0] command_reg_state = 4'b000;       //register which stores the direction-buttons input as a state while a packet sequence is being transmitted for a particular direction input 
reg [3:0] command_reg_next_state = 4'b000;  //register which stores the direction-buttons input while a packet sequence is being transmitted for a previous(current) direction input
reg [3:0] i;                       //variable to count number of transmitted packets - max 10
reg Packet_Sequence_Finished_Flag; //0 - Packet Sequence still in progress; 1 - Packet Sequence Finished;Used as a control signal for the Command Input State Machine

//Packet Counter
always@(posedge CLK or posedge RST)begin
	if(RST)begin
		i = 4'd0;
      Packet_Sequence_Finished_Flag = 0;
   end   
	else if(i<10)begin   //increment i only at packet strobe
      if( (i < 9) && pack_strobe)begin
         i = i+1;
      end   
      else if( (i == 9) && pack_strobe)begin
         Packet_Sequence_Finished_Flag = 1;
         i = i+1;
      end
      else begin
         i = i;   
      end
   end   
	else begin
      Packet_Sequence_Finished_Flag = 0;
		i = 4'd0;
   end   
end
//end of Packet Counter

//Command Input State Machine
//Setup memory for direction state: if direction button is pressed while sending packets for a previous direction,
//the car should start moving in the new direction only after full packet sequence is transmitted for the previous one
always@(posedge CLK)begin
	if(RST)begin
		command_reg_state = IDLE; 
		command_reg_next_state = IDLE; 
	end
   else if(Packet_Sequence_Finished_Flag)begin    //command_reg_state takes a different state only after a complete package sequence
      command_reg_state = command_reg_next_state; //state progression
      command_reg_next_state = IDLE; 
	end
   else begin     //ensure command_reg_state does not change while transmitting a package sequence
      case(COMMAND)
         Forwards: 		 command_reg_next_state = Forwards;
         Backwards: 		 command_reg_next_state = Backwards;
         Left:		   	 command_reg_next_state = Left;
         Right: 			 command_reg_next_state = Right;
         ForwardLeft:    command_reg_next_state = ForwardLeft;
         ForwardRight:   command_reg_next_state = ForwardRight;
         BackwardLeft:   command_reg_next_state = BackwardLeft;
         BackwardRight:  command_reg_next_state = BackwardRight;
         IDLE: if(command_reg_next_state != IDLE)begin command_reg_next_state = IDLE; end//= command_reg_next_state; end
               else begin command_reg_next_state = IDLE; end
         default: command_reg_next_state = IDLE; 
      endcase
   end
	
end

//pulse generating module
wire Pulse; //generated pulse 

PulseGen  	# 		(.Counter_Width(Counter_Width),
						 .Counter_Max(Counter_Max)
						)
						PulseGenerator
					  (.CLK(CLK),
						.RST(RST),
                  .pack_strobe(pack_strobe),
						.pack_gen_EN(pack_gen_EN),
                  .Pulse(Pulse),                //Generated Pulse - Output  
                  .Pulse_Strobe(Pulse_Strobe)   //Strobe which marks the beginning of each pulse period - Output
					);

//end of pulse gen module

//packet generating module
Packet_Gen #        (.Pulse_Counter_Width(Pulse_Counter_Width),   
                     .StartBurstSize(StartBurstSize),
                     .CarSelectBurstSize(CarSelectBurstSize),
                     .GapBurstSize(Gap),
                     .AssertBurstSize(AssertBurstSize),
                     .DeAssertBurstSize(DeAssertBurstSize)
                     )
                     Pack_Gen
                    (.CLK(CLK),
                     .Pulse(Pulse),
                     .Pulse_Strobe(Pulse_Strobe),
                     .RST(RST),
                     .pack_strobe(pack_strobe),
                     .current_dir_state(command_reg_state),
                     .IR_LED(IR_LED)
                     );
//end of packet generating module

//USED ONLY WHEN IR MODULE IS ON ITS OWN                     
//assign Sequence_Show = !i[0]; //used as an indication on which car is being controlled. Connected to the LED above switch for each car switch.


//ONLY FOR SIM and Testing
//assign Pulse_Sim = Pulse;
//assign i_2 = i;
//assign Pulse_Strobe_2 = Pulse_Strobe;
//assign j_2 = j;
//assign Packet_Finished_Flag_2 = Packet_Finished_Flag;
//assign command_reg_next_state_2 = command_reg_next_state;
//assign command_reg_state_2 = command_reg_state;
//assign FunctionOutput = Pulse_Con_Flag;
//assign Packet_Sequence_Done = Packet_Sequence_Finished_Flag;


endmodule