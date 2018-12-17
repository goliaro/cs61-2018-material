	.file	"fun12.cc"
	.text
	.globl	_Z3funPKc
	.type	_Z3funPKc, @function
_Z3funPKc:
.LFB27:
	xorl	%eax, %eax
	orq	$-1, %rcx
	movq	%rdi, %rsi
	repnz scasb
	xorl	%eax, %eax
	movq	%rcx, %rdx
	notq	%rdx
	movq	%rdx, %rcx
	decq	%rcx
	movslq	%ecx, %rdx
	addq	%rsi, %rdx
.L3:
	movb	(%rsi,%rax), %dil
	movl	%eax, %r8d
	testb	%dil, %dil
	je	.L2
	leaq	1(%rax), %r9
	notq	%rax
	cmpb	(%rdx,%rax), %dil
	jne	.L2
	movq	%r9, %rax
	jmp	.L3
.L2:
	cmpl	$4, %ecx
	setle	%al
	cmpl	%ecx, %r8d
	setne	%dl
	orl	%edx, %eax
	movzbl	%al, %eax
	ret
.LFE27:
	.size	_Z3funPKc, .-_Z3funPKc
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
