	.file	"fun08.cc"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d %d %d"
	.text
	.globl	_Z3funPKc
	.type	_Z3funPKc, @function
_Z3funPKc:
.LFB19:
	subq	$40, %rsp
	leaq	.LC0(%rip), %rsi
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	leaq	12(%rsp), %rdx
	leaq	16(%rsp), %rcx
	leaq	20(%rsp), %r8
	call	sscanf@PLT
	orl	$-1, %edx
	cmpl	$3, %eax
	jne	.L1
	movl	16(%rsp), %edx
	addl	12(%rsp), %edx
	subl	20(%rsp), %edx
.L1:
	movq	24(%rsp), %rsi
	xorq	%fs:40, %rsi
	movl	%edx, %eax
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	addq	$40, %rsp
	ret
.LFE19:
	.size	_Z3funPKc, .-_Z3funPKc
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
