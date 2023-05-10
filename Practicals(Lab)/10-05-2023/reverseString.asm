Write a program to reverse the given string and store at the same location

ORG 100H
   
.DATA

ARRAY1 DB 01H,02H,03H,04H,05H,06H,07H,08H,09H,0AH,0BH,0CH,0DH,0EH,0FH;

.CODE

    MOV SI, OFFSET ARRAY1;
    MOV CL, 0FH;
    MOV CH, 00H;
    MOV DI, SI;
    MOV DI, 0EH;
    
L1 :MOV AL,[SI];
    MOV BL,[DI];
    XCHG [SI],BL;
    XCHG [DI],AL;
    INC SI;
    DEC DI;
    INC CH;
    DEC CL;
    CMP CL,CH;
    JG L1;
    .EXIT 
    
    END