// //(c) 2026 www.xanthium.in

// Timer 1 is Configured to Generate time delay of 1Second continously
// and blink the LED connected to P3.1 with delay of 1 second

// External Crytal Clock = 11.0592 Mhz

// Internal Timer Clock  = External Crytal Clock/12 -> 11.0592 Mhz/12
// Internal Timer Clock  =  0.9216 Mhz

// Ticks (Time Period )  = 1/(0.9216 Mhz)
//                       = 1.085uS (micro seconds)

// 16 bit Timer Counter increments every 1.085uS (micro seconds)

// Compiler used is Kiel uVision 5 

#include <reg51.h>   //Header file used by Kiel uVision
void main(void)
{
	P3 = 0x00; // Port 3 all bits off
	
	TMOD = 0x10;       // -------------Timer1, Mode 1(16-bit)
	                   // C/T = 0, So Timer Mode 
	
	                   // TMOD Register
	                   // [G C/T M1 M0] [G C/T M1 M0]
	                   // [0 0   0  1 ] [0 0   0  0 ]
	 
while(1)
	{
		int i = 0;
		for (i = 0;i<20;i++) //Call 50ms delay 20 times = 1 Second 
		{
			//Generate 50 ms Delay 
		  TH1 = 0x4B;        // Load high byte
		  TL1 = 0xFD;        // Load low byte 
  
		  TR1 = 1;           // Start Timer1
	
		  while(TF1 == 0); //if   TF1 = 0 stay here
	                     //when TF1 = 1 Exit while loop
	
	    TF1 = 0;         // Manually Clear the Timer overflow Flag
	    TR1 = 0;         // Stop the Timer 
		}
		
		
		P3 ^= 0x01; //Toggle P3.0 Bit  using XOR operative
		
	}//end of while(1)
	
}//end of main()