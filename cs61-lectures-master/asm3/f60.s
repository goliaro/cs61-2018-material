	.file	"f60.cc"
	.text
	.globl	_Z1fll
	.type	_Z1fll, @function
_Z1fll:
.LFB0:
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
.LFE0:
	.size	_Z1fll, .-_Z1fll
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
