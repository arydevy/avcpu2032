#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "cpu.h"
#include "exec.h"

VM vm;


//int argc, char *argv[])
int main () {
  
	
	reset(&vm,0x30000); //Reset the cpu 


	//Program	
	writeMemory(&vm,0x30000,iNop);
	writeMemory(&vm,0x30001,iHlt);
	

	//Create jump table
  INST *jumpTable[iCount] ={
	I_NOP,
	I_HLT
	};

	for(;;){
		
		// Fetch
		uint8_t ins = fetch(&vm);   //Get instruction
		
		// Decode && Execute
		int exit = jumpTable[ins](&vm);

		// Exit if true
		if(exit){break;}
		vm.PC++;      //increment PC
	}


} 
