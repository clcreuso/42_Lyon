global _ft_isalpha

section .text

_ft_isalpha:
	xor eax, eax

	cmp rdi, 41h
	jl false

	cmp rdi, 7Ah
	jg false

	cmp rdi, 5Bh
	jl true

	cmp rdi, 60h
	jg true
	
	jmp false

true:
	inc rax

false:
	ret
