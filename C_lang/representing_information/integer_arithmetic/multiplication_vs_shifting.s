	.file	"multiplication_vs_shifting.c"
	.section	".text"
	.align 2
	.globl main
	.type	main, @function
main:
	stwu 1,-32(1)
	stw 31,28(1)
	mr 31,1
	li 9,10
	stw 9,8(31)
	li 9,20
	stw 9,12(31)
	li 9,0
	mr 3,9
	addi 11,31,32
	lwz 31,-4(11)
	mr 1,11
	blr
	.size	main,.-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
