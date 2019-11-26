;Write a program to subtract two 128 bit numbers
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
	LDR R0,=0X06
	MOV R3,#1
	MOV R2,#1
	BL FACT
STOP
	B STOP
FACT PUSH {R3,R14}
	ADD R3,#1
	CMP R3,R0
	BCS EXIT
	BL FACT
	POP {R3,R14}
	MUL R2,R2,R3
	
EXIT BX LR
	AREA mydata, DATA,READWRITE
DST DCD 0,0,0,0
	END