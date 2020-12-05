/*
* Swapping of nibble inside the 8-bit character
*/
#include <stdio.h>

int main() {
char ch = 0x12; // ch is a 8 bit character
                // lower nibble contains = 0010
                // upper nibble contains = 0001
ch = ch << 4 | ch >> 4;
  /*
  ch = 0x12
  ch = ch << 4  // ch = 0x20
  ch = ch >> 4  // ch = 0x01
  ch = 0x20 + 0x01  // ch = 0x21
  */
ch = ch;    // This line is just added so that i can view the result in the debugger

return 0;
}
