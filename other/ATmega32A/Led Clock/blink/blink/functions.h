/*
 * functions.h
 *
 * Created: 12/30/2020 1:42:54 PM
 *  Author: abhay
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define first_row 2
#define second_row 3
#define third_row 7
#define fourth_row 4

#define first_col 4
#define second_col 6
#define third_col 7
#define fourth_col 5

int timer1H;
int timer1L;
char key;
unsigned int maincounter;
char second1;
char minute;
char hour;
char qtrSec;
int initCount=0;
int finCount=0;
void Myinit();
void key_scan();
void USART_Init();
void usart_send (unsigned char ch);
void usart_string (char *st);
void row(int PinNum, char PinHighLow);
void column(char pinNum, char PinHighLow);
void CubeChar(char num);
void CubeCharClock(char num);
void allOff();
void clockUpdate();
void Myinit()
{
	USART_Init();
	DDRA = 0xff;
	DDRB = (1 << 3);
	DDRC |= (1 << DDRC6)|(0 << DDRC7)|(0 << DDRC1)|(0 << DDRC0);
	DDRD |= (1 << DDRD7)|(1 << DDRD6)|(1 << DDRD5)|(1 << DDRD4)|(1 << DDRD3)|(1 << DDRD2)|(1 << DDRD1)|(0 << DDRD0);
	//DDRC &= ~(1 << DDRC7);
	PORTC |= (1 << PORTC7)|(1 << PORTC1)|(1 << PORTC0);
	
	/*
	16000000/256 = 62500
	1/62500 = 1.6*10^-5 = 16 us
	1*10^(-3) / 16us = 62.5
	256-62.5 = 193.5 = 0xc1
	*/
	maincounter = 0;
	second1 = 1;
	minute = 0;
	hour = 0;
	qtrSec = 13;
	timer1H = 0xc2;
	timer1L = 0xf7;
	key = 0x00;	
	
}

void USART_Init()
{
	/* Set baud rate */
	//UBRRH = (unsigned char)(baud>>8);
	UBRRL = 0x67;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
void usart_send (unsigned char ch)
{
	while(! (UCSRA & (1<<UDRE)));
	UDR = ch;
}
void key_scan()
{
	key = PINC;
	if((key & 0x80)  == 0){
		PORTA |= (1 << PORTA2);
		timer1H = 0xe1;
		timer1L = 0x7c;
	}
	else
	{
		PORTA &= ~(1 << PORTA2);

		timer1H = 0xc2;
		timer1L = 0xf7;
	}
	
	if((PINC & (1 << 0)) == 0) //If switch is pressed
	{
		PORTA |= ((PORTA & 0x08) | (1 << PORTA3)); //Turns ON LED
		
	}
	else
	{
		PORTA &= ~((PORTA & 0x08) | (1 << PORTA3)); //Turns OFF LED
	}
	
	if((PINC & (1 << 1)) == 0) //If switch is pressed
	{
		for (char cnt1=0;cnt1 < 0x40; cnt1 ++)
		{
		usart_send(cnt1+0x30);
		}usart_send('\r');usart_send('\n');
	}
	else
	{
	//	usart_send(' ');
	}

}

char usart_receive()
{
	//char rechar;
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}
//for sending string to uart
void usart_string (char *st)
{
	unsigned char i=0;
	while(st[i]!=0)
	{
		usart_send(st[i]);
		i++;
	}
}
// for sending string from Txd with some delay for Esp8266
void USART_SendString (char *st)
{
	unsigned char i=0;
	while(st[i]!=0)
	{
		usart_send(st[i]);
		i++;
		_delay_ms(25);
	}
}








void usart_rec_string()
{
	char ch;
	char carray[100];
	
	int i=0;
	
	while ((ch = usart_receive())!=0x0A)
	{
		
		carray[i++]=ch;
		
	}
	carray[i] = '\0';
	usart_string(carray);
	//	lcd_print(carray);
}

void CubeChar(char num){
	char k1 = num;
	if(k1 == 1){
		row(first_row,1);
		column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(second_row,1);
		column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(third_row,1);
		column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(fourth_row,1);
		column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
		allOff();
	}
	if (k1 == 2)
	{
		row(first_row,1);
		column(first_col, 1);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(second_row,1);
		column(first_col, 1);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(third_row,1);
		column(first_col, 1);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
		allOff();
		row(fourth_row,1);
		column(first_col, 1);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
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
			column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(second_row,1);
			column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(third_row,1);
			column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
			row(fourth_row,1);
			column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
			allOff();
		}
			if (k1 == 4)
			{
				row(first_row,1);
				column(first_col, 1);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 1);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
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
				column(first_col, 1);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
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
				column(first_col, 1);column(second_col,0 );column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 1);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 1);column(second_col, 1);column(third_col, 0);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 7)
			{
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
				column(first_col, 1);column(second_col, 0);column(third_col, 0);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 8)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col,0 );column(third_col, 0);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 9)
			{
				row(first_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(second_row,1);
				column(first_col, 0);column(second_col, 1);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(third_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
				row(fourth_row,1);
				column(first_col, 0);column(second_col, 0);column(third_col, 1);column(fourth_col, 0);
				allOff();
			}
			if (k1 == 0)
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
			if (k1 == 0x0e)
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
			if (k1 == 16)
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
			if (k1 == 17)
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
			if (k1 == 18)
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


#endif /* FUNCTIONS_H_ */
