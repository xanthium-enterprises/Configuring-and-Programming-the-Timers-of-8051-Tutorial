// (c) 2026 www.xanthium.in

// Timer 0 is Configured to Generate an Timer 0 Interrupt
// Timer 0 overflows after 71.1ms 
// P3.0 is blinked inside the isr

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
	
	TMOD = 0x01;       // -------------Timer0, Mode 1(16-bit)
	                   // C/T = 0, So Timer Mode 
	
	                   // TMOD Register
	                   // [G C/T M1 M0] [G C/T M1 M0]
	                   // [0 0   0  0 ] [0 0   0  1 ]
	 
   IE = 0x82;        // IE Register
										 // [EA - ET2 ES] [ET1 EX1 ET0 EX0 ]
	                   // [1  0  0   0] [ 0   0   1   0  ]
	                   //  EA enabled 
	                   //  ET0 Timer Interrupt enabled
	
	 //Generate 71.1ms ms Delay 
	 TH0 = 0x00;        // Load high byte
	 TL0 = 0x00;        // Load low byte 
   TR0 = 1;           // Start Timer0
	
	 while(1); //Wait here indefenitely 
	 
	 
}//end of main()

//Keil Interrupt routine 
void timer0_ISR(void) interrupt 1
{
	P3 ^= 0x01; //Toggle P3.0 Bit  using XOR operative
}
