;Write a program to multiply two 32 bit numbers by repetitive addition
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
		
UP 	ADDS R4,R3
	ADC R5,#0
	SUBS R2,#01
	BNE UP
	STR R5,[R6],#4
	STR R4,[R6]
STOP
	B STOP
NUM1 DCD 0x00000055
NUM2 DCD 0x00000011	
	AREA mydata, DATA,READWRITE
DST DCD 0
	END