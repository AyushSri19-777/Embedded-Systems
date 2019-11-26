;Write a program to add two 128 bit numbers stored in code segment and store the result in data segment.
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
	MOV R3,#04
	
UP 	LDR R4,[R0],#4
	LDR R5,[R1],#4
	ADCS R6,R4,R5
	STR R6,[R2],#04
	SUB R3,#01
	TEQ R3,#00
	BNE UP
STOP
	B STOP
NUM1 DCD 0x00000008,0x0000000A,0x00000005,0x00000007	
NUM2 DCD 0x00000006,0x00000007,0x00000008,0x00000002	
	AREA mydata, DATA,READWRITE
DST DCD 0,0,0,0
	END