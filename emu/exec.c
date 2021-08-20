#include <stdio.h>
#include "exec.h"
#include "cpu.h"
#include "config.h"

//this function prints the instrctions
//if DEBUG is defined
void printIns(char instruction[],uint32_t address){
	#ifdef DEBUG
	printf("[ADDRESS] 0x%X | [INSTRUCTION] %s\n",address,instruction);
	#endif
}

int I_NOP(VM* vm){
 printIns("NOP",vm->PC);
 return 0;
}

int I_HLT(VM *vm){
	printIns("HLT",vm->PC);
	return 1; // 1 means exit
}
