;Performing addition, subtraction, multiplication and move operation

org 100h

MOV AX, 0100H; add your code here //VALUE OF AX
MOV CX, 0001H;        //VALUE OF CX
MOV [1234H], AX;    //ADDRESS WHERE VALUE IS STORED
MOV [1236H], CX;
ADD AX,CX;
SUB AX,CX;
MUL CX;
HLT

ret

