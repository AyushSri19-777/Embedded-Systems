;Write a program to add ten 32 bit numbers stored in code segment and store the result in data segment
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
	LDR R6,=DST
	MOV R2,#0
	MOV R3,#0
	MOV R4,#10

UP 	LDR R1,[R0],#4
	ADDS R2,R1
	ADCS R3,#0
	SUBS R4,#01
	BNE UP
	STR R2,[R6]
	STR R3,[R6,#-4]!
STOP
	B STOP
SRC DCD 0x00000008,0x00000004,0x00000007,0x00000001,0x00000005,0x00000002,0x000000008,0x00000012,0x00000009,0x00000004
	AREA mydata, DATA,READWRITE
DST DCD 0
	END
