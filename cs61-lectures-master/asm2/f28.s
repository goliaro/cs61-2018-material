	.file	"f28.cc"
	.text
	.globl	_Z1fiii
	.type	_Z1fiii, @function
_Z1fiii:
.LFB0:
	cmpl	%edx, %esi
	movl	%edx, %ecx
	cmovge	%esi, %ecx
	movl	%edi, %eax
	cmpl	%ecx, %edi
	jge	.L1
	cmpl	%edx, %edi
	cmovl	%edx, %edi
	cmpl	%edi, %esi
	movl	%edx, %eax
	cmovge	%esi, %eax
.L1:
	rep ret
.LFE0:
	.size	_Z1fiii, .-_Z1fiii
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
