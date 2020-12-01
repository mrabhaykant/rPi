A program is a set of code.
These set of code are converted to machine language instructions.
These machine language instructions are then executed by the hardware.
Target: A physical hardware which operates these instructions. Example: raspberry pi, ATmega32, Attiny2313 etc.
A target can execute these instructions in a sequential order. No out of order execution is possible at silicon level.
When the target is Powered ON. It starts reading from the first memory location. 
Most of the time the first memory location instruction will tell the processor to, start reading from the the secodary storage(flash memory, hard disk, sd card, pen drive etc).
It reads the instrucation and loads them into the memory. and then executes the instructions one by one. 
To make it continous we add a jump instruction at the end of our program instructions.
