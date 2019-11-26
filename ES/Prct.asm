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
	LDR R0,=SRC
	ADD R2,R0,#4
	MOV R4,#0
	MOV R5,#0
UP1	LDR R0,=SRC
	ADD R2,R0,#4
	MOV R4,#0
UP2	
	LDR R6,[R0]
	LDR R7,[R2]
	CMP R6,R7
	BCC K
	LDR R8,[R2]
	LDR R9,[R0]
	STR R8,[R0]
	STR R9,[R2]
K	ADD R2,#4
	ADD R0,#4
	ADD R4,#1
	CMP R4,#4
	BNE UP2
	ADD R5,#1
	CMP R5,#5
	BEQ STOP
	B UP1
	
STOP
	B STOP
	AREA mydata, DATA,READWRITE
SRC DCD 0,0,0,0,0
	END

