;Q1 : Write the program to count all 1's
;Q2 : To perform ADD of 2x2 matrix
;Q3 : To perform the transpose of 2x2 matrix
;Q4 : Write an assembly language program to find whether a given byte is available in the given sequence or not. If it is available write FF in R3. Otherwise write 00 in R3.

org 00H
MOV R0, #20H
MOV R2, #30H
MOV R1, #40H
MOV R3,	#04H
LOOP1: MOV A, @R0
		MOV B,@R2
		ADD A, B
		MOV @R1, A
		DEC R3
		INC R0
		INC R1
		INC R2
		CJNE R3, #00H, LOOP1
END
