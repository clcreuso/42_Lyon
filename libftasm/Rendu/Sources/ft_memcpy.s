global _ft_memcpy

section .text

_ft_memcpy:
	cld
	
	mov rax, rdi
	mov rcx, rdx

	rep movsb

return:
	ret
