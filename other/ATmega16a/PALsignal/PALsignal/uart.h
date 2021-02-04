/*
 * uart.h
 *
 * Created: 2/1/2021 10:00:59 PM
 *  Author: abhay
 */ 


#ifndef UART_H_
#define UART_H_

// #define BAUD 9600
// #define MYUBRR FOSC/16/BAUD-1
// 
// USART_Init ( MYUBRR );

void USART_Init()
{
	/* Set baud rate */
	//UBRRH = (unsigned char)(baud>>8);
	UBRRL = 0x67;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN)| (1<< RXCIE);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
void usart_send (unsigned char ch)
{
	while(! (UCSRA & (1<<UDRE)));
	UDR = ch;
}
char usart_receive()
{
	//char rechar;
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}

#endif /* UART_H_ */