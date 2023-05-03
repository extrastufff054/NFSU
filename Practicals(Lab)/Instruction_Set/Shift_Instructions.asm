;Shift Instructions

MOV AX, 1000H;
MOV BX, 0100H;
MOV DX, 00E0H;
MOV CX, 000FH; 
MOV [7000H], 110FH;
MOV [6000H], 000DH;

;1) SHL/SAL : Shift Logical/Arithmetic Left
SHL AX,2;
SAL DX,1;

;2) SHR : Shift Logical Right
SHR AX,1;
SHR DX,2;  

;3) SAR : Shift Arithmetic Right
SAR BX,4;
SAR CX,4;

HLT

RET
