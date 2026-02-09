global _ft_isascii

section .text

_ft_isascii:
	xor eax, eax

	cmp rdi, 7Fh
	jg false

	cmp rdi, 00h
	jl false

	inc rax

false:
	ret
