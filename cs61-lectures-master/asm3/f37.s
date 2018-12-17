	.file	"f37.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB0:
	testl	%edi, %edi
	movl	$1, %eax
	jle	.L4
.L3:
	imull	%edi, %eax
	subl	$1, %edi
	jne	.L3
	rep ret
.L4:
	rep ret
.LFE0:
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
