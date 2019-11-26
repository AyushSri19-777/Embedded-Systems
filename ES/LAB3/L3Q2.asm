;Write a program to multiply two 32 bit numbers by repetitive addition for BCD
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
	LDR R1,=NUM1
	LDR R11,=NUM2
	LDR R12,[R11]
	MOV R9,#0
	MOV R11,#0
	
LOOP LDR R7,[R0]
	MOV R2,#8
	LDR R3,=0
	
UP	AND R4,R7,#0x0F
	AND R5,R9,#0x0F
	MOV R6,#0
	ADCS R6,R4,R5
	CMP R6,#0x0A
	BCC down
	ADD R6,#06
	
down AND R10,R6,0x0F
	LSR R6,#04
	ADD R3,R10
	ROR R3,#04
	ROR R7,#04
	ROR R9,#04
	SUB R2,#01
	TEQ R2,#00
	BNE UP
	MOV R9,R3
	ADD R11,R6
	LDR R8,=0x0
	MSR xPSR,R8
	SUB R12,#01
	TEQ R12,#00
	BNE LOOP
	
	LDR R8,=DST
	STR R3,[R8],#4
	STR R11,[R8]
STOP
	B STOP
NUM1 DCD 0x92345678
NUM2 DCD 0x00000004
	AREA mydata, DATA,READWRITE
DST DCD 0
	END