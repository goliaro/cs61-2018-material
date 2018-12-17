	.file	"f47.cc"
	.text
	.globl	_Z1fPhi
	.type	_Z1fPhi, @function
_Z1fPhi:
.LFB0:
	movslq	%esi, %rsi
	movzbl	(%rdi,%rsi), %eax
	ret
.LFE0:
	.size	_Z1fPhi, .-_Z1fPhi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
