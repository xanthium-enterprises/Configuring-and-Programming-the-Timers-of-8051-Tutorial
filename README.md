# Tutorial on Configuring and Programming the Timers of 8051/8052  in embedded C

- This repo contains a complete beginner-to-intermediate tutorial on programming and configuring the Timers of 8051 / 8052 microcontrollers using Embedded C.

The tutorial explains Timer concepts,Timer modes, registers, delay calculations, polling vs interrupts, and provides working source codes (.c) compiled using Keil uVision and SDCC (Small Device C Compiler).

##What You Will Learn

- How 8051 / 8052 timers work internally

- Difference between Timer mode and Counter mode

- Timer operating modes: Mode 0, Mode 1, Mode 2, Mode 3

- How to configure TMOD (Timer Mode Register) of 8051/8052

- How to configure TCON (Timer Control Register) of 8051/8052

- How to configure IE (Interrupt Enable Register) of 8051/8052 for interrupt programming

- How to calculate timer reload values for accurate delays

- How to generate the following delays

	- 71.1 ms delay

	- 50 ms delay

	- 1 second delay

- How to use Timer interrupts instead of polling

- Writing 8051 Timer ISRs in

- Keil uVision

- SDCC


## Target Microcontrollers

- 8051 (AT89S51, AT89S52, P89V51RD2, STC89C52, etc.)

- 8052 variants

- Nuvoton W78E052DDG (used in this tutorial)



## 8051 Hardware Assumptions

- External crystal frequency: 11.0592 MHz

- Timer clock = Crystal / 12 = 0.9216 MHz

- Timer tick = 1.085 µs


## Compilers Supported

- Keil uVision (C51)

- SDCC (Small Device C Compiler)

