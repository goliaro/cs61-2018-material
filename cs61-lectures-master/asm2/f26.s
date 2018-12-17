	.file	"f26.cc"
	.text
	.globl	_Z1fjj
	.type	_Z1fjj, @function
_Z1fjj:
.LFB0:
	cmpl	%esi, %edi
	jb	.L3
	movl	%edi, %eax
	ret
.L3:
	movl	$0, %eax
	ret
.LFE0:
	.size	_Z1fjj, .-_Z1fjj
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
