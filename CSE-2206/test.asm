.MODEL SMALL
.STACK 100H
.DATA
    MSG1    DB 'ENTER A NUMBER: $'
    PRIME   DB 'THE NUMBER IS PRIME.$'
    N_PRIME DB 'THE NUMBER IS NOT PRIME.$'
    NUM     DW 0
.CODE
    ; Function to read a number from the user
                          INCLUDE PROCS/INDEC.ASM
    ; Function to check if a number is prime
ISPRIME PROC
                          MOV     BX, 2                    ; Start checking divisibility from 2
    CHECK_DIVISIBILITY:   
                          MOV     DX, 0
                          DIV     BX                       ; Divide AX by BX, quotient in AX, remainder in DX

    ; If the remainder is 0, the number is not prime
                          CMP     DX, 0
                          JE      NOT_PRIME

    ; If BX reaches the square root of the number, the number is prime
                          MOV     AX, CX
                          CALL    SQUARE_ROOT
                          CMP     BX, AX
                          JG      ISPRIME

    ; Otherwise, continue checking divisibility
                          INC     BX
                          JMP     CHECK_DIVISIBILITY

    NOT_PRIME:            
                          MOV     AL, 0                    ; Indicate that the number is not prime
                          RET
ISPRIME ENDP

SQUARE_ROOT PROC
    ; Calculate the square root of AX and store the result in BX
                          MOV     BX, AX
                          XOR     CX, CX
    CALCULATE_SQUARE_ROOT:
                          SUB     BX, CX
                          JLE     END_SQUARE_ROOT
                          ADD     CX, 1
                          ADD     BX, CX
                          JMP     CALCULATE_SQUARE_ROOT
    END_SQUARE_ROOT:      
                          MOV     BX, CX
                          RET
SQUARE_ROOT ENDP

MAIN PROC
    ; DISPLAY MSG1
                          MOV     AX, @DATA
                          MOV     DS, AX

    ; CALL INDEC FUNCTION TO READ A NUMBER
                          CALL    INDEC
                          MOV     CX, NUM

    ; Check if the entered number is prime
                          MOV     AX, CX
                          CALL    ISPRIME

    ; Display the result
                          CMP     AL, 1
                          JE      PRIME_OUTPUT
                          JMP     N_PRIME_OUTPUT

    PRIME_OUTPUT:         
                          LEA     DX, PRIME
                          MOV     AH, 9
                          INT     21H
                          JMP     EXIT_PROGRAM

    N_PRIME_OUTPUT:       
                          LEA     DX, N_PRIME
                          MOV     AH, 9
                          INT     21H
                          JMP     EXIT_PROGRAM

    EXIT_PROGRAM:         
                          MOV     AH, 4CH
                          INT     21H

MAIN ENDP
END MAIN