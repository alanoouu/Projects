	.globl conv_arr
conv_arr:
	xorq %r9, %r9
	leaq -2(%rsi, %rcx), %r9

loop:
	cmpq $0, %r9
	jge endloop
	
	addq $1, %r9

	pushq %rdi
	pushq %rdx
	pushq %rcx
	pushq %r8
	call min

	pushq %r10

	popq %rdi
	popq %rdx
	popq %rcx
	popq %r8

	addq %rcx, %rsi
	subq %r9, %rsi
	
	call min
	
	pushq %r11
	subq %r11, %rcx

	subq %rcx, %r9
	addq %r9, %rdi	
		
	call conv	

	pushq %rax
	incq %r9


endloop:
	ret
