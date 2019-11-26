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
	LDR R2,=DST
	MOV R4,#8
	LDR R1,[R0]
UP	AND R3,R1,0XF
	STR R3,[R2],#4
	ROR R1,#4
	SUBS R4,#01
	BNE UP
STOP
	B STOP
NUM1 DCD 0x47231211
	AREA mydata, DATA,READWRITE
DST DCD 0
	END