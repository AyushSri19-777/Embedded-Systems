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
	LDR R1,=0X07
	LDR R7,=DST
	MOV R2,#1
	BL LCM
STOP
	B STOP
LCM PUSH {R2,R14}
	BL DIV
	STR R2,[R7]
	LDR R6,[R7]
	MOV R1,R0
	BL DIV
	STR R2,[R7]
	LDR R8,[R7]
	CMP R6,#0
	BEQ EX1
	B G
F	B EXIT
G	BL LCM
	POP {R2,R14}
	ADD R2,#1
EXIT BX LR
	B STOP
EX1	CMP R8,#0
	B F
DIV 
UP	SUB R2,R1
	CMP R1,#0
	BNE UP
	BX LR
	AREA mydata, DATA,READWRITE
DST DCD 0,0,0,0
	END