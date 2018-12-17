	.file	"f41.cc"
	.text
	.globl	_Z6xor_opii
	.type	_Z6xor_opii, @function
_Z6xor_opii:
.LFB0:
	movl	%edi, %eax
	xorl	%esi, %eax
	ret
.LFE0:
	.size	_Z6xor_opii, .-_Z6xor_opii
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
