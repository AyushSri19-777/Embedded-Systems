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
	LDR R6,=DST
	LDR R4,[R0]
	LDRH R5,[R1,#2]	
	;ADC R5,R4
	STR R5,[R6]	
STOP
	B STOP
NUM1 DCD 0x12345678
NUM2 DCD 0x47231211
	AREA mydata, DATA,READWRITE
DST DCD 0
	END