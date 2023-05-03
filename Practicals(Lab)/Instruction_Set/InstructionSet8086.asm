
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX,1234H;
MOV BX,2345H;

;Exchange contents of AX to BX and BX to AX
XCHG AX,BX;

;Input the port
MOV DX,0023H;
IN AL,DX;

;Output the port
MOV DX,0092H;
OUT DX,AX;

;Push to the stack 
MOV AX,1F2BH;
PUSH AX;

;Pop from the stack segment 
MOV AX,1C2BH;
PUSH AX;

MOV BX,302AH;
PUSH BX;

POP CX;

POP [12H];                                          
                                           

HLT
ret




