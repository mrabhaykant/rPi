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
#include "dispChars.h"
#define NOP asm("nop");
#define ZERO PORTD=0
#define BLACK PORTD=(1<<7) //v out = .3v (black color)
#define WHITE PORTD=(1<<5) //v out = .8v (just white color)
#define color PORTD=(1<<7)|(1<<5)
int8_t SW1;
char SWxs;
char SWxM;
char SWxxM;
void myName(int num,char chrAlp);
void myName4(int num,char chrAlp);
void myName5(int num,char chrAlp);
void tvchar(int alpha);
void myDelay(int num);
static int16_t i;
static int8_t j,k,o1=0;
static uint8_t m;

// struct d_chr{
// 	int8_t d_chr_pos[20];
// 	};
#include "dispFrames.h"
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
//	tvchar(SW1);
	
	if (SWxs > 5)
	{
		SWxs=0;SWxM++;
	}
	if (SWxM>9)
	{
		SWxM=0;SWxxM++;
	}
	if (SWxxM >5)
	{
		SWxxM =0;
	}
	tvchar(5);
// 		if (m < 127)
// 		{
// 			tvchar(SW1);
// 		}
// 		if (m >= 127)
// 		{
// 			tvchar(1);
// 		}
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
	SW1++;
	if(SW1>9){SW1=0;SWxs++;}
