	.file	"test_sizeof_2.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "sizeof(struct SX2) = %d\12\0"
	.align 8
.LC1:
	.ascii "    offsetof(SX2::inner.b) = %llu\12\0"
	.align 8
.LC2:
	.ascii "    offsetof(SX2::inner.c) = %llu\12\0"
.LC3:
	.ascii "    offsetof(SX2::d) = %llu\12\0"
.LC4:
	.ascii "    %p\12\0"
.LC5:
	.ascii "    %p\12\12\0"
	.align 8
.LC6:
	.ascii "sizeof(struct SX2_flatted) = %d\12\0"
	.align 8
.LC7:
	.ascii "    offsetof(SX2_flatted::b) = %llu\12\0"
	.align 8
.LC8:
	.ascii "    offsetof(SX2_flatted::c) = %llu\12\0"
	.align 8
.LC9:
	.ascii "    offsetof(SX2_flatted::d) = %llu\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main

	movl	$32, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC3(%rip), %rcx
	call	printf

	leaq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rcx
	call	printf

	# 
	movl	$24, %edx
	leaq	.LC6(%rip), %rcx
	call	printf
	movl	$2, %edx
	leaq	.LC7(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC8(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC9(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	addq	$2, %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdx
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
