global _ft_isprint

section .text

_ft_isprint:
	xor eax, eax

	cmp rdi, 7Eh
	jg false

	cmp rdi, 20h
	jl false

	inc rax

false:
	ret
