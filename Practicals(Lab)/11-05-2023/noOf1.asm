; Write a program that find the number of 1's in a byte (i.e in the binary equivalent of a number)

MOV CX, 8 ;initialize loop counter to 8
MOV BL, byte_to_count ;load byte to count into BL
MOV AH, 0 ;initialize count to 0
LOOP_START:
    SHR BL, 1 ;shift right to check each bit
    JC ADD_COUNT ;if carry flag is set, add to count
    LOOP LOOP_START ;continue looping until all bits checked
ADD_COUNT:
    INC AH ;increment count
    LOOP LOOP_START ;continue looping until all bits have been checked

byte_to_count EQU 0A5h ;define byte to count as a constant

RET ;return from the program
