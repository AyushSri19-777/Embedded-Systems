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
	LDR R1,=NUM2	
	LDR R2,[R0]
	LDR R3,[R1]
UP	CMP R2,R3
	BEQ STOP
	CMP R2,R3
	BCS DOWN
	CMP R2,R3
	BCC DOWN2
	B UP

DOWN SUB R2,R2,R3
	B UP
DOWN2 	SUB R3,R3,R2
	B UP
STOP
	B STOP	
NUM1 DCD 0x20
NUM2 DCD 0X64
	AREA mydata, DATA,READWRITE
DST DCD 0
	END