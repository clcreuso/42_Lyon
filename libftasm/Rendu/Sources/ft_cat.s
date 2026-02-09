%define BUFFER 1024

global _ft_cat
	
section .text

_ft_cat:
	mov rbx, rdi

init_stackframe:
	enter 0, 0

init_loop:
	sub rsp, BUFFER
	mov rsi, rsp

read_buffer:
	mov rax, 0x2000003
	mov rdi, rbx
	mov rdx, BUFFER
	syscall
	jc reset_stackframe

save_size_read:
	push rax
	push rax

write_buffer:
	mov rax, 0x2000004
	mov rdi, 0x1
	pop rdx
	syscall

stop_cat:
	pop rax
	test rax, rax
	jnz read_buffer

reset_stackframe:
	leave

return:
	ret
