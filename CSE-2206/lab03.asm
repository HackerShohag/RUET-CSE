.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
	; DISPLAY CHARACTER '?'
	           MOV AH, 2
	           MOV DL, '?'
	           INT 21H
	; DISPLAY NEW LINE
	           MOV AH, 2
	           MOV DL, 0DH
	           INT 21H
	           MOV DL, 0AH
	           INT 21H
	; READ TWO CHARACTER AND SAVE IN BL, AL
	           MOV AH, 1
	           INT 21H
	           MOV BL, AL
	           INT 21H
	           MOV CL, AL
	; DISPLAY NEW LINE
	           MOV AH, 2
	           MOV DL, 0DH
	           INT 21H
	           MOV DL, 0AH
	           INT 21H
	; COMPARE TWO CHARACTER
	           CMP BL, CL
	           JG  GREATER
	           JE  EQUAL
	           JL  SMALLER
	; IF AL > BL
	GREATER:   
	           MOV AH, 2
	           MOV DL, CL
	           INT 21H
	           MOV DL, BL
	           INT 21H
	           JMP ENDPROGRAM
	; IF AL = BL
	EQUAL:     
	           MOV AH, 2
	           MOV DL, CL
	           INT 21H
	           INT 21H
	           JMP ENDPROGRAM
	
	; IF AL < BL
	SMALLER:   
	           MOV AH, 2
	           MOV DL, BL
	           INT 21H
	           MOV DL, CL
	           INT 21H
	           JMP ENDPROGRAM
	ENDPROGRAM:
	           MOV AH, 4CH
	           INT 21H
MAIN ENDP
END MAIN