;Write a program to FACT BY RECUR
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
	LDR R0,[R0]
	BL FACT
STOP
	B STOP
	
FACT PUSH {R4,R14}
	MOV R4,R0
	CMP R0,#0
	BNE DOWN
	MOV R0,#1
	B LAST
	
DOWN SUB R0,#1
	BL FACT
	MOV R1,R4
	MUL R0,R0,R1
	
LAST POP {R4,R14}
	BX LR	

NUM1 DCD 0x5	
	AREA mydata, DATA,READWRITE
DST DCD 0
	END