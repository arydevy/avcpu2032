#ifndef EXEC_H
#define EXEC_H
#include "cpu.h"

// if the return is 1 stop the program
typedef int INST(VM* vm);


int I_NOP(VM* vm);
int I_HLT(VM* vm);

#endif
