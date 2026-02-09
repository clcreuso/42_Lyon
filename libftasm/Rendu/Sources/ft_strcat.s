global _ft_strcat
extern _ft_putchar

section .text

_ft_strcat:
	xor eax, eax
	xor rcx, rcx
	not rcx
	push rdi

	repne scasb
	dec rdi

main_loop:
	movsb
	cmp byte [rsi], 0
	jne main_loop

return:
	pop rax
	ret