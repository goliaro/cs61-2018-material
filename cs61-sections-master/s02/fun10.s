	.file	"fun10.cc"
	.text
	.globl	_Z3funPKc
	.type	_Z3funPKc, @function
_Z3funPKc:
.LFB19:
	xorl	%edx, %edx
	subq	$8, %rsp
	xorl	%esi, %esi
	call	strtol@PLT
	movl	%eax, %ecx
	movb	$1, %dl
	shrl	$8, %ecx
	je	.L2
	leal	-1(%rax), %edx
	testl	%eax, %edx
	setne	%dl
.L2:
	movzbl	%dl, %eax
	popq	%rdx
	ret
.LFE19:
	.size	_Z3funPKc, .-_Z3funPKc
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
