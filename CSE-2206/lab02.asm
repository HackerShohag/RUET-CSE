.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB "ENTER THE FIRST NUMBER: $"
    MSG2 DB 0DH,0AH,"ENTER THE SECOND NUMBER: $"
    MSG3 DB 0DH,0AH,"ENTER THE THIRD NUMBER: $"
    MSG4 DB 0DH,0AH,"THE GREATEST OF ALL IS: $"
    A    DB ?
    B    DB ?
    C    DB ?
    RS   DB ?
.CODE
MAIN PROC
          MOV AX, @DATA
          MOV DS, AX

    ; FIRST NUMBER INPUT
          LEA DX, MSG1
          MOV AH, 9
          INT 21H

          MOV AH, 1
          INT 21H
          MOV A, AL

    ; SECOND NUMBER INPUT
          LEA DX, MSG2
          MOV AH, 9
          INT 21H

          MOV AH, 1
          INT 21H
          MOV B, AL

    ; THIRD NUMBER INPUT
          LEA DX, MSG3
          MOV AH, 9
          INT 21H

          MOV AH, 1
          INT 21H
          MOV C, AL
          MOV RS, AL

    ; COMPARISON
          MOV AL, A
          CMP AL, B
          JG  COMP1
          MOV AL, B
          CMP AL, C
          JG  COMP2
          JMP EXIT

    COMP1:
          MOV AL, A
          CMP AL, C
          JG  A_G

    COMP2:
          MOV AL, B
          CMP AL, C
          JG  B_G
    
    A_G:  
          MOV AL, A
          MOV RS, AL
          JMP EXIT

    B_G:  
          MOV AL, B
          MOV RS, AL
          JMP EXIT

    EXIT: 
          LEA DX, MSG4
          MOV AH, 9
          INT 21H
          
          MOV AH, 2
          MOV DL, RS
          
          INT 21H
          MOV AH, 4CH
          INT 21H
MAIN ENDP
END MAIN