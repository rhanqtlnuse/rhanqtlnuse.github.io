	.file	"test_sizeof_1.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "32-bit\0"
.LC1:
	.ascii "%d\12\0"
.LC2:
	.ascii "sizeof(struct SX) = %d\12\0"
	.align 8
.LC3:
	.ascii "    offsetof(SX::inner.b) = %llu\12\12\0"
	.align 8
.LC4:
	.ascii "sizeof(struct SX_flatted) = %d\12\0"
	.align 8
.LC5:
	.ascii "    offsetof(SX_flatted::b) = %llu\12\0"
	.align 8
.LC6:
	.ascii "    offsetof(SX_flatted::c) = %llu\12\0"
	.align 8
.LC7:
	.ascii "    offsetof(SX_flatted::d) = %llu\12\12\0"
.LC8:
	.ascii "sizeof(struct SX2) = %d\12\0"
	.align 8
.LC9:
	.ascii "    offsetof(SX2::inner.b) = %llu\12\0"
	.align 8
.LC10:
	.ascii "    offsetof(SX2::inner.c) = %llu\12\0"
.LC11:
	.ascii "    offsetof(SX2::d) = %llu\12\0"
.LC12:
	.ascii "    %p\12\0"
.LC13:
	.ascii "    %p\12\12\0"
	.align 8
.LC14:
	.ascii "sizeof(struct SX2_flatted) = %d\12\0"
	.align 8
.LC15:
	.ascii "    offsetof(SX2_flatted::b) = %llu\12\0"
	.align 8
.LC16:
	.ascii "    offsetof(SX2_flatted::c) = %llu\12\0"
	.align 8
.LC17:
	.ascii "    offsetof(SX2_flatted::d) = %llu\12\0"
.LC18:
	.ascii "sizeof(struct SX3) = %d\12\0"
	.align 8
.LC19:
	.ascii "    offsetof(SX3::inner.b) = %llu\12\0"
.LC20:
	.ascii "    offsetof(SX3::d) = %llu\12\12\0"
.LC21:
	.ascii "sizeof(struct SX4) = %d\12\0"
	.align 8
.LC22:
	.ascii "    offsetof(SX4::inner.b) = %llu\12\0"
.LC23:
	.ascii "sizeof(struct SX5) = %d\12\0"
	.align 8
.LC24:
	.ascii "    offsetof(SX5::inner.b) = %llu\12\0"
.LC25:
	.ascii "sizeof(struct SX6) = %d\12\0"
	.align 8
.LC26:
	.ascii "    offsetof(SX6::inner.b) = %llu\12\0"
.LC27:
	.ascii "sizeof(struct SX7) = %d\12\0"
	.align 8
.LC28:
	.ascii "    offsetof(SX7::inner.b) = %llu\12\0"
.LC29:
	.ascii "sizeof(struct SX8) = %d\12\0"
	.align 8
.LC30:
	.ascii "    offsetof(SX8::inner.c) = %llu\12\0"
.LC31:
	.ascii "    offsetof(SX8::d) = %llu\12\12\0"
.LC32:
	.ascii "sizeof(struct SX9) = %d\12\0"
	.align 8
.LC33:
	.ascii "    offsetof(SX9::inner.b) = %llu\12\0"
.LC34:
	.ascii "    offsetof(SX9::d) = %llu\12\12\0"
.LC35:
	.ascii "sizeof(struct SX10) = %d\12\0"
	.align 8
.LC36:
	.ascii "    offsetof(SX10::inner.b) = %llu\12\0"
	.align 8
.LC37:
	.ascii "    offsetof(SX10::inner.c) = %llu\12\0"
	.align 8
.LC38:
	.ascii "    offsetof(SX10::d) = %llu\12\12\0"
.LC39:
	.ascii "sizeof(struct SXX) = %d\12\0"
	.align 8
.LC40:
	.ascii "    offsetof(SXX::inner.b) = %llu\12\0"
	.align 8
.LC41:
	.ascii "    offsetof(SXX::inner.inner2.d) = %llu\12\0"
	.align 8
.LC42:
	.ascii "    offsetof(SXX::inner.inner2.e) = %llu\12\0"
.LC43:
	.ascii "    offsetof(SXX::f) = %llu\12\0"
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
	leaq	.LC0(%rip), %rcx
	call	puts
	movl	$12, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$4, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movl	$12, %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movl	$2, %edx
	leaq	.LC5(%rip), %rcx
	call	printf
	movl	$4, %edx
	leaq	.LC6(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC7(%rip), %rcx
	call	printf
	movl	$32, %edx
	leaq	.LC8(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC9(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC10(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC11(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC14(%rip), %rcx
	call	printf
	movl	$2, %edx
	leaq	.LC15(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC16(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC17(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	addq	$2, %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	printf
	leaq	-64(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rdx
	leaq	.LC13(%rip), %rcx
	call	printf
	movl	$12, %edx
	leaq	.LC18(%rip), %rcx
	call	printf
	movl	$2, %edx
	leaq	.LC19(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC20(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC21(%rip), %rcx
	call	printf
	movl	$2, %edx
	leaq	.LC22(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC23(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC24(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC25(%rip), %rcx
	call	printf
	movl	$9, %edx
	leaq	.LC26(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC27(%rip), %rcx
	call	printf
	movl	$10, %edx
	leaq	.LC28(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC29(%rip), %rcx
	call	printf
	movl	$12, %edx
	leaq	.LC30(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC31(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC32(%rip), %rcx
	call	printf
	movl	$4, %edx
	leaq	.LC33(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC34(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC35(%rip), %rcx
	call	printf
	movl	$4, %edx
	leaq	.LC36(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC37(%rip), %rcx
	call	printf
	movl	$16, %edx
	leaq	.LC38(%rip), %rcx
	call	printf
	movl	$40, %edx
	leaq	.LC39(%rip), %rcx
	call	printf
	movl	$8, %edx
	leaq	.LC40(%rip), %rcx
	call	printf
	movl	$24, %edx
	leaq	.LC41(%rip), %rcx
	call	printf
	movl	$28, %edx
	leaq	.LC42(%rip), %rcx
	call	printf
	movl	$32, %edx
	leaq	.LC43(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
