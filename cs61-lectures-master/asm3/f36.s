	.file	"f36.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB0:
	movl	$0, %eax
	testl	%edi, %edi
	jg	.L8
	rep ret
.L8:
	pushq	%rbx
	movl	%edi, %ebx
	leal	-1(%rdi), %edi
	call	_Z1fi
	imull	%ebx, %eax
	popq	%rbx
	ret
.LFE0:
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
