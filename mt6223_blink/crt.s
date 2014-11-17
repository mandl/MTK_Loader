

.macro clear_bss
	mov   r0, #0
	ldr   r1, =__bss_start
	ldr   r2, =__bss_end
loop_bss:
	cmp   r1, r2
	strlo r0, [r1], #4
	blo   loop_bss
.endm

.macro copy_data
    ldr   r0, =__data_start
    ldr   r1, =_data_start
    ldr   r2, =__data_end
	cmp r0, r2
	beq done_data
loop_data:
    ldrb  r4, [r0], #1
    strb  r4, [r1], #1
	cmp r0, r2
    bne   loop_data
done_data:
.endm

.macro copy_ramtext
    ldr   r0, =__ramtext_start
    ldr   r1, =_ramtext_start
    ldr   r2, =__ramtext_end
	cmp r0, r2
	beq done_ramtext
loop_ramtext:
    ldrb  r4, [r0], #1
    strb  r4, [r1], #1
	cmp r0, r2
    bne   loop_ramtext
done_ramtext:
.endm

	.EQU	ARM_MODE_FIQ,	0x11
	.EQU	ARM_MODE_IRQ,	0x12
	.EQU	ARM_MODE_SVC,	0x13


	.EQU	I_BIT,		0x80
	.EQU	F_BIT,		0x40

	.EQU	TOP_OF_RAM_EXT, 	0x4000a000
	.EQU 	FIQ_STACK_SIZE_1,	1024
	.EQU 	IRQ_STACK_SIZE_1,	1024

.macro init_stacks
	/* initialize stacks, starting at TOP_OF_RAM */
	ldr	r0, =TOP_OF_RAM_EXT

	/* initialize FIQ stack */
	msr	CPSR_c, #ARM_MODE_FIQ | I_BIT | F_BIT
	mov	r13, r0
	sub	r0, r0, #FIQ_STACK_SIZE_1

	/* initialize IRQ stack */
	msr	CPSR_c, #ARM_MODE_IRQ | I_BIT | F_BIT
	mov	r13, r0
	sub	r0, r0, #IRQ_STACK_SIZE_1

	/* initialize supervisor stack */
	msr	CPSR_c, #ARM_MODE_SVC | I_BIT | F_BIT
	mov	r13, r0
.endm


.globl _start
_start:

.globl _vectors
_vectors:   b _Reset
            ldr     PC, Undef_Addr
            ldr     PC, SWI_Addr
            ldr     PC, PAbt_Addr
            ldr     PC, DAbt_Addr
            ldr     PC, IRQ_Addr
            ldr     PC, IRQ_Addr
            ldr     PC, FIQ_Addr


Undef_Addr:     .word   UNDEF_Routine		/* defined in main.c  */
SWI_Addr:       .word   SWI_Routine			/* defined in main.c  */
PAbt_Addr:      .word   UNDEF_Routine		/* defined in main.c  */
DAbt_Addr:      .word   UNDEF_Routine		/* defined in main.c  */
IRQ_Addr:       .word   IRQ_Routine         /* defined in main.c  */
FIQ_Addr:       .word   FIQ_Routine			/* defined in main.c  */

_Reset:
	/* clear bss section */
	clear_bss

	 /*initialize all stacks */
	init_stacks

	/* jump to main */
	ldr	pc, _jump_main

	/* endless loop at end of program */
_loop:
	b	_loop
	b	_start

_jump_main:
	.word main


