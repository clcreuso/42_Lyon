global _ft_puts
extern _ft_putchar
extern _ft_putstr

section .text

_ft_puts:
	xor eax, eax

	test rdi, rdi
	jz return
	call _ft_putstr

	mov rdi, 0Ah
	call _ft_putchar

return:
	ret
