.MODEL SMALL
.STACK 100H
.DATA
    MSG1    DB 'ENTER THE NUMBER: $'
    PRIME   DB 'THE NUMBER IS PRIME.$'
    N_PRIME DB 'THE NUMBER IS NOT PRIME.$'
    NUM     DW ?
.CODE
                   INCLUDE PROCS/INDEC.ASM
                   INCLUDE PROCS/OUTDEC.ASM

MAIN PROC
                   MOV     AX, @DATA
                   MOV     DS, AX


                   LEA     DX, MSG1
                   MOV     AH, 9H
                   INT     21H
                   CALL    INDEC
                   MOV     CX, AX
                   MOV     NUM, 2
    PRIME_LOOP:    
                   XOR     DX, DX
                   MOV     AX, CX
                   MOV     BX, NUM
                   DIV     BX

                   CMP     DX, 0
                   JE      N_PRIME_OUTPUT
                   INC     NUM

                   MOV     BX, NUM
                   CMP     BX, CX
                   JE      PRIME_OUTPUT
                   JMP     PRIME_LOOP
                
    N_PRIME_OUTPUT:
                   LEA     DX, N_PRIME
                   MOV     AH, 9
                   INT     21H
                   JMP     EXITPROGRAM
                
    PRIME_OUTPUT:  
                   LEA     DX, PRIME
                   MOV     AH, 9
                   INT     21H
                   JMP     EXITPROGRAM
    EXITPROGRAM:   
                   MOV     AH, 4CH
                   INT     21H
MAIN ENDP
END MAIN