	.file	"f56.cc"
	.text
	.globl	_Z1flll
	.type	_Z1flll, @function
_Z1flll:
.LFB0:
	salq	$20, %rdi
	imulq	%rdx, %rsi
	leaq	(%rdi,%rsi), %rax
	ret
.LFE0:
	.size	_Z1flll, .-_Z1flll
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
