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
	LDR R1,=2
	LDR R2,=0XFFFFFFFF
	LDR R3,=0X10000001
	LDR R4,=0X0
	MSR XPSR,R4
	ASR R2,#1
	SMLAL R3,R4,R1,R2
	UMULL R3,R4,R1,R2
	SMULL R3,R4,R1,R2

STOP B STOP
	AREA mydata, DATA,READWRITE
DST DCD 0
	END