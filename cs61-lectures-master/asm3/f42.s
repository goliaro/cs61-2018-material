	.file	"f42.cc"
	.text
	.globl	_Z6not_opi
	.type	_Z6not_opi, @function
_Z6not_opi:
.LFB0:
	movl	%edi, %eax
	notl	%eax
	ret
.LFE0:
	.size	_Z6not_opi, .-_Z6not_opi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
