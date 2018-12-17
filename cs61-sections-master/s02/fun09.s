	.file	"fun09.cc"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"r"
	.text
	.globl	_Z3funPKc
	.type	_Z3funPKc, @function
_Z3funPKc:
.LFB19:
	leaq	.LC0(%rip), %rsi
	subq	$8, %rsp
	call	fopen@PLT
	orl	$-1, %edx
	testq	%rax, %rax
	je	.L1
	movq	%rax, %rdi
	call	fclose@PLT
	xorl	%edx, %edx
.L1:
	movl	%edx, %eax
	popq	%rdx
	ret
.LFE19:
	.size	_Z3funPKc, .-_Z3funPKc
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
