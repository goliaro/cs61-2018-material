	.file	"f65.cc"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Hello."
.LC1:
	.string	"This is Dr. Evil."
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"I am calling from inside the house."
	.align 8
.LC3:
	.string	"I can count: %d %d %d %d %d %d %d %d\n"
	.align 8
.LC4:
	.string	"I hate you, %s. Printed %d chars.\n"
	.text
	.globl	_Z1fiPKc
	.type	_Z1fiPKc, @function
_Z1fiPKc:
.LFB30:
	pushq	%rbp
	pushq	%rbx
	subq	$8, %rsp
	movl	%edi, %ebx
	movq	%rsi, %rbp
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leal	1(%rbx), %ecx
	leal	7(%rbx), %eax
	pushq	%rax
	leal	6(%rbx), %eax
	pushq	%rax
	leal	5(%rbx), %eax
	pushq	%rax
	leal	4(%rbx), %eax
	pushq	%rax
	leal	3(%rbx), %r9d
	leal	2(%rbx), %r8d
	movl	%ebx, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$32, %rsp
	movl	%eax, %ecx
	movq	%rbp, %rdx
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	ret
.LFE30:
	.size	_Z1fiPKc, .-_Z1fiPKc
	.globl	main
	.type	main, @function
main:
.LFB31:
	subq	$8, %rsp
	movq	(%rsi), %rsi
	call	_Z1fiPKc
	movl	$0, %eax
	addq	$8, %rsp
	ret
.LFE31:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
