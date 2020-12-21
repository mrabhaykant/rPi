all:
	
	arm-none-eabi-as -g -o kernel.o main.s
	arm-none-eabi-ld kernel.o -o kernel.elf
	arm-none-eabi-objcopy kernel.elf -O binary kernel.img
	
clean:
	rm kernel.img kernel.elf kernel.o