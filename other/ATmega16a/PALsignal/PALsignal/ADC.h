/*
 * ADC.h
 *
 * Created: 2/5/2021 6:58:58 PM
 *  Author: abhay
 */ 


#ifndef ADC_H_
#define ADC_H_
 char t0ch1;
 char buffer[20];
 static uint8_t A0L;
void ADC_Init(){
	DDRA = 0x00;	        /* Make ADC port as input */
	//ADCSRA = (1 << ADEN)|(1<<ADSC)|(0 << ADATE)| (0 << ADIE)| (1<< ADPS2) | (0<< ADPS1) |(1<< ADPS0);
	//ADCSRA = (1 << ADEN)|(1 << ADIE) | (0<<ADSC) | (1<< ADPS2) | (1<< ADPS1) |(0<< ADPS0);	//0x87;          /* Enable ADC, with freq/128  */
//	ADMUX = 0x40;           /* Vref: Avcc, ADC channel: 0 */
//ADMUX = (1 << REFS1) | (1 << REFS0);	// internal Vref 2.56V
}
void ADC_Read(char channel)
{
	//int Ain,AinLow;
	
	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	
 	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
		 A0L = ADCL;
		 // char buffer[20];
		 itoa(A0L,buffer,10);
		 // t0ch1 = buffer[0];
	 
	//t0ch1 = ADCH/10; 	
// 	_delay_us(10);
// 	AinLow = (int)ADCL;		/* Read lower byte*/
// 	Ain = (int)ADCH*256;		/* Read higher 2 bits and 
// 					Multiply with weight */
// 	Ain = Ain + AinLow;				
// 	
	//return(Ain);			/* Return digital value*/
}

// ISR(ADC_vect){
// 	 A0L = ADCL;
// 	 // char buffer[20];
// 	 itoa(A0L,buffer,16);
// 	// t0ch1 = buffer[0];
// }

void ADC_disp(int num,char chrAlp){
	switch(chrAlp){
		case 'd':
		SPDR = num+0x30;
		//for( o1=0;o1<1;o1++){PORTD = /*0xa0*/(arr9[i-num]>>o1);BLACK;}
		//BLACK;
		break;
		}
	}
// void temp_disp()
// {
// 	char Temperature[10];
// 	float celsius;
// 	celsius = (ADC_Read(0)*4.88);
// 	celsius = (celsius/10.00);
// 	sprintf(Temperature,"%d%cC  ", (int)celsius, degree_sysmbol);/* convert integer value to ASCII string */
// 	LCD_String_xy(2,0,Temperature);/* send string data for printing */
// 	_delay_ms(1000);
// 	memset(Temperature,0,10);
// }


#endif /* ADC_H_ */