	.file	"f35.cc"
	.text
	.globl	_Z1fj
	.type	_Z1fj, @function
_Z1fj:
.LFB1:
	testl	%edi, %edi
	je	.L4
	xorl	%edx, %edx
	xorl	%eax, %eax
.L3:
	addl	%edx, %eax
	addl	$1, %edx
	cmpl	%edx, %edi
	jne	.L3
	rep ret
.L4:
	xorl	%eax, %eax
	ret
.LFE1:
	.size	_Z1fj, .-_Z1fj
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
