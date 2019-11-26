;Write a program to subtract two 32 bit numbers
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	DCD 0x10001000
	DCD Reset_Handler
	
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=NUM1
	LDR R1,=NUM2
	LDR R2,=DST

	LDR R4,[R0]
	LDR R5,[R1]
	SUB R6,R4,R5
	STR R6,[R2]
STOP
	B STOP
NUM1 DCD 0x00007658	
NUM2 DCD 0x000037A6	
	AREA mydata, DATA,READWRITE
DST DCD 0,0,0,0
	END