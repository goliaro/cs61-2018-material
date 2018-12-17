	.file	"f51.cc"
	.text
	.globl	_Z1fP9two_wordsi
	.type	_Z1fP9two_wordsi, @function
_Z1fP9two_wordsi:
.LFB0:
	movslq	%esi, %rsi
	movl	(%rdi,%rsi,8), %eax
	ret
.LFE0:
	.size	_Z1fP9two_wordsi, .-_Z1fP9two_wordsi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
