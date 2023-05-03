;Verify register addressing modes and immediate addressing mode

org 100h
MOV AX,0100H;
MOV [5000H],0100H;
MOV BX,0500H;

HLT
ret




