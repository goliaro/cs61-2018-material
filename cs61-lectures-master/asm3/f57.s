	.file	"f57.cc"
	.text
	.globl	_Z5mod16j
	.type	_Z5mod16j, @function
_Z5mod16j:
.LFB0:
	movl	%edi, %eax
	andl	$15, %eax
	ret
.LFE0:
	.size	_Z5mod16j, .-_Z5mod16j
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
