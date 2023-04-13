ORG 100H

;Arithmetic Instructions

MOV AX,0101H;
MOV BX,000FH;  
MOV CX,0FFFH;

;1)ADD => 
ADD AX,0001H;       Immediate Addresing Mode 
ADD AX,BX;          Register Direct Addressing Mode
ADD AX, [SI];       Register Indirect Addressing Mode
ADD AX, [1000H];    Direct Addressing Mode
ADD [5000H],0110H;  Immediate Addressing Mode

;2)ADC =>
ADC AX,0010H;       Immediate Addresing Mode 
ADC AX,BX;          Register Direct Addressing Mode
ADC AX, [SI];       Register Indirect Addressing Mode
ADC AX, [6000H];    Direct Addressing Mode
ADC [5000H],0110H;  Immediate Addressing Mode 

;3)SUB =>
SUB AX,0001H;       Immediate Addresing Mode 
SUB AX,BX;          Register Direct Addressing Mode
SUB AX, [SI];       Register Indirect Addressing Mode
SUB AX, [1000H];    Direct Addressing Mode
SUB [5000H],0110H;  Immediate Addressing Mode

;4)SBB =>
SBB AX,0001H;       Immediate Addresing Mode 
SBB AX,BX;          Register Direct Addressing Mode
SBB AX, [SI];       Register Indirect Addressing Mode
SBB AX, [1000H];    Direct Addressing Mode
SBB [5000H],0110H;  Immediate Addressing Mode

;5)MUL(8 bit) =>
MUL AL;             Immediate Addresing Mode 
   
;6)MUL(16 bit) =>
MUL AX;             Immediate Addresing Mode 

;7)IMUL (Signed Multiplication) =>
IMUL CX;            

;8)DIV(8 bit) =>
DIV BL;           Immediate Addresing Mode 

;9)DIV(16 bit) =>
DIV CX;           Immediate Addresing Mode 


;10)INC =>
INC AX;

;11)DEC =>
DEC BX;

;12)NEG =>
NEG AL;
NEG BL;


HLT
RET
