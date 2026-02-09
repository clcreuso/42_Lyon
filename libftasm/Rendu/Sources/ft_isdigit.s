global _ft_isdigit

section .text

_ft_isdigit:
	xor eax, eax

	cmp rdi, 39h
	jg false

	cmp rdi, 30h
	jl false

	inc rax

false:
	ret
