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
	LDR R0,=0X12131415
	LDR R1,=0XABCDEF12
	LDR R2,=0X12345678
	LDR R13,=0X10001000
	LDR R4,=0X11111111
	PUSH {R2,R1}
	STM R13,{R1,R2}
	STMDB R13!,{R2,R0}
	LDM R13,{R6,R7}
	POP {R10}
	LDMDB R13!,{R6,R7}
STOP
	B STOP
SRC DCD 0X0723
	AREA mydata, DATA,READWRITE
DST DCD 0
	END