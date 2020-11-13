
	.globl	lsearch_2

# var map
# 	%rdx - int target
# 	%r9d - int tmp
# 	%rcx / %r8d - int i
# 	%rax - int *A
# 	%rsi - int n
# 	%rdi - (int n) - 1
	
lsearch_2:
	testl	%esi, %esi		#if (n <= 0){
	jle	loop
	movslq	%esi, %rax
	movl	$1, %ecx		#i = 1;
	leaq	-4(%rdi,%rax,4), %rax	
	movl	(%rax), %r9d		#tmp = A[n-1];
	movl	%edx, (%rax)		#A[n-1] = target;
loop:
	movl	%ecx, %r8d		# i = i;		
	addq	$1, %rcx		#i = i + 1
	cmpl	%edx, -4(%rdi,%rcx,4)	#while (A[i] != target){
	jne	endloop
	movl	%r9d, (%rax)		#A[n-1] = tmp;
	leal	-1(%rsi), %eax		#point *A to A[n-1]
	cmpl	%r8d, %eax		#if (i < A*){
	jg	endif			
	cmpl	%r9d, %edx		#if (tmp == target){
	jne	endloop
	rep ret

endif:
	movl	%r8d, %eax		
	ret				#}
endloop:
	movl	$-1, %eax		#return -1;
	ret				#}

