	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.comm	character_variable,1,1
	.comm	mask,1,1
	.comm	reversed,1,1
	.comm	x,4,4
	.align	2
	.global	main
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L2
	mov	r2, #1
	strb	r2, [r3]
	ldr	r3, .L2+4
	ldrb	r3, [r3]	@ zero_extendqisi2
	mvn	r3, r3
	uxtb	r2, r3
	ldr	r3, .L2+4
	strb	r2, [r3]
	ldr	r3, .L2+4
	mov	r2, #0
	strb	r2, [r3]
	ldr	r3, .L2+8
	mov	r2, #0
	str	r2, [r3]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L3:
	.align	2
.L2:
	.word	character_variable
	.word	mask
	.word	x
	.size	main, .-main
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
