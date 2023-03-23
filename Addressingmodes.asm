
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

;Immediate addressing mode  
MOV BX,0010H;
MOV DX,0100H;

;Register addressing mode
MOV BX,DX;   
MOV AX,110FH;
MOV AX,BX;
;Direct addressing mode
MOV AL,[07H];
MOV DL,[2400H];
;Register indirect addressing mode 
MOV AX,[BX];  Physical address = [DS]*10+[BX];

;Based relative addressing mode 
MOV AX,[BP]+5;
MOV BX,[BP+6H];
;Based indexed relative addressing mode
MOV SI,1234H;
MOV DI,0092H;
MOV AX,[BX][SI]+5H;
;Indexed relative addressing mode 
MOV DX,[DI]+5H;               


ret




