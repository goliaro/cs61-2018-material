	.file	"f30.cc"
	.text
	.globl	_Z1fRSt6vectorIiSaIiEE
	.type	_Z1fRSt6vectorIiSaIiEE, @function
_Z1fRSt6vectorIiSaIiEE:
.LFB871:
	movq	(%rdi), %rax
	movq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.L4
	movq	%rax, %rdx
	addq	$4, %rax
	subq	%rax, %rcx
	andq	$-4, %rcx
	addq	%rax, %rcx
	movl	$0, %eax
.L3:
	movslq	(%rdx), %rsi
	addq	%rsi, %rax
	addq	$4, %rdx
	cmpq	%rcx, %rdx
	jne	.L3
	rep ret
.L4:
	movl	$0, %eax
	ret
.LFE871:
	.size	_Z1fRSt6vectorIiSaIiEE, .-_Z1fRSt6vectorIiSaIiEE
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
