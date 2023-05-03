;FIND OUT THE AVG OF N NUMBERS, WHERE N =42+10=52 
;
    MOV SI,042;  ----------------------- SI<-500
    MOV DI,052; ------------------------ DI<-600
    MOV AX,0000H; ---------------------- AX=0000
    MOV CL,[SI]; ----------------------- CL<-[SI]  load the block size(value of n)
    MOV BL,CL;  ------------------------ BL<-CL    Store n into BL
    INC SI;      ----------------------- SI=SI+1
 L1:ADD AL,[SI]; ----------------------- AL=AL+[SI]
    ADC AH,00H;  ----------------------- AH=AH+00+CY
    INC SI;  --------------------------- SI=SI+1
    DEC CL;  --------------------------- CL=CL-1
    JNZ L1; ---------------------------- JMP IF ZF=0
    DIV BL;  --------------------------- AX=AX/BL
    MOV [DI], AX; ---------------------- [DI]<-AX
    HLT;  ------------------------------ STOP
 
