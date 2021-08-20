# avcpu2032
The AVCP2032 is a BigEndian 32bit virtual cpu created by arydev

## Building
To compile the emulator You need gcc ans a POSX OS (Mac,GNU/Linux,BDS...)
``` 
$ make
```
## Specification
The AVCP2032 has 20 General Porpose registers 5 32bit 5 16bit 5 8bit and 5 float



|  Name |  Type |    Size    |  Description                        |
--- | --- | ---| ---
|  PC   |  PT   |   32bit    |  A pointer to a location in memory  |
|  SP   |  PT   |   32bit    |  Stack Pointer                      |
| Flags |  ST   |   16bit    |  Bits represent flags               |
| X0-X4 |  GP   |   32bit    |  General Porpose 32 bit registers   |
| Y0-Y4 |  GP   |   16bit    |  General Porpose 16 bit registers   |
| W0-W4 |  GP   |   8bit     |  General Porpose 8 bit registers    |
| F0-F4 |  FL   |   32bit    |  32bit Floting point registers      |

### Instruction set
The instruction set is not finished it may change

| OP | Memonic | PseudoInstruction |       Description           |
--- | ---| --- | ----
| 0000   | NOP  | NOP         |  No Operation               |
| 1000   | EXT  | EXT 0       |  Exit and return number     |
| 2000   | HLT  | HLT         |  Halt                       |
| 3000   | ADD  | ADD X0, 19  |  ADD number to register     |
| 4000   | ADD  | ADD  X0, X1 |  Add register to register   |
| 5000   | ADDC | ADDC X0, 5  |  Add with carry             |
| 6000   |      |             |                             |
| 7000   | SUB  | SUB X0, 5   |  Subtract num from register |
| 8000   | SUM  | SUM X0, X3  |  Subtract reg from reg      |
| 9000   | MUL  | MUL  X1, 2  |  Multiply reg by num        |
| A000   | DIV  | DIV  X3, 5  |  Divide reg by num          |
| B000   | AND  | AND X0, 100 |  And between reg and num    |
| C000   | OR   | OR X0, 50   |  Or between reg and num     |
| D000   | NOT  | NOT X0, 60  |  Not between reg and num    |
| E000   | XOR  | XOR X0, 34  |  Xor between reg and num    |
| F000   | NOR  | NOR X0, 64  |  Nor between reg and num    |
| 1100   | MV   | MV X0, 5    |  Move data to register      |
| 1200   | MV   | MV X0, X1   |  Move Register to register  |  
| 1300   | LD   | LD X0, 0xff |  Load Address to register   |    
| 1400   | LD   | LD X0, [X3] |  Load from addres in r to r |    
| 1500   | STR  | STR 0xff, 5 |  Store data in address      |     
| 1600   | STR  | STR 0xff, X2|  Store Register to address  |     
| 1700   | STR  | STR [X2],X0 |  Store in r address register|      
| 1800   | STR  | STR [X2],10 |  Store in r addres data     |
| 1900   | PUSH | PUSH X0     |  Push register to the stack |
| 2100   | PUSH | PUSH 65     |  Push data to stack         |
| 2200   | POP  | POP X0      |  Pop from stack to register |



