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
	LDR R1,=DST
	LDRB R2,[R0],#1
	LDRB R3,[R0]
	MOV R4,#0
	
UP	CMP R2,R3
	BCC RES
	SUB R2,R3
	ADD R4,#1
	B UP
	
RES	STRB R2,[R1],#1
	STRB R4,[R1]

STOP
	B STOP
SRC DCD 0X0723
	AREA mydata, DATA,READWRITE
DST DCD 0
	END
