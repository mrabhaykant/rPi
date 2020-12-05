#include <stdio.h>

int main() {
char ch = 0x12;
ch = ch << 4 | ch >> 4;
ch = ch;

return 0;
}
