	.file	"f34.cc"
	.text
	.globl	_Z1fj
	.type	_Z1fj, @function
_Z1fj:
.LFB1:
	testl	%edi, %edi
	je	.L7
	leal	-1(%rdi), %eax
	cmpl	$7, %eax
	jbe	.L8
	pxor	%xmm0, %xmm0
	movl	%edi, %edx
	xorl	%eax, %eax
	movdqa	.LC0(%rip), %xmm1
	shrl	$2, %edx
	movdqa	.LC1(%rip), %xmm2
.L5:
	addl	$1, %eax
	paddd	%xmm1, %xmm0
	paddd	%xmm2, %xmm1
	cmpl	%edx, %eax
	jb	.L5
	movdqa	%xmm0, %xmm1
	movl	%edi, %edx
	andl	$-4, %edx
	psrldq	$8, %xmm1
	paddd	%xmm1, %xmm0
	movdqa	%xmm0, %xmm1
	cmpl	%edx, %edi
	psrldq	$4, %xmm1
	paddd	%xmm1, %xmm0
	movd	%xmm0, %eax
	je	.L10
.L3:
	leal	1(%rdx), %ecx
	addl	%edx, %eax
	cmpl	%ecx, %edi
	je	.L1
	addl	%ecx, %eax
	leal	2(%rdx), %ecx
	cmpl	%ecx, %edi
	je	.L1
	addl	%ecx, %eax
	leal	3(%rdx), %ecx
	cmpl	%ecx, %edi
	je	.L1
	addl	%ecx, %eax
	leal	4(%rdx), %ecx
	cmpl	%ecx, %edi
	je	.L1
	addl	%ecx, %eax
	leal	5(%rdx), %ecx
	cmpl	%ecx, %edi
	je	.L1
	addl	%ecx, %eax
	leal	6(%rdx), %ecx
	cmpl	%ecx, %edi
	je	.L1
	addl	%ecx, %eax
	addl	$7, %edx
	leal	(%rax,%rdx), %ecx
	cmpl	%edx, %edi
	cmovne	%ecx, %eax
	ret
.L7:
	xorl	%eax, %eax
.L1:
	rep ret
.L10:
	rep ret
.L8:
	xorl	%edx, %edx
	xorl	%eax, %eax
	jmp	.L3
.LFE1:
	.size	_Z1fj, .-_Z1fj
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC1:
	.long	4
	.long	4
	.long	4
	.long	4
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
