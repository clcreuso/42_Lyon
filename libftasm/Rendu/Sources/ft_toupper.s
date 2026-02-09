global _ft_toupper
extern _ft_isalpha

section .text

_ft_toupper:
	cmp rdi, 61h
	jl return
	cmp rdi, 7Ah
	jg return

	and rdi, 5Fh

return:
	mov rax, rdi
	ret
