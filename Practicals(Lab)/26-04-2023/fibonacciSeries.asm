    ;GENERATE FINBONACCI SERIES FOR UPTO 15 NUMBERS
    
    ORG 100H;
    
    MOV AL, 00H; Load AL with 00H
    MOV SI, 500H; Point to offset 500H
    MOV [SI], AL;Store first number into memory
    INC SI; Point to next location
    ADD AL, 01H; Add 01 with AL
    MOV [SI], AL;     Store second number into memory
    MOV CX,[600H];   Take the limit of the sequence
    SUB CX, 0002H; Remove 02 from limit
L1 :MOV AL, [SI-1]; Take the last stored value into AL
    ADD AL,[SI]; Add current value with AL
    INC SI; Point to next location
    MOV [SI], AL;   Store AL content into memory
    LOOP L1;  Loop to L1 until counter becomes 0
    HLT ; Terminate program
