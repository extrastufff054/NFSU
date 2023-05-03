;store first element of array in AL 
;Compare AL with 2nd element array[2]
;if second is larger modify AL=array[2] otherwise compare with next element 

;To initialize an array of 16 nos. with regular interval of 10
;Define data segment and offset on which you want to define the data
;
 ORG 100H
        MOV AX, 6000H;
        MOV DS, AX; 
        MOV AX, 30H;   
        MOV BX, 1000H;
        MOV CX, 0A4H;
        
ARRAY : MOV [BX], AX;
        ADD AX, 50D;
        INC BX;
        LOOP ARRAY;
        
        MOV BX, 1000H;
        MOV AX, [BX];
        MOV CX, 1FH;
       
L1    : CMP AX,[BX+2];
        JNC L2;
        MOV AX,[BX+2];

L2    : INC BX;
        LOOP L1;
        MOV [0FFFH], AX;

HLT;        
