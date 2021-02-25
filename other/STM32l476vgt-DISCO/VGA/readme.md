This document contains codes for generating simple VGA signal.\
VGA mode : 1024 x 768 at 60Hz



Hardware setup

|BOARD : Stm32l476vg-DISCO                |VGA||
| --- | --- | --- |
|GND               |      |     Pin 5|
|PB2 (LED Red)     |Hsync|      Pin 13|
|PE8 (LED Green)   |      |     Pin |
|PB5(LCD_SEG_12)   |Vsync|      Pin 14|
|PB15(LCD_SEG_4)   |Video|      Pin 1|


Timer 3 \
Formula = (1/APB1_Clock)x(PSC+1)x(ARR+1)\
Prescaler = 0\
ARR = 1653\
channel 1\
Pulse = 166\
Channel 2\
Pulse = 55\
