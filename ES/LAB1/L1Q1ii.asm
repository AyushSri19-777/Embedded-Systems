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
	LDR R0,=SRC+N*4-4
	LDR R1,=SRC+(N*8)-4-V*4
	
	MOV R4,#10
UP 	LDR R3,[R0],#-04
	STR R3, [R1], #-04
	SUBS R4,#01
	BNE UP
STOP
	B STOP
N   EQU 10
V   EQU 5
	AREA mydata, DATA,READWRITE
SRC DCD 0x12345678,0xABCDEF12,0x48723489,0x12345548,0xABC45F12,0x48453489,0x13445678,0xABC56F12,0x48783489,0x48783488
	END
