;Practice
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
	LDR R6,=DST
	LDR R2,[R1]
	LDR R3,[R0]
	BL DIV
	STR R4,[R6],#4
	STR R2,[R6]
STOP
	B STOP	
DIV 
UP	ADD R4,#1
	SUBS R2,R3
	BNE UP
	BX LR
NUM1 DCD 0x4
NUM2 DCD 0x0000000C
	AREA mydata, DATA,READWRITE
DST DCD 0
	END