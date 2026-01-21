// (c) 2026 www.xanthium.in

// Timer0 used to Generate 1 second delay using interrupts
// Timer0 is Configured to Generate an Timer 0 Interrupt
// Timer0 overflows after 50ms 
// P3.0 is blinked inside the isr every 1 second

// External Crytal Clock = 11.0592 Mhz
// Internal Timer Clock  = External Crytal Clock/12 -> 11.0592 Mhz/12
// Internal Timer Clock  =  0.9216 Mhz
// Ticks (Time Period )  = 1/(0.9216 Mhz)
//                       = 1.085uS (micro seconds)

// 16 bit Timer Counter increments every 1.085uS (micro seconds)

// Compiler used is Kiel uVision 5

unsigned char count = 0; //global variable for keeping track of number of interrupts

#include <reg51.h>   //Header file used by Kiel uVision
void main(void)
{
  P3 = 0x00; // Port 3 all bits off
    
  TMOD = 0x01; // -------------Timer0, Mode 1(16-bit)
               // C/T = 0, So Timer Mode 
    
               // TMOD Register
               // [G C/T M1 M0] [G C/T M1 M0]
               // [0 0   0  0 ] [0 0   0  1 ]
     
  IE = 0x82;   // IE Register
               // [EA - ET2 ES] [ET1 EX1 ET0 EX0 ]
               // [1  0  0   0] [ 0   0   1   0  ]
               //  EA enabled 
               //  ET0 Timer Interrupt enabled
    
  //Generate 50ms  Delay 
  TH0 = 0x4B;   // Load high byte
  TL0 = 0xFD;   // Load low byte 
  
  TR0 = 1;      // Start Timer0
    
  while(1); //Wait here indefenitely 
     
     
}//end of main()

//Keil Interrupt routine for Timer 0
void timer0_ISR(void) interrupt 1
{
  //Generate 50ms  Delay 
  TH0 = 0x4B;   // Load high byte
  TL0 = 0xFD;   // Load low byte 
  
	count++; //Increment counter
	
	if(count >=20)// 20 × 50 ms = 1 second
	{
		count = 0;  // Reset  counter
		P3 ^= 0x01;
		
	}
}