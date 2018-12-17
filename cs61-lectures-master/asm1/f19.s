	.file	"f19.cc"
	.text
	.globl	_Z1fiii
	.type	_Z1fiii, @function
_Z1fiii:
.LFB0:
	imull	$1000, %edi, %edi
	imull	$-10000, %esi, %eax
	addl	%edi, %eax
	imull	$-100000, %edx, %edx
	addl	%edx, %eax
	ret
.LFE0:
	.size	_Z1fiii, .-_Z1fiii
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
