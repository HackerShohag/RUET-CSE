section .data
	hello db 42

section .text
	global main

main:
	mov eax,4
	mov ebx,1
	mov ecx,hello
	int 80h

	mov eax,1
	mov ebx,1
	int 80h
