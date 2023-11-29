.MODEL SMALL
.STACK 100H
.DATA
    MSG1  DB "ENTER THE BINARY NUMBER: $"
    MSG2  DB "THE NUMBER OF 1'S IS: $"
    COUNT DB 0
.CODE
MAIN PROC
    ; OUTPUT THE MSG1
               MOV AX, @DATA
               MOV DS, AX
               LEA DX, MSG1
               MOV AH, 9
               INT 21H
    
    ; INPUT BINARY
               MOV AH, 1
               INT 21H
    BINARY:    
               CMP AL, 0DH
               JE  ENDPROGRAM
               CMP AL, 31H
               JE  INCREMENT
               JG  ENDPROGRAM
               CMP AL, 30H
               JE  NEXT_INPUT
               JL  ENDPROGRAM
    NEXT_INPUT:
               INT 21H
               JMP BINARY

    INCREMENT: 
               INC COUNT
               JMP NEXT_INPUT
    ; RETURN
    ENDPROGRAM:
    ; PRINT NEWILINE
               MOV AH, 2
               MOV DL, 0DH
               INT 21H
               MOV DL, 0AH
               INT 21H
    ; PRINT MSG3
               LEA DX, MSG2
               MOV AH, 9
               INT 21H
    ; PRINT COUNT
               MOV AH, 2
               MOV DL, COUNT
               ADD DL, '0'
               INT 21H
    ; RETURN
               MOV AH, 4CH
               INT 21H
MAIN ENDP
END MAIN