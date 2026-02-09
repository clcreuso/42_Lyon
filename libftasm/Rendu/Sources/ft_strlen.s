global _ft_strlen

section .text

_ft_strlen:
	mov rbx, rdi
	xor eax, eax

main_loop:
	cmp byte [rbx], 0
	je  return
	inc rax
	inc rbx
	jmp main_loop

return:
	ret
