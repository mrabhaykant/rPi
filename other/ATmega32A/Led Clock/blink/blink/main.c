/*
* blink.c
*
* Created: 12/11/2020 9:55:55 PM
* Author : abhay
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "functions.h"
char flag1=0;
ISR(TIMER0_OVF_vect){
	flag1++;
	if (flag1 == 10)
	{
		PORTB ^= (1 << 3);
		flag1 = 0;
	}
	
	//TCNT0 = 0xb2;
	//flag1++;
}

ISR(TIMER1_OVF_vect)
{
	//PORTA ^=  (1 << PORTA1);
	maincounter++;
	PORTA ^= (1 << 0);
	
	TCNT1 = 0xc2f7;	// 1 sec
	//TCNT1 = 0xe17c;	// 0.5 s
	//TCNT1 = 0xf0be;		// 250 ms 
	//	TCNT1 = 0xfcf2;
 //TCNT1L = 0x7c;	
// second1++;
// if (second1 == 13)
// {.
// 	second1 = 1;
// }
clockUpdate();
}
int t0cnt=0;
ISR(TIMER0_COMP_vect){
	t0cnt++;
	if((t0cnt >= 50)/*&&(t0cnt <= 200)*/){
	PORTA ^= (1 << PORTA2);
	
	}
	if(t0cnt == 1000){
		OCR0 = 16;
		PORTA ^= (1 << PORTA2);
		//t0cnt = 0;
	}
	if(t0cnt >= 2000){
		OCR0 = 151;
		PORTA ^= (1 << PORTA2);
		//t0cnt = 0;
	}
}

	//TCNT1H = timer1H;
	//TCNT1L = timer1L;

	int ymt = 0;
void clockUpdate(){
	second1++;
	minute++;
	//if (maincounter == 60)
	//{
		//second1 = 1;
		//minute++;
//
	//}
	 if (minute > 60)
	 {
		 minute = 0;
		 hour++;
	 }
	 if (hour > 12)
	 {
		 hour = 0;
	 }
	 if (second1 >= 13)
	 {
		 second1 = 1;
	 }
	 if((minute >= 15))
	 {
		 qtrSec++;
		 if (qtrSec > 16)
		 {
			 PORTC |= (1 << PORTC6);
			 qtrSec = 13;
			 _delay_ms(10);
			 PORTC &= ~(1 << PORTC6);
		 }
		 minute = 0;
		 
	 }
		 
	 
	 
}
	


int main(void)
{

TIMSK=(1<<TOIE0)|(1<<TOIE1)|(1 << OCIE0);
TCCR0 = (1<<WGM01)|(0 << COM00)|(1 << CS02)|(0 << CS01)|(1 << CS00);		// Timer 0 control register	prescaler = 256
TCNT0 = 0;
OCR0 = 156;
	/*
	CS10 and CS12 = clock / 1024
	16000000/1024 = 15625 Hz		clock is divided by 1024 prescaler
	1/15625 = 0.000064? Seconds = 64 micro seconds		time of 1 period
	time required for 1000mS 
	1000 * 10^(-3)
	--------------
	64 * 10^(-6)
	= 15625
	TCNT1  = 65536 - 15625 = 49911 (Decimal) = 0xc2f7
	TCNT1H = 0xc2
	TCNT1L = 0xf7
		
	7812.5	e17c	500ms
	50ms	50ms/64us = 781.25		65536 - 781.25 = 64754.75		fcf7
	*/
	TCCR1A = 0x00;
	TCCR1B = (1 << CS12)|(0 << CS11)|(1 << CS10);
	TCNT1 = 0xc2f7;
	
	//TCNT0 = // Lead the timer0 with the number to trigger
	/* Replace with your application code */
	//enum row_seq {first_row = 7,second_row = 4,third_row = 2,bottom_row = 3};
			
	Myinit();
	sei();
	while (1)
	{	
		
		
	
		CubeCharClock(second1);
		CubeCharClock(qtrSec);


		
	}
}


void row(int PinNum, char PinHighLow)
{
	if(PinHighLow == 1){
			PORTD |= (1 << PinNum);
_delay_ms(1);
	}
			
	if(PinHighLow == 0)	{	
			PORTD &= ~(1 << PinNum);
		//	_delay_ms(1);
	}
}
void column(char pinNum, char PinHighLow)
{
	if(PinHighLow == 1){
		PORTA |= (1 << pinNum);
		_delay_ms(1);
		//while((TCNT1 ==  0x0c3f7));
		//_delay_ms(0.2);
	}
	
	if(PinHighLow == 0)	{
		PORTA &= ~(1 << pinNum);
	//	_delay_ms(1);
	}
}
void CubeCharClock(char num){
	char k1 = num;
	if(k1 == 1){
		row(first_row,1);
		column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
		allOff();
		row(second_row,1);
		column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(third_row,1);
		column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(fourth_row,1);
		column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
	}
	if (k1 == 2)
	{
				row(first_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 1);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
		/*
		row(first_row,1);
		column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 1);
		allOff();
		row(second_row,1);
		column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
		allOff();
		row(third_row,1);
		column(first_col, 0);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(fourth_row,1);
		column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 1);
		allOff();
		*/
	}
		if (k1 == 3)
		{
					row(first_row,1);
					column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
					allOff();
					row(second_row,1);
					column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 1);
					allOff();
					row(third_row,1);
					column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
					allOff();
					row(fourth_row,1);
					column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
					allOff();
		}
			if (k1 == 4)
			{
						row(first_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
						allOff();
						row(second_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
						allOff();
						row(third_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 1);
						allOff();
						row(fourth_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
						allOff();
			}	
			if (k1 == 5)
			{
						row(first_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
						allOff();
						row(second_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
						allOff();
						row(third_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
						allOff();
						row(fourth_row,1);
						column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 1);
						allOff();
				/*
				row(first_row,1);
				column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				*/
			}
			if (k1 == 6)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 7)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 8)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 9)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 10)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
		}
		if (k1 == 11)
		{
			row(first_row,1);
			column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
		}
		if (k1 == 12)
		{
			row(first_row,1);
			column(first_col, 0);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			
		}
		if (k1 == 13)
		{
			row(first_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
		}
		if (k1 == 14)
		{
			row(first_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
		}
		if (k1 == 15)
		{
			row(first_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
		}
		if (k1 == 16)
		{
			row(first_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
			allOff();
		}
}


//void video_frame(){
	///*
	//____|--|-------------------------------------|--|
	//4	
	//*/
//}
void allOff(){
	column(first_col, 0);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
	row(first_row,0);row(second_row,0);row(third_row,0);row(fourth_row,0);
}