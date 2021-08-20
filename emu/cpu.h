#ifndef CPU_H
#define CPU_H
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "config.h"




/*-----[Instructions]-----*/
enum {
	iNop = 0x0000, //No op
	iHlt = 0x0001,  // Halt/exit 
	iCount
};

/*-----[Registers]-----*/
enum{
	X0 = 0,  // all that start with x are 32 bit registers
	X1,
	X2,
	X3,
	X4,
	R32_Count //Clever trick to get the number of items in the enum
};

/*-----[Flags]-----*/
enum{
	F_Z = 0, //Zero
	F_L,     //Less
	F_E,     //Equal
	F_N,     //Negative
	F_C,     //Cary
	F_COUNT
};


/*-----[Virtual Machine]-----*/

/*
I defined a  struct here becouse this project uses
DataOrentatedProgramming
*/
typedef struct{

	uint8_t memory[MEMORY_SIZE];         // RAM
	uint32_t PC;                       	 // Program Counter
	bool flags[F_COUNT];                 // Flags
	uint32_t reg32[R32_Count];           // 32bit Registers


} VM;

/*-----[Memory Manipulation]-----*/
static inline void reset(VM* vm,uint32_t address){
	vm->PC = address;
}

static inline uint8_t readMemory(VM* vm,uint32_t address)
{
  return vm->memory[address];
}

static inline void writeMemory(VM* vm,uint32_t address,uint32_t value)
{
  vm->memory[address]=value;
}

static inline uint32_t fetch(VM* vm){
	return readMemory(vm,vm->PC);
}

#endif
