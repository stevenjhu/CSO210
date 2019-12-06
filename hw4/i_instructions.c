
//These are the i-instructions implemented by the simulted MIPS processor
#include "cpu.h"
#define MASK5		0x1F
#define RS(x) 		(x>>21)&MASK5
#define RT(x) 		(x>>16)&MASK5
#define IMD(x)		x&0xFFFF

void addi(unsigned int instruction){
	unsigned int test = (registers[IMD(instruction)]>>15)&0x1;
	if (test != 0x0){
		unsigned int sign_extended = IMD(instruction)|(0xFFFF<<16)
		registers[RT(instruction)]=(unsigned int)((int)registers[RS(instruction)]+(int)sign_extended);
	}else{
		registers[RT(instruction)]=(unsigned int)((int)registers[RS(instruction)]+(int)IMD(instruction));
	}
}

void addiu(unsigned int instruction){
	unsigned int test = (registers[IMD(instruction)]>>15)&0x1;
	if (test != 0x0){
		unsigned int sign_extended = IMD(instruction)|(0xFFFF<<16)
		registers[RT(instruction)]=registers[RS(instruction)]+sign_extended;
	}else{
		registers[RT(instruction)]=registers[RS(instruction)]+IMD(instruction);
	}
}

void andi(unsigned int instruction){

}

void ori(unsigned int instruction){

}

void xori(unsigned int instruction){

}

void slti(unsigned int instruction){

}

void sltiu(unsigned int instruction){

}

void beq(unsigned int instruction){

}

void bne(unsigned int instruction){

}

void lb(unsigned int instruction){

}

void lbu(unsigned int instruction){

}

void lh(unsigned int instruction){

}

void lhu(unsigned int instruction){

}

void lw(unsigned int instruction){

}

void lui(unsigned int instruction){

}

void sb(unsigned int instruction){

}

void sh(unsigned int instruction){

}

void sw(unsigned int instruction){

}
