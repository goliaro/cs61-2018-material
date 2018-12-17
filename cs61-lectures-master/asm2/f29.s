	.file	"f29.cc"
	.text
	.globl	_Z1fPKii
	.type	_Z1fPKii, @function
_Z1fPKii:
.LFB0:
	testl	%esi, %esi
	jle	.L4
	movq	%rdi, %rdx
	leal	-1(%rsi), %eax
	leaq	4(%rdi,%rax,4), %rsi
	movl	$0, %eax
.L3:
	movslq	(%rdx), %rcx
	addq	%rcx, %rax
	addq	$4, %rdx
	cmpq	%rsi, %rdx
	jne	.L3
	rep ret
.L4:
	movl	$0, %eax
	ret
.LFE0:
	.size	_Z1fPKii, .-_Z1fPKii
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
