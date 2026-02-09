global _ft_strdup

section .text
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
	xor eax, eax
	test rdi, rdi
	jz return

init_stackframe:
	enter 0, 0

size_allocation:
	call _ft_strlen
	inc rax
	push rax

memory_allocation:
	push rdi
	mov rdi, rax
	call _malloc

string_duplication:
	pop rsi
	pop rdx
	mov rdi, rax
	call _ft_memcpy

reset_stackframe:
	leave

return:
	ret
