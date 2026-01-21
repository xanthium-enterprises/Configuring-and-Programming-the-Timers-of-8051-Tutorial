

// (c) 2026 www.xanthium.in

// Timer 0 Programming Tutorial 

// Timer 0 is Configured to Generate time delay of 71.1 ms once

// External Crytal Clock = 11.0592 Mhz

// Internal Timer Clock  = External Crytal Clock/12 -> 11.0592 Mhz/12
// Internal Timer Clock  =  0.9216 Mhz

// Ticks (Time Period )  = 1/(0.9216 Mhz)
//                       = 1.085uS (micro seconds)

// 16 bit Timer Counter increments every 1.085uS (micro seconds)

//Compiler used is Kiel uVision 5 

#include <reg51.h>   //Header file used by Kiel uVision
void main(void)
{
	
	TMOD = 0x01;       // Timer0, Mode 1(16-bit)
	                   // C/T = 0, So Timer Mode 
	
	                   // TMOD Register
	                   // [G C/T M1 M0] [G C/T M1 M0]
	                   // [0 0   0  0 ] [0 0   0  1 ]
  
  // Delay = 71.1 mS (milli seconds) 
	
	// Load 0x0000 into the 16 bit Register 
	// Timer Counts from 0x0000 -> 0xFFFF or from 0 -> 65,535 ,
	
	// total steps = 65,536 
	// Time Delay = 1.085uS X 65,536 = 71,172 uS (Micro Seconds)
	// or 71.1 mS (milli seconds) 
	
	TH0 = 0x00;        // Load high byte
  TL0 = 0x00;        // Load low byte 
  
	TR0 = 1;           // Start Timer0
	
	while(TF0 == 0); //if   TF0 = 0 stay here
	                 //when TF0 = 1 Exit while loop
	
	TF0 = 0;      // Manually Clear the Timer overflow Flag
	TR0 = 0;      // Stop the Timer 
	
	while(1); //Stop here.
}