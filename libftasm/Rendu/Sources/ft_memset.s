global _ft_memset

section .text

_ft_memset:
	cld
	push rdi

	mov rax, rsi
	mov rcx, rdx

	rep stosb

return:
	pop rax
	ret
