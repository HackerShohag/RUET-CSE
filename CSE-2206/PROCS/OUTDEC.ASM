OUTDEC PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    MOV BX, 10

    OR AX, AX
    JGE @END_IF1

    PUSH AX
    MOV DL, '-'
    MOV AH, 2
    INT 21H
    POP AX
    NEG AX

    @END_IF1:
        XOR CX, CX
        MOV BX, 10D

    @REPEAT1:
        XOR DX, DX
        DIV BX
        PUSH DX
        INC CX
        
        OR AX, AX
        JNE @REPEAT1

        MOV AH, 2

    @PRINT_LOOP:
        POP DX
        OR DL, 30H
        INT 21H
        LOOP @PRINT_LOOP

    POP DX
    POP CX
    POP BX
    POP AX
    RET
OUTDEC ENDP