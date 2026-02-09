global _ft_putchar

section .text

_ft_putchar:
	push rdx
	push rsi
	push rdi

	mov rax, 0x2000004
	mov rdi, 0x1
	mov rsi, rsp
	mov rdx, 0x1
	syscall

	pop rdi
	pop rsi
	pop rdx
	ret
