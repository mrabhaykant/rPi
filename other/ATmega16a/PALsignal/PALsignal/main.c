/*
 * PALsignal.c
 *
 * Created: 1/26/2021 12:44:25 AM
 * Author : abhay
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "uart.h"
#include "ADC.h"
#include "dispChars.h"

#define NOP asm("nop");
#define ZERO PORTD=0
#define BLACK PORTD=(1<<7) //v out = .3v (black color)
#define WHITE PORTB=(1<<5) //v out = .8v (just white color)
#define color PORTD=(1<<7)|(1<<5)
int8_t SW1;		//Seconds
char SWxs;		//10 seconds
char SWxM;		//min
char SWxxM;		//10 min
char SWxH;		//hour
char SWxxH;		//10 hour
void myName(int num,char chrAlp);
void myName4(int num,char chrAlp);
void myName5(int num,char chrAlp);
void tvchar(int alpha);
void myDelay(int num);
static int16_t i;
static int8_t j,k,o1=0;
static uint16_t m;

// struct d_chr{
// 	int8_t d_chr_pos[20];
// 	};
#include "dispFrames.h"
char rx;
ISR(USART_RXC_vect)
{
// 	if (rxn==BUFFER_SIZE)
// 	{
// 		rxn = 0;
// 	}
// 	rx[rxn++] = UDR;
rx = UDR;	
}

ISR(TIMER2_COMP_vect){

	if(i<3){
		BLACK;myDelay(0xF9);	//0xf8 = 4us
		ZERO;myDelay(0xc8);	//0xf9 = 28us
 		BLACK;myDelay(0xF9);
 		ZERO;myDelay(0xc8);
	}
//	WHITE;
	if(i>=3 && i <=6){
		ZERO;myDelay(0xf9);
		BLACK;myDelay(0xc8);
		ZERO;myDelay(0xf9);
		BLACK;myDelay(0xc8);
	}
	/*
		SW1 Seconds
			SWxs	10 seconds
				SWxM	Min
					SWxxM	10 Min
						SwxH	Hour
							SWxxH	10 Hour
	*/
		if(SW1>9){SW1=0;SWxs++;}	// Clock Second Digit Update if the second digit is > 9 then put zero.
	if (SWxs > 5) {
		SWxs=0;SWxM++;	//whenever 10sec greater than 5 means 60 it goes to zero.
	}
	if (SWxM>9)	{
		SWxM=0;SWxxM++;
	}
	if (SWxxM >5) {
		SWxxM =0;SWxH++;
	}
	if(SWxH >9)	{
		SWxH = 0;SWxxH++;
	}
	if (SWxxH ==2)	{
		if (SWxH >3) {
			SWxxH = 0;SWxH = 0;
		}
	}
	/*
	*	This is a two hour timer.
	*/
if (SWxH > 1)
{
	tvchar(1);
}
else
{
	tvchar(5);
}

			if(i>=309 && i <312)
			{
				//BLACK;_delay_us(4);
				ZERO;myDelay(0xf8);
				BLACK;/*_delay_us(28);*/myDelay(0xF9);
				ZERO;myDelay(0xf8);
				BLACK;myDelay(0xF9);
			}
	if(i==313){
		i=0;
			ZERO;myDelay(0xf8);
			BLACK;/*_delay_us(28);*/myDelay(0xF9);
			ZERO;myDelay(0xf8);
			BLACK;myDelay(0xF9);
	}
	i++;
	if (m == 15625)
	{
		SW1++;
		m=0;
	}
	m++;
}

void myDelay(int num){
	TCNT0 =num;  		/* Load TCNT0*/
	TCCR0 =(1 << CS01);  		/* Timer0, normal mode, 8 pre-scalar */
	
	while((TIFR&0x01)==0);  /* Wait for TOV0 to roll over */
	TCCR0 = 0;
	TIFR = 0x1;  		/* Clear TOV0 flag*/
}

