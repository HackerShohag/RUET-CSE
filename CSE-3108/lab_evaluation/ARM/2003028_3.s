mov R1, #0 ;
mov R2, #10 ;
while 
	CMP R1, R2 ;
	BEQ done ;
	ADD R1, R1, #5 ;
	B while ;
done STOP ;
	end
