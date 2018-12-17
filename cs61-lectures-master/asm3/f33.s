	.file	"f33.cc"
	.text
	.globl	_Z1fj
	.type	_Z1fj, @function
_Z1fj:
.LFB0:
	pushq	%r12
	pushq	%rbp
	pushq	%rbx
	testl	%edi, %edi
	je	.L4
	movl	%edi, %r12d
	movl	$0, %ebx
	movl	$0, %ebp
.L3:
	movl	%ebx, %edi
	call	_Z1gj@PLT
	addl	%eax, %ebp
	addl	$1, %ebx
	cmpl	%ebx, %r12d
	jne	.L3
.L1:
	movl	%ebp, %eax
	popq	%rbx
	popq	%rbp
	popq	%r12
	ret
.L4:
	movl	%edi, %ebp
	jmp	.L1
.LFE0:
	.size	_Z1fj, .-_Z1fj
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
