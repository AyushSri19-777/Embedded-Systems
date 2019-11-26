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
	MOV R0,#0X4A
	LDR R3,=DST
	MOV R4,#2
UP	AND R1,R0,#0X0F
	CMP R1,#0XB	
	BCC DOWN
	ADD R1,0X07
	
DOWN ADD R1,0X30
	STR R1,[R3],#4
	LSR R0,#4
	
	SUBS R4,#01
	BNE UP
	
STOP
	B STOP
	AREA mydata, DATA,READWRITE
DST DCD 0
	END