ISR(TIMER1_OVF_vect)
{
	//SW1++;
	//if(SW1>9){SW1=0;SWxs++;}	// Clock Second Digit Update if the second digit is > 9 then put zero.
	
	
	
	TCNT1 = 0xc2f7;	//1s
	//TCNT1 = 0xe17b;	//0.5s
	//TCNT1 = 0xf0be;	//0.25
	//TCNT1 = 0xf0ff;	//0.25
	//TCNT1 = 0xfffa;
	sei();
	
}

int main(void)
{
	USART_Init();
		DDRA &= ~(1 << 0);
		DDRB |= (1<<5)|(1<<7)|(1<<4);	//SPI Init
		SPCR = (1<<SPE)|(1<<MSTR)|(1<<CPHA);
		//SPSR |= (1 << SPI2X);	// Double speed of spi
	DDRD |= (1<<7)|(1<<5)|(1 <<4);
	ADC_Init();
	USART_SendString("ATE0\r\n");
	_delay_us(2000);
	USART_SendString("AT+CIPMUX=0\r\n");
	_delay_us(2000);
	USART_SendString("AT+CIPSTART=\"UDP\",\"192.168.43.72\",6789\r\n");
	_delay_us(2000);
	USART_SendString("AT+CIPSEND=5\r\n");
	_delay_us(1000);
	USART_SendString("ABHAY\r\n");
	
	//TIMSK=(0<<TOIE0)|(1<<TOIE1)|(1 << OCIE0);
	//TCCR0 = (1<<WGM01)|(0 << COM00)|(1 << CS02)|(0 << CS01)|(0 << CS00);		// Timer 0 control register	prescaler = 256
	//TCNT0 = 0;
	//OCR0 = 4;
	TCCR1B = (1<<CS12)|(1<<CS10);
	TCNT1 = 0xc2f7;
	TIMSK |= (1 <<OCIE2)|(1<<TOIE1);
	TCCR0 = (1 << CS01)|(1 << CS00)|(1 << WGM01);
	TCCR2 = (1 << CS22)|(1 << CS21)|(1 << CS20)|(1 << WGM21);
	TCNT2 = 0;
	OCR2 = 0;
	sei();
// 	 unsigned int i;
// 	 int j;
    /* Replace with your application code */
  while(1){

	}
}

#include "frames.h"