// 		if (SWxs > 5)
// 		{
// 			SWxs=0;SWxM++;
// 		}
// 		if (SWxM>9)
// 		{
// 			SWxM=0;SWxxM++;
// 		}
// 		if (SWxxM >5)
// 		{
// 			SWxxM =0;
// 		}
	TCNT1 = 0xc2f7;
	//TCNT1 = 0xe17b;	//0.5s
	//TCNT1 = 0xf0be;	//0.25
	sei();
	
}
int main(void)
{
	DDRD |= (1<<7)|(1<<5)|(1 <<4);
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

void tvchar(int alpha){
	if(alpha == 0){
		
		if(i>=6 && i <=308)
		{
			ZERO;myDelay(0xF9);BLACK;_delay_us(8);
			BLACK;
			_delay_us(5);
			//WHITE;
			BLACK;
			//_delay_us(1);
			if (i<50)
			{
			}
			if (i>=50 && i<150 )
			{
				_delay_us(4);
				for (j=0;j<25;j++)
				{
					for (k=j;k<2;k++)
					{
						if (i>50 && i<150)
						{
							WHITE;BLACK;WHITE;BLACK;WHITE;BLACK;WHITE;BLACK;WHITE;
						}
						
						// 								if (i>90 && i<100)
						// 								{
						// 									BLACK;WHITE;
						// 								}
						
						//_delay_us(1);
					}
					
				}
			}
			else if (i>=150 && i<=289)
			{_delay_us(5);
				for (j=0;j<2;j++)
				{
					
					WHITE;
					//_delay_us(1);
					
					
				}
			}
			else if (i>=290 && i<=300)
			{
				for (j=0;j<25;j++)
				{
					for (k=j;k<2;k++)
					{
						WHITE;
						_delay_us(1);
					}
					
				}
			}
			
			BLACK;_delay_us(2);
		}

	}
	if(alpha == 1){
		if(i>=6 && i <=308)
		{
			ZERO;myDelay(0xF9);BLACK;_delay_us(8);
			BLACK;
			_delay_us(5);
			//WHITE;
			BLACK;
			//_delay_us(1);
			if (i<50)
			{
			}
			if (i>=50 && i<150 )
			{
				_delay_us(4);
				for (j=0;j<25;j++)
				{
					for (k=j;k<2;k++)
					{
						if (i>50 && i<150)
						{
							WHITE;BLACK;WHITE;BLACK;WHITE;
						}
						// 								if (i>90 && i<100)
						// 								{
						// 									BLACK;WHITE;
						// 								}
						
						//_delay_us(1);
					}
					
				}
			}
			else if (i>=150 && i<=289)
			{_delay_us(5);
				for (j=0;j<2;j++)
				{
					
					WHITE;
					//_delay_us(1);
					
					
				}
			}
			else if (i>=290 && i<=300)
			{
				for (j=0;j<25;j++)
				{
					for (k=j;k<2;k++)
					{
						WHITE;
						_delay_us(1);
					}
					
				}
			}
			
			BLACK;_delay_us(2);
		}
	}
	if(alpha == 3){
		
		if(i>=6 && i <=308)
		{
			ZERO;myDelay(0xF9);BLACK;_delay_us(8);
			BLACK;
			_delay_us(5);
			WHITE;
			_delay_us(1);
			if (i<190)
			{
				for (j=0;j<20;j++)
				{
					for (k=j;k<2;k++)
					{
						BLACK;WHITE;
						_delay_us(1);
					}
					
				}
			}
			else if (i>200)
			{
				for (j=0;j<30;j++)
				{
					for (k=j;k<2;k++)
					{
						_delay_us(1);
					}
					
				}
			}
			
			BLACK;_delay_us(2);
		}
		

	}
	
	if(alpha == 4){
		if(i>=6 && i <=308)
		{//8
			ZERO;myDelay(0xF9);
			BLACK;
			BLACK;
			BLACK;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;
			BLACK;
			WHITE;


			
			
			BLACK;_delay_us(6);
			//BLACK;
			//_delay_us(5);
			//WHITE;
			//BLACK;
			//_delay_us(1);
			if (i<10)
			{
				WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(1);BLACK;
			}
			if (i>=40&&i<=59)
			{
				myName(40,'a');
				myName(40,'b');
				myName(40,'h');
				myName(40,'a');
				myName(40,'y');
				//	myName(60,'h');
				//	myName(60,'a');
				//for(int o1=0;o1<4;o1++)PORTD = (1<<5)&(arr1[i-60]<<o1);
				
				//for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arry[i-60]>>o1);
				
				// 				for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arry[i-60]>>o1);
				// 				BLACK;
				
			}
			if (i>=70&&i<=89)
			{
				myName(70,'a');
				myName(70,'a');
				myName(70,'h');
				myName(70,'a');
				myName(70,'y');
			}
			if (i>=95&&i<=114/*114*/)
			{
				myName4(95,'1');
				// 					for(int o1=0;o1<3;o1++){PORTD =/* 0xa0&*/(arrZ[i-95]>>o1);}
				// 					BLACK;
				myName4(95,'2');
				myName4(95,'3');
				myName4(95,'4');
				
 				
// 				myName(95,'y');
			}
			if (i>=125&&i<=144)
			{
				myName4(125,'5');
				myName4(125,'6');
				myName4(125,'7');
				myName4(125,'8');
				
				//myName(125,'h');
				//myName(125,'a');
				//myName(120,'y');
				//for(int o1=0;o1<5;o1++)PORTD = (1<<5)&(arrB[i-90]<<o1);
				//for(int o1=0;o1<5;o1++)PORTD = (1<<5)&(arr1[i-90]<<o1);
				//for(int o1=0;o1<7;o1++)
				// 				PORTD = (1<<7)|(arr1[101-i]<<o1);
				
			}
			if (i>=150&&i<=169)
			{
				myName4(150,'9');
 				myName4(150,'0');
// 				myName(150,'h');
// 				myName(150,'a');
// 				myName(150,'y');
			}
			if (i>=180&&i<=199)
			{
				myName(180,'a');
				myName(180,'b');
				myName(180,'h');
				myName(180,'a');
				myName(180,'y');
			}
			if (i>=210&&i<=229)
			{
				myName(210,'a');
				myName(210,'b');
				myName(210,'h');
				myName(210,'a');
				myName(210,'y');
			}
			if (i>=240&&i<=259)
			{
				myName(240,'a');
				myName(240,'b');
				myName(240,'h');
				myName(240,'a');
				myName(240,'y');
			}
// 			if (i>=270&&i<=289)
// 			{
// 				myName(270,'a');
// 				myName(270,'b');
// 				myName(270,'h');
// 				myName(270,'a');
// 				myName(270,'y');
// 			}
			// 				if (i>=290&&i<=309)
			// 				{
			// 					myName(270,'a');
			// 					myName(270,'b');
			// 					myName(270,'h');
			// 					myName(270,'a');
			// 					myName(270,'y');
			// 				}
			// 			else if (i>=280 && i<=300)
			// 			{
			// 				//myName(20);
			// 				for (j=0;j<25;j++)
			// 				{
			// 					for (k=j;k<2;k++)
			// 					{
			// 						WHITE;
			// 						_delay_us(1);
			// 					}
			//
			// 				}
			// 			}
			
			BLACK;_delay_us(2);
		}
	}
		if(alpha == 5){
			if(i>=6 && i <=308)
			{//8
				ZERO;

							//NOP					
				myDelay(0xfa);
				//myDelay(0xFa);
					BLACK;BLACK;BLACK;BLACK;
// NOP
									//NOP
// 									NOP
// 									NOP
// 													NOP
// 													NOP
// 													NOP
// 													NOP
					//	PORTD =16;
							//	NOP
								//NOP
					//PORTD =0x80;
					PORTD =0x10;
					PORTD =0x90;//NOP
					PORTD =0x00;
										PORTD =0x90;
					PORTD =0x10;
				//	PORTD =0x90;
					PORTD =0x00;
					PORTD =0x10;
					PORTD =0x90;
				//	PORTD =0x90;
					PORTD =0x00;
					PORTD =0x00;
					
// 										PORTD =0x10;
// 										PORTD =0x90;
// 										PORTD =0x10;
// 										PORTD =0x00;
					
// 										PORTD =0x10;
// 										PORTD =0x90;
// 										PORTD =0x10;
// 										PORTD =0x00;
														
					
// 					PORTD =0x80;
// 					PORTD =0x90;
// 					
// 					PORTD =0x80;PORTD =0x80;
// 					PORTD =0x90;
// 					
// 					PORTD =0x80;
// 					PORTD =0x90;
					
					//PORTD =0x80;PORTD =0x80;
					//PORTD =0x90;//PORTD =0x90;
					//PORTD =0x80;PORTD =0x80;
				//		PORTD =0x10;//PORTD =0x90;
						//PORTD =0x80;//PORTD =0x80;
				//	NOP
// 					PORTD =0x90;
// 					
// 					PORTD =0x80;PORTD =0x80;
// 					PORTD =0x90;
// 					
// 					PORTD =0x80;PORTD =0x80;
// 					PORTD =0x90;
// 					PORTD = 00;
					
// 																		PORTD =00;
// 																		PORTD =0x00;
// 																		PORTD =16;
// 																		PORTD =00;
// 																		PORTD =0x00;
									//PORTD ^=(1<<5);
									//PORTD ^=(1<<5);
									//////////////////////////
									//PORTD ^=(1<<5);
									//PORTD ^=(1<<5);
									//PORTD ^=(1<<5);

									//PORTD ^=(1<<5);
																	//	PORTD ^=(1<<5);
																		//PORTD ^=(1<<5);

// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
// 									PORTD ^=(1<<7)|(1<<4);PORTD ^=(1<<4);
				BLACK;
// 				BLACK;BLACK;BLACK;BLACK;
// 				BLACK;
_delay_us(1);
				//NOP
				//NOP
				//NOP
				//NOP
				//NOP
			//myDelay(0xFf);
//			myDelay(0xff);
								//	WHITE;
				//_delay_us(5);
				//WHITE;
				//BLACK;
				//_delay_us(1);
				if (i<10)
				{
					WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(1);BLACK;
				}
				if (i>=40&&i<=59)
				{
					myName4(40,SWxxM+0x30);
					myName4(40,SWxM+0x30);
					BLACK;
					WHITE;
					WHITE;
					BLACK;
										//myName4(40,'d');
// 					if(i>=45 &&i<=46){WHITE;BLACK;}
// 					if(i>=50 &&i<=51){WHITE;BLACK;}
					myName4(40,SWxs+0x30);
					myName4(40,SW1+0x30);
// 					myName(40,'b');
// 					myName(40,'h');
// 					myName(40,'a');
//  					myName(40,'y');
					//	myName(60,'h');
					//	myName(60,'a');
					//for(int o1=0;o1<4;o1++)PORTD = (1<<5)&(arr1[i-60]<<o1);
					
					//for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arry[i-60]>>o1);
					
					// 				for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arry[i-60]>>o1);
					// 				BLACK;
					
				}
// 				if (i>=70&&i<=89)
// 				{
// 					//myName(70,'a');myName(70,'b');myName(70,'h');myName(70,'a');myName(70,'y');
// 					myName4(95,'1');myName4(95,'2');//myName4(95,'3');myName4(95,'4');
// 				}
				if (i>=95&&i<=114)
				{
					myName4(95,'1');myName4(95,'2');myName4(95,'3');myName4(95,'4');
	// 				myName(95,'y');
				}
				if (i>=125&&i<=144)
				{
					myName4(125,'5');myName4(125,'6');myName4(125,'7');myName4(125,'8');
				}
 				if (i>=150&&i<=169)
 				{
  					myName4(150,'9');myName4(150,'0');myName4(150,'9');myName4(150,'0');//BLACK;
 // 					// 				myName(150,'h');
 // 					// 				myName(150,'a');
 // 					// 				myName(150,'y');
 				}
				if (i>=180&&i<=199)
				{
					myName(180,'a');myName(180,'b');myName(180,'h');myName(180,'a');myName(180,'y');//myName(180,'a');
				}
				if (i>=210&&i<=229)
				{
					//myName(210,'a');myName(210,'b');myName(210,'h');myName(210,'a');
					myName4(210,'n');
				}
				if (i>=240&&i<=259)
				{
					myName(240,'a');
					myName(240,'b');
					myName(240,'h');
					myName(240,'a');
					myName(240,'y');
				}
				if (i>=270&&i<=289)
				{
				 	myName(270,'a');
				 	myName(270,'b');
				 	myName(270,'h');
				 	myName(270,'a');
				 	myName(270,'y');
				}
 				 				if (i>=290&&i<=309){}
// 				 				{
// 									 WHITE;_delay_us(50);}
				 				//	myName(270,'a');
				// 					myName(270,'b');
				// 					myName(270,'h');
				// 					myName(270,'a');
				// 					myName(270,'y');
				// 				}
				// 			else if (i>=280 && i<=300)
				// 			{
				// 				//myName(20);
				// 				for (j=0;j<25;j++)
				// 				{
				// 					for (k=j;k<2;k++)
				// 					{
				// 						WHITE;
				// 						_delay_us(1);
				// 					}
				//
				// 				}
				// 			}
				
				BLACK;_delay_us(2);
			}
		}
}


void myName(int num,char chrAlp){
	//int8_t temp1;
	switch(chrAlp){
		
	case 'a':
	//BLACK;
	for(int o1=0;o1<3;o1++)PORTD = 0xa0&(arra[i-num]>>o1);
		
		BLACK;
// 		ZERO;
		
	break;
	case 'b':
	for( int o1=0;o1<3;o1++)PORTD = 0xa0&(arrb[i-num]>>o1);
	BLACK;
	ZERO;//BLACK;
	break;
	case 'h':
	for(int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arrh[i-num]>>o1);
	BLACK;
	break;
// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arra[i-num]>>o1);
// 	BLACK;
	case 'y':
	for(int o1=0;o1<3;o1++)PORTD = /*0xa0*/(arry[i-num]>>o1);
	BLACK;
	break;
	}
// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arra[i-num]>>o1);
// 	BLACK;
// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arry[i-num]>>o1);
// 	BLACK;
}
void myName4(int num,char chrAlp){
	switch(chrAlp){
			case 'd':
			
			//for( o1=0;o1<1;o1++){PORTD = /*0xa0*/(arr9[i-num]>>o1);BLACK;}
			//BLACK;
			break;
			case '0':
			for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr0[i-num]>>o1);
			BLACK;
			break;
		case '1':
		for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arr1[i-num]>>o1);
		BLACK;
		break;
		case '2':
		for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arr2[i-num]>>o1);
		BLACK;
		break;
		case '3':
		for( int o1=0;o1<3;o1++)PORTD = /*0xff&*/(arr3[i-num]>>o1);
		BLACK;
		break;
		// 	for(int o1=0;o1<3;o1++)PORTD = (1<<5)&(arra[i-num]>>o1);
		// 	BLACK;
		case '4':
		for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr4[i-num]>>o1);
		BLACK;
		break;
// 	}
// }
// void myName5(int num,char chrAlp){
// 	switch (chrAlp){
		case '5':
		for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr5[i-num]>>o1);
		BLACK;
	break;
	case '6':
		for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr6[i-num]>>o1);
		BLACK;
	break;
	case '7':
		for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr7[i-num]>>o1);
		BLACK;
	break;
	case '8':
	for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr8[i-num]>>o1);
	BLACK;
	break;
	case '9':
	for( o1=0;o1<3;o1++)PORTD = /*0xa0*/(arr9[i-num]>>o1);
	BLACK;
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