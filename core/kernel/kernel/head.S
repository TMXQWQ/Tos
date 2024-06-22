;TIX kernel 0.0.1
;Copyright 2024 TMX

.section .text
ENTRY(__start)



//=======	init page
.align 8

.org	0x1000

__PML4E:

	.quad	0x102003
	.fill	255,8,0
	.quad	0x102003
	.fill	255,8,0

.org	0x2000

__PDPTE:
	
	.quad	0x103003	/* 0x103003 */
	.fill	511,8,0

.org	0x3000

__PDE:

	.quad	0x000083	
	.quad	0x200083
	.quad	0x400083
	.quad	0x600083
	.quad	0x800083		/* 0x800083 */
	.quad	0xa00083
	.quad	0xc00083
	.quad	0xe00083
	.quad	0x1000083
	.quad	0x1200083
	.quad	0x1400083
	.quad	0x1600083
	.quad	0x1800083
	.quad	0x1a00083
	.quad	0x1c00083
	.quad	0x1e00083
	.quad	0x2000083
	.quad	0x2200083
	.quad	0x2400083
	.quad	0x2600083
	.quad	0x2800083
	.quad	0x2a00083
	.quad	0x2c00083
	.quad	0x2e00083



	.quad	0xe0000083		/*0x 3000000*/
	.quad	0xe0200083
	.quad	0xe0400083
	.quad	0xe0600083
	.quad	0xe0800083
	.quad	0xe0a00083
	.quad	0xe0c00083
	.quad	0xe0e00083
	.fill	480,8,0

.section .data

//      	GDT_Table

.globl GDT_Table

GDT_Table:
	.quad	0x0000000000000000			/*0	NULL descriptor		       	00*/
	.quad	0x0020980000000000			/*1	Kernel	Code	64-bit	Segment	08*/
	.quad	0x0000920000000000			/*2	Kernel	Data	64-bit	Segment	10*/
	.quad	0x0000000000000000			/*3	User	Code	32-bit	Segment 18*/
	.quad	0x0000000000000000			/*4	User	Data	32-bit	Segment 20*/
	.quad	0x0020f80000000000			/*5	User	Code	64-bit	Segment	28*/
	.quad	0x0000f20000000000			/*6	User	Data	64-bit	Segment	30*/
	.quad	0x00cf9a000000ffff			/*7	Kernel	Code	32-bit	Segment	38*/
	.quad	0x00cf92000000ffff			/*8	Kerbel	Data	32-bit	Segment	40*/
	.fill	100,8,0					    /*10 ~ 11 TSS in long-mode 128-bit 50*/
GDT_END:

GDT_POINTER:
GDT_LIMIT:	.word	GDT_END - GDT_Table - 1
GDT_BASE:	.quad	GDT_Table

//=======	IDT_Table

.globl IDT_Table

IDT_Table:
	.fill  512,8,0
IDT_END:

IDT_POINTER:
IDT_LIMIT:	.word	IDT_END - IDT_Table - 1
IDT_BASE:	.quad	IDT_Table


