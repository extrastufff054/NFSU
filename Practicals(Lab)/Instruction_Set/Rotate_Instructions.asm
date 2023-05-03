;Rotate Instructions

MOV AX, 1000H;
MOV BX, 0100H;
MOV DX, 00E0H;
MOV CX, 000FH; 
MOV [7000H], 110FH;
MOV [6000H], 000DH;

;1) ROR : Rotate Right Without Carry
ROR AH,4;
ROR BH,2;

;2) ROL : Rotate Left Without Carry
ROL AL,4;
ROL BL,2;

;3) RCR : Rotate Right Through Carry
RCR AX,1;
RCR CX,2;

;4) RCL : Rotate Left Through Carry
RCL DX,2;
RCL BX,1;

