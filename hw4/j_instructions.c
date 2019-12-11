
//These are the J-instructions implemented by the simulted MIPS processor

//J instruction:  opcode (6 bits)      address (26 bits)
#include "cpu.h"
#define ADDRESS(x) 	(x&0x3FFFFFF)
#define MASK4		0xF0000000
void j(unsigned int instruction){
	unsigned int addr = ADDRESS(instruction);
	npc=((pc+4)&MASK4)|(addr<<2);
}
void jal(unsigned int instruction){
	registers[31]=pc+4;
	unsigned int addr = ADDRESS(instruction);
	npc=((pc+4)&MASK4)|(addr<<2);
}

