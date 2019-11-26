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
	MOV R0,#42
	MOV R1,#56
	MOV R8,#1
	BL HCF
STOP
	B STOP		
HCF PUSH {R8,R14}
	CMP R0,#0
	BEQ DOWN
	MOV R6,R0
	MOV R7,R1
	BL DIV
	MOV R0,R7
	BL HCF
	POP {R6,LR}
	
DOWN BX LR

DIV	

UP	SUBS R7,R6
	ADD R8,#1
	CMP R7,R6
	BCS UP
	BX LR
	AREA mydata, DATA,READWRITE
DST DCD 0
	END