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
	MOV R4,#10
	MVN R5,#1
	MOV R0,#2
	MOV R1,#-2
	UMULL R4,R3,R0,R1
	LDR R0,=NUM1
	LDR R1,=NUM2
	LDR R2,=DST
UP	LDRB R3,[R0],#1
	STRB R3,[R2],#1
	SUBS R4,#1
	BNE UP
STOP
	B STOP
NUM1 DCD 0x12345678
NUM2 DCD 0x00004504
	AREA mydata, DATA,READWRITE
DST DCD 0
	END