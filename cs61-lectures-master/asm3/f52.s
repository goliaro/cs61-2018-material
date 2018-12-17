	.file	"f52.cc"
	.text
	.globl	_Z1fP10four_wordsi
	.type	_Z1fP10four_wordsi, @function
_Z1fP10four_wordsi:
.LFB0:
	movslq	%esi, %rsi
	salq	$4, %rsi
	movl	(%rdi,%rsi), %eax
	ret
.LFE0:
	.size	_Z1fP10four_wordsi, .-_Z1fP10four_wordsi
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
