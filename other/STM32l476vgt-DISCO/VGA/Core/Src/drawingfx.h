/*
 * drawingfx.h
 *
 *  Created on: Feb 24, 2021
 *      Author: abhay
 */

#ifndef SRC_DRAWINGFX_H_
#define SRC_DRAWINGFX_H_
void boxy(uint8_t x,uint16_t y,uint8_t w,uint16_t h){
	int i;
	for(i = x; i < (x+w) ; i++){
	 			myPhoto1[x+y][i] |= 0xff;	// ROW
	 	  }
	  for(i = y;i<(y+h);i++){
			myPhoto1[i][x] |= 0x40;	// column left
		  }
	  for(i = y;i<(y+h);i++){
					myPhoto1[i][x+w] |= 0x80;	// column right
			  }
	  for(i = x;i<(x+w);i++){
				myPhoto1[(y+h)][i] |= 0xff;	// ROW
		  }
}
void boxy_inv(uint8_t x,uint16_t y,uint8_t w,uint16_t h){
	int i;
	for(i = x; i < (x+w) ; i++){
		 			myPhoto1[x+y][i] &= ~0xff;	// ROW
		 	  }
		  for(i = y;i<(y+h);i++){
				myPhoto1[i][x] &= ~0x40;	// column left
			  }
		  for(i = y;i<(y+h);i++){
						myPhoto1[i][x+w] &= ~0x80;	// column right
				  }
		  for(i = x;i<(x+w);i++){
					myPhoto1[(y+h)][i] &= ~0xff;	// ROW
		  }
}
//for(i = 30;i<35;i++){
// 			myPhoto1[10][i] |= 0xff;	// ROW
// 	  }
// 	  for(i = 0;i<39;i++){
// 	  			myPhoto1[i][30] |= 0x40;	// column
// 	  	  }
// 	  for(i = 0;i<39;i++){
// 	  	  			myPhoto1[i][34] |= 0x40;	// column
// 	  	  	  }
// 	  for(i = 30;i<35;i++){
// 	 			myPhoto1[39][i] |= 0xff;	// ROW
// 	 	  }



#endif /* SRC_DRAWINGFX_H_ */
