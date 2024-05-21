.MODEL SMALL
.STACK 100H
.DATA
      STR1 DB "THIS IS A SAMPLE STRING$"
      STR2 DB "VOWELS:"
      LEN  DW ?, '$'
      VOW  DB 0,'$'

.CODE
MAIN PROC
            MOV  AX, @DATA
            MOV  DS, AX

            LEA  DX, STR1
            MOV  AH, 09H
            INT  21H

      ; NEW LINE
            MOV  AH, 02H
            MOV  DL, 0DH
            INT  21H
            MOV  DL, 0AH
            INT  21H

            MOV  LEN, 23

      CNT:  
            MOV  AX, LEN
            CMP  AX, 0
            JE   VCP
        
            LEA  SI, STR1
            ADD  SI, AX
            MOV  DL, [SI-1]

            DEC  LEN

            MOV  AH, 2H
            INT  21H
            LOOP CNT

      VCP:  
            MOV  LEN, 23
            JMP  VC

      VC:   
            MOV  AX, LEN
            CMP  AX, 0
            JE   EXIT

            DEC  LEN

            LEA  SI, STR1
            ADD  SI, AX
            MOV  BL, [SI-1]

      ; COMPARING WITH THE VOWELS
            CMP  BL, 'A'
            JE   VOWEL

            CMP  BL, 'E'
            JE   VOWEL

            CMP  BL, 'I'
            JE   VOWEL

            CMP  BL, 'O'
            JE   VOWEL

            CMP  BL, 'U'
            JE   VOWEL

            CMP  BL, 'a'
            JE   VOWEL

            CMP  BL, 'e'
            JE   VOWEL

            CMP  BL, 'i'
            JE   VOWEL

            CMP  BL, 'o'
            JE   VOWEL

            CMP  BL, 'u'
            JE   VOWEL
        
            LOOP VC

      VOWEL:
            INC  VOW
            JMP  VC
    
      EXIT: 
            MOV  AH, 2
            MOV  DL, 0DH
            INT  21H

            MOV  DL, 0AH
            INT  21H

            LEA  DX, STR2
            MOV  AH, 9
            INT  21H

            MOV  AH, 2
            MOV  DL, VOW
            ADD  DL, '0'
            INT  21H
          
            MOV  AH, 4CH
            INT  21H
MAIN ENDP
END MAIN