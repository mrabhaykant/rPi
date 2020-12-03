#include <stdio.h>
#include <bcm_host.h>

/*
If there is no kernel driver available, and a program needs 
to access a peripheral address directly with mmap, it needs 
to know where in the virtual memory map the peripheral bus 
segment has been placed. This varies according to which modle
 of rPi is being used, so there are three helper function 
available to provide platform independence. 

unsigned bcm_host_get_peripheral_address()
unsigned bcm_host_get_peripheral_size()
unsigned bcm_host_get_sdram_address()
*/
unsigned bcm_host_get_peripheral_address();
int main()
{
unsigned int address = 0;

printf("Address : %x",bcm_host_get_peripheral_address());
printf("Address : %x",bcm_host_get_peripheral_size());
printf("Address : %x",bcm_host_get_sdram_address());
return 0;
}
