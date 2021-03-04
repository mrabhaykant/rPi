.data
string: .asciz "\nHello\n"
.text
.global main
.extern printf

main:
	MOV R0,#0
	MOV R0,R13	//move sp to r0
	ADD R1,R0,R1	//add r0 to r1
	push {r1}
	pop {r1}
	ldr r0, =string
	bl printf
	MOV R5,#5
	b loop
	b main

loop:
	SUB R5,#1
	BNE loop
