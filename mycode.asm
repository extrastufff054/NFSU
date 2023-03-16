
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX, 0FFF0H; add your code here //VALUE OF AX
MOV CX, 0001H;        //VALUE OF CX
MOV [1234H], AX;    //ADDRESS WHERE VALUE IS STORED
MOV [1236H], CX;
ADD AX,CX;
HLT

ret