void myName(int num,char chrAlp){
	//int8_t temp1;
	switch(chrAlp){
		
	case 'a':
	//BLACK;
	SPDR = arra[i-num];//_delay_us(1);
	//for(int o1=0;o1<3;o1++)PORTD = 0xa0&(arra[i-num]>>o1);
		
		//BLACK;
		//_delay_us(1);
// 		ZERO;
		
	break;
	case 'b':
	SPDR = (arrb[i-num]);//_delay_us(1);
	break;
		case 'e':
		SPDR = (arre[i-num]);
		break;
	case 'f':
	SPDR = (arrf[i-num]);
	break;
	case 'h':
	SPDR = arrh[i-num];
	break;
	case 'i':
	SPDR = arri[i-num];//_delay_us(1);
	break;
	case 'k':
	SPDR = arrk[i-num];//_delay_us(1);
	break;
	case 'm':
	SPDR = arrm[i-num];//_delay_us(1);
	break;
	case 'n':
	SPDR = arrn[i-num];//_delay_us(1);
	break;
	case 'r':
	SPDR = arrr[i-num];//_delay_us(1);
	break;
	case 's':
	SPDR = arrs[i-num];
	break;
	case 't':
	SPDR = arrt[i-num];//_delay_us(1);
	break;
// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arra[i-num]>>o1);
// 	BLACK;
	case 'y':
	SPDR = arry[i-num];//_delay_us(1);
	//for(int o1=0;o1<3;o1++)PORTD = /*0xa0*/(arry[i-num]>>o1);
	//BLACK;
	break;
	
// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arra[i-num]>>o1);
// 	BLACK;
// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arry[i-num]>>o1);
// 	BLACK;
	
	}
}
void myName4(int num,char chrAlp){
	switch(chrAlp){
			case 'd':
			SPDR = (arrdot[i-num]);
			//for( o1=0;o1<1;o1++){PORTD = /*0xa0*/(arr9[i-num]>>o1);BLACK;}
			//BLACK;
			break;
		case '0':
			SPDR = (arr0[i-num]);
			//for( o1=0;o1<3;o1++)SPDR = (arr5[i-num]);
			//PORTD = /*0xa0*/(arr0[i-num]>>o1);
			//BLACK;
			break;
		case '1':
			SPDR = (arr1[i-num]);
			//for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arr1[i-num]>>o1);		// THis one works Decomment 
			//for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(ptr1>>o1);
			//BLACK;
		break;
		case '2':
			SPDR = (arr2[i-num]);
			//for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arr2[i-num]>>o1);
			//BLACK;
		break;
		case '3':
			SPDR = (arr3[i-num]);
			//for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arr3[i-num]>>o1);
			//BLACK;
		break;
		case '4':
			SPDR = (arr4[i-num]);
			//for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr4[i-num]>>o1);
			//BLACK;
		break;

	case '5':
		SPDR = (arr5[i-num]);
		//for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr5[i-num]>>o1);
		//BLACK;
		break;
	case '6':
		SPDR = (arr6[i-num]);
		//for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr6[i-num]>>o1);
		//BLACK;
	break;
	case '7':
		SPDR = (arr7[i-num]);
		//for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr7[i-num]>>o1);
		//BLACK;
	break;
	case '8':
		SPDR = (arr8[i-num]);
		//for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr8[i-num]>>o1);
		//BLACK;
	break;
	case '9':
		SPDR = (arr9[i-num]);
		//for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr9[i-num]>>o1);
		//BLACK;
	break;
	
	case 'n':
	if( (i-num+0) <= 8){	for (o1=0;o1<7;o1++)
	{
		PORTD |= (1 << 4)|(1<<5);
		PORTD |= (1 << 4)|(1<<5);
		PORTD |= (1 << 4)|(1<<5);
		PORTD |= (1 << 4)|(1<<5);
		BLACK;
		PORTD |= (1 << 4);//|(1<<5);
		PORTD |= (1 << 4);
		PORTD |= (1 << 4);
		PORTD |= (1 << 4);
		PORTD |= (1 << 4);
		PORTD |= (1 << 4);
		PORTD |= (1 << 4);
		PORTD |= (1 << 4);
		BLACK;
		PORTD |= (1 << 5);
		PORTD |= (1 << 5);
		PORTD |= (1 << 5);
		PORTD |= (1 << 5);
		BLACK;
	}
 		}
 	if(i-num >=9  && (i-num) <=14){	
		 for (o1=0;o1<7;o1++)
		 {
			 PORTD |= (1 << 5);
			 PORTD |= (1 << 5);
			 PORTD |= (1 << 5);
			 PORTD |= (1 << 5);
			
		 } BLACK;
		 	}
			 if(i-num >=15  && (i-num) <=19){
				 for (o1=0;o1<7;o1++)
				 {
					 PORTD |= (1 << 4);
					 PORTD |= (1 << 4);
					 PORTD |= (1 << 4);
					 PORTD |= (1 << 4);
					 SPDR=0xaa;
				 } BLACK;
			 }
// 	if(i-num+2){	BLACK;WHITE;WHITE;BLACK;	BLACK;BLACK;BLACK;BLACK;	}
// 	if(i-num+3){	BLACK;WHITE;WHITE;BLACK;	BLACK;BLACK;BLACK;BLACK;	}
// 	if(i-num+4){	BLACK;WHITE;myDelay(0xf2);BLACK;	BLACK;BLACK;BLACK;BLACK;	}
// 	if(i-num+5){	BLACK;WHITE;WHITE;BLACK;	BLACK;BLACK;BLACK;BLACK;	}
// 	if(i-num+6){	BLACK;WHITE;WHITE;BLACK;	BLACK;BLACK;BLACK;BLACK;	}
// 	if(i-num+7){	BLACK;WHITE;WHITE;WHITE;	BLACK;BLACK;BLACK;BLACK;	}
// 	if(i-num+8){	BLACK;WHITE;BLACK;BLACK;	BLACK;BLACK;BLACK;BLACK;	}
	
	BLACK;
	break;
	}
}