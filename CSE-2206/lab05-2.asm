.MODEL SMALL
.STACK 100H
.DATA
    MSG1   DB 'ENTER THE NUMBER: $'
    ODD    DB 'THE NUMBER IS ODD.$'
    EVEN_N DB 'THE NUMBER IS EVEN.$'
.CODE
MAIN PROC
    ; DISPLAY MSG1
                MOV AX, @DATA
                MOV DS, AX
                LEA DX, MSG1
                MOV AH, 9
                INT 21H
    
    ; TAKE INPUT
                MOV AH, 1
                INT 21H
    NUMBER:     
                CMP AL, 20H
                JE  CHECK_BIT
                
                CMP AL, 30H
                JE  NEXT_INPUT
                JL  CHECK_BIT
                CMP AL, 39H
                JL  NEXT_INPUT
                JG  CHECK_BIT
    
    NEXT_INPUT: 
                MOV CL, AL
                INT 21H
                JMP NUMBER
    
    CHECK_BIT:  
                XOR DX, DX
                MOV AL, CL
                MOV BX, 2D
                DIV BX
                ADD DX, '0'
                CMP DX, 30H
                JE  EVEN_OUTPUT
                CMP DX, 31H
                JE  ODD_OUTPUT
                
    EVEN_OUTPUT:
                LEA DX, EVEN_N
                MOV AH, 9
                INT 21H
                JMP EXITPROGRAM
                
    ODD_OUTPUT: 
                LEA DX, ODD
                MOV AH, 9
                INT 21H
                JMP EXITPROGRAM
    EXITPROGRAM:
                MOV AH, 4CH
                INT 21H
MAIN ENDP
END MAIN