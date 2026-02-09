global _ft_bzero

section .text

_ft_bzero:
	cld
	xor eax, eax

	mov rcx, rsi
	rep stosb

return:
	ret
