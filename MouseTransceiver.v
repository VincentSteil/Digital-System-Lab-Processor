//`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:42:10 17/02/2014 
// Design Name: 
// Module Name:    MouseTransceiver 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 	Large ammounts of code were already provided, however
//									that also greatly restricts my coding options
//
//////////////////////////////////////////////////////////////////////////////////
/*
Seven Segement Display values: MouseX, MouseY
*/

module MouseTransceiver(
	//Standard Inputs
	input 				RESET,
	input 				CLK,
	//IO - Mouse side
	inout 				CLK_MOUSE,
	inout 				DATA_MOUSE,
	// Mouse data information
	output reg [3:0] 	MouseStatus,		// needed to add reg status to do non-blocking assign
	output reg [7:0] 	MouseX,
	output reg [7:0] 	MouseY,
	output 				SendInterrupt
	/*
	output wire			AN0, AN1, AN2, AN3,
	output wire			CA, CB, CC, CD, CE, CF, CG, CDP
	*/
);


	// X, Y Limits of Mouse Position e.g. VGA Screen with 160 x 120 resolution
	parameter [7:0] MouseLimitX = 160;
	parameter [7:0] MouseLimitY = 120;
	
	/////////////////////////////////////////////////////////////////////
	//TriState Signals
	//Clk
	reg 	ClkMouseIn;
	wire 	ClkMouseOutEnTrans;
	
	//Data
	wire 	DataMouseIn;
	wire 	DataMouseOutTrans;
	wire 	DataMouseOutEnTrans;
	
	//Clk Output - can be driven by host or device
	assign CLK_MOUSE = ClkMouseOutEnTrans ? 1'b0 : 1'bz;
	
	//Clk Input
	assign DataMouseIn = DATA_MOUSE;
	
	//Clk Output - can be driven by host or device
	assign DATA_MOUSE = DataMouseOutEnTrans ? DataMouseOutTrans : 1'bz;

	/////////////////////////////////////////////////////////////////////
	//This section filters the incoming Mouse clock to make sure that
	//it is stable before data is latched by either transmitter
	//or receiver modules
	reg [7:0] MouseClkFilter;
	
	always@(posedge CLK) begin
		if(RESET)
			ClkMouseIn <= 1'b0;
		else 
			begin
				//A simple shift register
				MouseClkFilter[7:1] <= MouseClkFilter[6:0];
				MouseClkFilter[0] <= CLK_MOUSE;
				
				//falling edge
				if(ClkMouseIn & (MouseClkFilter == 8'h00))			
					ClkMouseIn <= 1'b0;
				
				//rising edge
				else if(~ClkMouseIn & (MouseClkFilter == 8'hFF))
					ClkMouseIn <= 1'b1;
			end
	end
	///////////////////////////////////////////////////////
	//Instantiate the Transmitter module
	wire 			SendByteToMouse;
	wire 			ByteSentToMouse;
	wire [7:0] 	ByteToSendToMouse;
	MouseTransmitter T(
					//Standard Inputs
					.RESET (RESET),
					.CLK(CLK),
					//Mouse IO - CLK
					.CLK_MOUSE_IN(ClkMouseIn),
					.CLK_MOUSE_OUT_EN(ClkMouseOutEnTrans),
					//Mouse IO - DATA
					.DATA_MOUSE_IN(DataMouseIn),
					.DATA_MOUSE_OUT(DataMouseOutTrans),
					.DATA_MOUSE_OUT_EN (DataMouseOutEnTrans),
					//Control
					.SEND_BYTE(SendByteToMouse),
					.BYTE_TO_SEND(ByteToSendToMouse),
					.BYTE_SENT(ByteSentToMouse)
	);
	
	
	///////////////////////////////////////////////////////
	//Instantiate the Receiver module
	wire 					ReadEnable;
	wire [7:0] 			ByteRead;
	wire [1:0] 			ByteErrorCode;
	wire 					ByteReady;
	MouseReceiver R(
							//Standard Inputs
							.RESET(RESET),
							.CLK(CLK),
							//Mouse IO - CLK
							.CLK_MOUSE_IN(ClkMouseIn),
							//Mouse IO - DATA
							.DATA_MOUSE_IN(DataMouseIn),
							//Control
							.READ_ENABLE (ReadEnable),
							.BYTE_READ(ByteRead),
							.BYTE_ERROR_CODE(ByteErrorCode),
							.BYTE_READY(ByteReady)
	);

	///////////////////////////////////////////////////////
	//Instantiate the Master State Machine module
	wire [7:0] 				MouseStatusRaw;
	wire [7:0] 				MouseDxRaw;
	wire [7:0] 				MouseDyRaw;
	MouseMasterSM MSM(
								//Standard Inputs
								.RESET(RESET),
								.CLK(CLK),
								//Transmitter Interface
								.SEND_BYTE(SendByteToMouse),
								.BYTE_TO_SEND(ByteToSendToMouse),
								.BYTE_SENT(ByteSentToMouse),
								//Receiver Interface
								.READ_ENABLE (ReadEnable),
								.BYTE_READ(ByteRead),
								.BYTE_ERROR_CODE(ByteErrorCode),
								.BYTE_READY(ByteReady),
								//Data Registers
								.MOUSE_STATUS(MouseStatusRaw),
								.MOUSE_DX(MouseDxRaw),
								.MOUSE_DY(MouseDyRaw),
								.SEND_INTERRUPT(SendInterrupt)
	);
	/*
	SevenSegmentDisplay SevenSeg(
								.CLK(CLK),
								// Anode values
								.AN0(AN0),
								.AN1(AN1),
								.AN2(AN2),
								.AN3(AN3),
								// Cathode Values
								.CA(CA),
								.CB(CB),
								.CC(CC),
								.CD(CD),
								.CE(CE),
								.CF(CF),
								.CG(CG),
								.CDP(CDP),
								// Actual display values
								.DIGIT1(MouseX[7:4]),		
								.DIGIT2(MouseX[3:0]),		
								.DIGIT3(MouseY[7:4]),		
								.DIGIT4(MouseY[3:0])			
	);
	*/

	//Pre-processing - handling of overflow and signs.
	//More importantly, this keeps tabs on the actual X/Y
	//location of the mouse.
	wire signed [8:0] MouseDx;
	wire signed [8:0] MouseDy;
	wire signed [8:0] MouseNewX;
	wire signed [8:0] MouseNewY;
	
	//DX and DY are modified to take account of overflow and direction
	assign MouseDx = (MouseStatusRaw[6]) ? (MouseStatusRaw[4] ? {MouseStatusRaw[4],8'h00} : {MouseStatusRaw[4],8'hFF} ) : {MouseStatusRaw[4],MouseDxRaw[7:0]};
	/*
	………………..
	FILL IN THIS AREA
	……………….
	
	*/
	// assign the proper expression to MouseDy
	assign MouseDy = (MouseStatusRaw[7]) ? (MouseStatusRaw[5] ? {MouseStatusRaw[5],8'h00} : {MouseStatusRaw[5],8'hFF} ) : {MouseStatusRaw[5],MouseDyRaw[7:0]};
	/* Below is pseudocode describing this assign statement
		
		if MouseStatusRaw[7]{													// movement overflow
			if MouseStatusRaw[5]{												// negative movement (sign bit)
				MouseDy = concat(MouseStatusRaw[5],8'h00)					//	if overflow dy && neg dy -> set PosY = 0x100 = -256
			}
			else{
				MouseDy = concat(MouseStatusRaw[5],8'hFF)					// if overflow dy && pos dy -> set PosY = 0x0FF = 255
			}
		}
		else{
				MouseDy = concat(MouseStatusRaw[5],MouseDyRaw[7:0])	// if not overflow, accept incoming dy value in 2's comp (hence appended sign bit)
		}
	
	*/
	// calculate new mouse position
	assign MouseNewX = {1'b0,MouseX} + MouseDx;
	assign MouseNewY = {1'b0,MouseY} + MouseDy;

	always@(posedge CLK)
		begin
			if(RESET) 
				begin
					MouseStatus 	<= 0;
					MouseX 			<= MouseLimitX/2;
					MouseY 			<= MouseLimitY/2;
				end 
			else if (SendInterrupt) 
				begin
				
					//Status is stripped of all unnecessary info
					MouseStatus 	<= MouseStatusRaw[3:0];
				
					//X is modified based on DX with limits on max and min
					if(MouseNewX < 0)
						MouseX 		<= 0;
					else if(MouseNewX > (MouseLimitX-1))
						MouseX 		<= MouseLimitX-1;
					else
						MouseX 		<= MouseNewX[7:0];
					/*
					………………..
					FILL IN THIS AREA
					……………….
					*/
					//Y is modified based on DY with limits on max and min
					if(MouseNewY < 0)
						MouseY 		<= 0;
					else if(MouseNewY > (MouseLimitY-1))
						MouseY 		<= MouseLimitY-1;
					else
						MouseY 		<= MouseNewY[7:0];
						
				
				end
		end


endmodule

