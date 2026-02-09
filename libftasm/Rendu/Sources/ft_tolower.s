global _ft_tolower
extern _ft_isalpha

section .text

_ft_tolower:
	cmp rdi, 41h
	jl return
	cmp rdi, 5Ah
	jg return

	xor rdi, 20h

return:
	mov rax, rdi
	ret
