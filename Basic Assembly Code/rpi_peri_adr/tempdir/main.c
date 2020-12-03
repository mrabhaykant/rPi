#include <stdio.h>

int main(void){
int a = 0;
unsigned aU = 0;
signed aS = 0;
short s = 0;
unsigned short sU = 0;
long l = 0;
unsigned long lU = 0;

printf("size of int a = %d\n",sizeof(a));
printf("size of unsigned int a = %d\n",sizeof(aU));
printf("size of Signed int a = %d\n",sizeof(aS));
printf("size of short s = %d\n",sizeof(s));
printf("size of unsigned short  sU = %d\n",sizeof(sU));
printf("size of long l = %d\n",sizeof(l));
printf("size of Unsigned long lU = %d\n",sizeof(lU));


return 0;
}
