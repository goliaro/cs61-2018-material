	.file	"f61.cc"
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB0:
	subq	$24, %rsp
	movl	%edi, 12(%rsp)
	movl	12(%rsp), %eax
	addl	$1, %eax
	movl	%eax, %edi
	call	_Z1gi@PLT
	subl	$1, %eax
	addq	$24, %rsp
	ret
.LFE0:
	.size	_Z1fi, .-_Z1fi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
