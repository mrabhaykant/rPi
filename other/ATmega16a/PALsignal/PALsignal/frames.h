/*
 * frames.h
 *
 * Created: 2/11/2021 3:41:39 PM
 *  Author: abhay
 */ 


#ifndef FRAMES_H_
#define FRAMES_H_
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
		{//8
			ZERO;

			//NOP
			myDelay(0xfa);
			//myDelay(0xFa);
			BLACK;
			BLACK;BLACK;BLACK;
			
			BLACK;

			for (o1 = 0;o1 < 6;o1++){

				PORTD ^= (1<<5);

				
			}
			BLACK;

			if (i<10)
			{
				//	WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(1);BLACK;
			}
			if (i>=40&&i<=59)
			{
				myName4(40,SWxxH+0x30);
				myName4(40,SWxH+0x30);
				myName4(40,'d');
				myName4(40,SWxxM+0x30);
				myName4(40,SWxM+0x30);
				myName4(40,'d');
				myName4(40,SWxs+0x30);
				myName4(40,SW1+0x30);

				
			}
			
			if (i>=70&&i<=89)
			{
				
			}
			if (i>=95&&i<=114)
			{
				
			}
			if (i>=125&&i<=144)
			{
				myName(125,'f');myName(125,'i');myName(125,'n');myName(125,'i');myName(125,'s');myName(125,'h');
			}
			if (i>=150&&i<=169)
			{
			//	myName4(150,'1');myName4(150,'2');myName4(150,'3');myName4(150,'4');myName4(150,'5');myName4(150,'6');myName4(150,'7');myName4(150,'8');myName4(150,'9');myName4(150,'0');
				
			}
			if (i>=180&&i<=199)
			{

				
			}
			if (i>=210&&i<=229)
			{
				//myName4(210,'1');myName4(210,'2');myName4(210,'3');myName4(210,'4');myName4(210,'5');myName4(210,'6');myName4(210,'7');myName4(210,'8');myName4(210,'9');myName4(210,'0');
				
			}
			if (i>=240&&i<=259)
			{
	
			}
			if (i>=270&&i<=289)
			{
				myName(270,'a');myName(270,'b');myName(270,'h');myName(270,'a');myName(270,'y');//myName(270,'a');
				_delay_us(1);
				myName(270,'k');myName(270,'a');myName(270,'n');myName(270,'t');	
			}
			if (i>=290&&i<=309){
			WHITE;_delay_us(30);
			}
			
			BLACK;_delay_us(2);
		}
	}
	
	///////////////////////////////////////////
	if(alpha == 3){
		
		if(i>=6 && i <=308)
		{//8
			ZERO;

			//NOP
			myDelay(0xfa);
			//myDelay(0xFa);
			BLACK;
			BLACK;BLACK;BLACK;
			
			BLACK;

			for (o1 = 0;o1 < 6;o1++){

				PORTD ^= (1<<5);

				
			}
			BLACK;
	if (i>=50 && i<150 )
	{
		_delay_us(4);
		for (j=0;j<25;j++)
		{
			for (k=j;k<4;k++)
			{
				if (i>50 && i<150)
				{
					SPDR = 0xfe;
				}
			}
			
		}
	}
	else if (i>=150 && i<=269)
	{_delay_us(5);
		
		for (j=0;j<2;j++)
		{
			SPDR = 0xfe;
		}
	
	}
	else if (i>=270 && i<=300)
	{
		for (j=0;j<25;j++)
		{
			for (k=j;k<3;k++)
			{
				SPDR = 0xfe;
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
			BLACK;
			BLACK;BLACK;BLACK;
			
		//	BLACK;
// 			SPDR ^= 0xaa;
// 			SPDR ^= 0xaa;
// 						SPDR ^= 0xaa;
// 						SPDR ^= 0xaa;
// 									SPDR ^= 0xaa;
// 									SPDR ^= 0xaa;
// 			for (o1 = 0;o1 <4;o1++){
			for (o1 = 0;o1 < 6;o1++){
				
				//while(!(SPSR & (1<<SPIF)));
				PORTD ^= (1<<5);

				
			}
			//SPSR |= (1 << SPI2X); 
			//SPSR &= ~(1 << SPI2X); 
			
			
			BLACK;
			_delay_us(2);

			if (i<10)
			{
				//	WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(10);BLACK;WHITE;_delay_us(1);BLACK;
			}
			if (i>=40&&i<=59)
			{
				myName4(40,SWxxH+0x30);
				myName4(40,SWxH+0x30);
				myName4(40,'d');
				myName4(40,SWxxM+0x30);
				myName4(40,SWxM+0x30);
				myName4(40,'d');
				myName4(40,SWxs+0x30);
				myName4(40,SW1+0x30);

				
			}
			if (i>=70&&i<=89)
			{
			
			}
			if (i>=95&&i<=114)
			{
			myName(95,'t');myName(95,'i');myName(95,'m');myName(95,'e');myName(95,'r');
			}
			if (i>=125&&i<=144)
			{
			
			}
			if (i>=150&&i<=169)
			{
			
			}
			if (i>=180&&i<=199)
			{
				
			
			}
			if (i>=210&&i<=229)
			{
	
			}
			if (i>=240&&i<=259)
			{
	
				myName(240,'b');myName(240,'y');
			}
			if (i>=270&&i<=289)
			{
				myName(270,'a');myName(270,'b');myName(270,'h');myName(270,'a');myName(270,'y');
				_delay_us(1);
				myName(270,'k');myName(270,'a');myName(270,'n');myName(270,'t');
			}
			if (i>=290&&i<=309){}

			BLACK;_delay_us(2);
		}
	}
	if(alpha == 6){
		
		if(i>=6 && i <=308)
		{
			ZERO;myDelay(0xF9);BLACK;_delay_us(8);
			BLACK;
			//	_delay_us(5);
			//WHITE;
			_delay_us(1);
			if (i<190)
			{
				for (j=0;j<20;j++)
				{
					for (k=j;k<2;k++)
					{
						BLACK;WHITE;
						SPDR = 0xff;
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
}




#endif /* FRAMES_H_ */