	.globl times
times:
	mov $0, %eax

loop:
	cmp $0, %esi
	jle endwhile 
	add %edi, %eax
	dec %esi
	jmp loop

endwhile:
	ret
	

