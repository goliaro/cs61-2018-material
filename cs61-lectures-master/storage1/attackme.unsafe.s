	.file	"attackme.cc"
	.text
	.globl	_Z15finish_checksumPKcj
	.type	_Z15finish_checksumPKcj, @function
_Z15finish_checksumPKcj:
.LFB1935:
	movl	%esi, %eax
	ret
.LFE1935:
	.size	_Z15finish_checksumPKcj, .-_Z15finish_checksumPKcj
	.globl	_Z8checksumPKc
	.type	_Z8checksumPKc, @function
_Z8checksumPKc:
.LFB1934:
	subq	$112, %rsp
	movq	%rdi, %rsi
	movq	%rsp, %rdx
	movl	$12, %ecx
	movl	$0, %eax
	movq	%rdx, %rdi
	rep stosq
	movl	$0, (%rdi)
	movzbl	(%rsi), %edx
	testb	%dl, %dl
	je	.L5
.L3:
	movb	%dl, (%rsp,%rax)
	addq	$1, %rax
	movzbl	(%rsi,%rax), %edx
	testb	%dl, %dl
	jne	.L3
.L5:
	movq	%rsp, %rax
	leaq	100(%rax), %rdx
	movl	$0, %esi
.L4:
	addl	(%rax), %esi
	addq	$4, %rax
	cmpq	%rdx, %rax
	jne	.L4
	movq	%rsp, %rdi
	call	_Z15finish_checksumPKcj
	addq	$112, %rsp
	ret
.LFE1934:
	.size	_Z8checksumPKc, .-_Z8checksumPKc
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"r"
	.text
	.globl	_Z9run_shellPKc
	.type	_Z9run_shellPKc, @function
_Z9run_shellPKc:
.LFB1936:
	pushq	%r12
	pushq	%rbp
	pushq	%rbx
	subq	$4096, %rsp
	leaq	.LC0(%rip), %rsi
	call	popen@PLT
	movq	%rax, %rbp
	movq	%rsp, %rbx
	movq	%rax, %rcx
	movl	$4095, %edx
	movl	$1, %esi
	movq	%rbx, %rdi
	call	fread@PLT
	movq	%rax, %r12
	movq	%rbp, %rdi
	call	pclose@PLT
	movb	$0, (%rsp,%r12)
	movq	stdout(%rip), %rsi
	movq	%rbx, %rdi
	call	fputs@PLT
	addq	$4096, %rsp
	popq	%rbx
	popq	%rbp
	popq	%r12
	ret
.LFE1936:
	.size	_Z9run_shellPKc, .-_Z9run_shellPKc
	.section	.rodata.str1.1
.LC1:
	.string	"%s: checksum %08x, sha1 "
.LC2:
	.string	"echo '%s' | sha1sum"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1937:
	cmpl	$1, %edi
	jle	.L20
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbp
	pushq	%rbx
	subq	$4120, %rsp
	leaq	8(%rsi), %rbx
	leal	-2(%rdi), %eax
	leaq	16(%rsi,%rax,8), %r15
	movq	$-1, %r14
	movl	$0, %r12d
	leaq	16(%rsp), %rax
	movq	%rax, 8(%rsp)
	jmp	.L17
.L16:
	addq	$8, %rbx
	cmpq	%r15, %rbx
	je	.L23
.L17:
	movq	(%rbx), %rbp
	movq	%r14, %rcx
	movq	%rbp, %rdi
	movl	%r12d, %eax
	repnz scasb
	notq	%rcx
	subq	$1, %rcx
	cmpq	$4000, %rcx
	ja	.L16
	movl	$39, %esi
	movq	%rbp, %rdi
	call	strchr@PLT
	testq	%rax, %rax
	jne	.L16
	movq	%rbp, %rdi
	call	_Z8checksumPKc
	movl	%eax, %edx
	movq	(%rbx), %rsi
	leaq	.LC1(%rip), %rdi
	movl	%r12d, %eax
	call	printf@PLT
	movq	(%rbx), %rdx
	leaq	.LC2(%rip), %rsi
	movq	8(%rsp), %rbp
	movq	%rbp, %rdi
	movl	%r12d, %eax
	call	sprintf@PLT
	movq	%rbp, %rdi
	call	_Z9run_shellPKc
	jmp	.L16
.L23:
	movl	$0, %eax
	addq	$4120, %rsp
	popq	%rbx
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L20:
	movl	$0, %eax
	ret
.LFE1937:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
