code section
start:
	push ebp
	mov ebp,esp
	call getchar
	add eax,1
	push eax
	call putchar
	mov esp,ebp
	pop ebp
	mov eax,0
	ret