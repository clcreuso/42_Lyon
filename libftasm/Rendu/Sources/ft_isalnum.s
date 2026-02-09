global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit

section .text

_ft_isalnum:
	call _ft_isalpha

	test rax, rax
	jnz return

	call _ft_isdigit

return:
	ret
