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
	LDR R6,=DST
	LDR R1,[R0]	
	MLA R3,R1,R1,R1
	LSR R3,#1
	STR R3,[R6]
	LDR R4,=0x24300000
	ROR R4,#28
	LDR R4,=0x0000000F
	ROR R4,#1
	LDR R7,=0x20000000
	MSR xPSR,R7
	LDR R4,=0x00000002
	RRXS R4,R4
	LDR R1,=0x10000000
	LDR R0,=0X12345678
	LDR R2,=0XADB0EF12
	STRB R0,[R1]
	STRB R0,[R1,#01]!
	STR R0,[R1],#04
	LDRB R0,[R1,#-1]!
	LDRH R0,[R1,#-2]
	RRX R3,R2
	LDR R2,[R1,#-4]
	ADC R3,#01
	
	
	
STOP
	B STOP
NUM1 DCD 0x4
NUM2 DCD 0x47231211
	AREA mydata, DATA,READWRITE
DST DCD 0
	END