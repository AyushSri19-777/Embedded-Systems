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
	LDR R6,=DST
	LDR R2,=0X0
	LDR R3,=0X1
	STRB R2,[R6],#1
	STRB R3,[R6]
	ADD R6,#07
	MOV R1,#0
	MOV R2,#1
	BL FIB
STOP
	B STOP

FIB ADD R3,R1,R2
	MOV R1,R2
	MOV R2,R3
	PUSH {R3,R14}
	CMP R3,#21
	BCS DOWN
	BL FIB
	POP {R3,R14}
	STRB R3,[R6,#-1]!
		
DOWN BX LR
	AREA mydata, DATA,READWRITE
DST DCD 0
	END