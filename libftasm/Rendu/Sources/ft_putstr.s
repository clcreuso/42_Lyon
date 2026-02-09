global _ft_putstr
extern _ft_strlen

section .text

_ft_putstr:
	xor eax, eax
	test rdi, rdi
	jz return

	call _ft_strlen

	mov rdx, rax
	mov rax, 0x2000004
	mov rsi, rdi
	mov rdi, 0x1
	syscall

return:
	ret
