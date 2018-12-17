	.file	"f49.cc"
	.text
	.globl	_Z1fPii
	.type	_Z1fPii, @function
_Z1fPii:
.LFB0:
	movslq	%esi, %rsi
	movl	(%rdi,%rsi,4), %eax
	ret
.LFE0:
	.size	_Z1fPii, .-_Z1fPii
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
