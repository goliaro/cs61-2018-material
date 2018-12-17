	.file	"f48.cc"
	.text
	.globl	_Z1fPsi
	.type	_Z1fPsi, @function
_Z1fPsi:
.LFB0:
	movslq	%esi, %rsi
	movswl	(%rdi,%rsi,2), %eax
	ret
.LFE0:
	.size	_Z1fPsi, .-_Z1fPsi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
