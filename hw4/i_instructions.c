#include <stdio.h>
//These are the i-instructions implemented by the simulted MIPS processor
#include "cpu.h"
#define MASK5		0x1F
#define RS(x) 		((x>>21)&MASK5)
#define RT(x) 		((x>>16)&MASK5)
#define IMD(x)		(x&0xFFFF)

unsigned int sign_extend(unsigned int immediate,int bits){
	unsigned int result = 0x0;
	unsigned int test = (immediate>>(bits-1))&0x1;
	if (test != 0x0){
		unsigned int sign_extended = immediate|(0xFFFFFFFF<<bits);
		result = sign_extended;
	}else{
		result = immediate;
	}
	return result;
	// printf("debug\n");
}

void addi(unsigned int instruction){
	registers[RT(instruction)]=(unsigned int)((int)registers[RS(instruction)]+(int)sign_extend(IMD(instruction),16));
}

void addiu(unsigned int instruction){
	registers[RT(instruction)]=registers[RS(instruction)]+sign_extend(IMD(instruction),16);
}

void andi(unsigned int instruction){
	registers[RT(instruction)] = registers[RS(instruction)]&IMD(instruction);
	//no need to make sure upper 16 bits are zero because (0 & anything) is 0
}

void ori(unsigned int instruction){
	unsigned int immediate = IMD(instruction);
	registers[RT(instruction)]=registers[RS(instruction)]|immediate;
	//make sure the upper 16 bits are zero
}

void xori(unsigned int instruction){
	unsigned int immediate =IMD(instruction);
	registers[RT(instruction)]=registers[RS(instruction)]^immediate;
		//make sure the upper 16 bits are zero
}

void slti(unsigned int instruction){
	if((int)registers[RS(instruction)]<(int)sign_extend(IMD(instruction),16)){
		registers[RT(instruction)]=1;
	}else{
		registers[RT(instruction)]=0;
	}
}

void sltiu(unsigned int instruction){
	if(registers[RS(instruction)]<sign_extend(IMD(instruction),16)){
		registers[RT(instruction)]=1;
	}else{
		registers[RT(instruction)]=0;
	}
}

void beq(unsigned int instruction){
	if(registers[RS(instruction)]==registers[RT(instruction)]){
		npc= pc+4+(sign_extend(IMD(instruction),16)<<2);
	}
}

void bne(unsigned int instruction){
	if(registers[RS(instruction)]!=registers[RT(instruction)]){
		npc= pc+4+(sign_extend(IMD(instruction),16)<<2);
	}
}

void lb(unsigned int instruction){
	registers[RT(instruction)]=sign_extend(memory[registers[RS(instruction)] + sign_extend(IMD(instruction),16)], 8);
}

void lbu(unsigned int instruction){
	registers[RT(instruction)]=memory[registers[RS(instruction)] + sign_extend(IMD(instruction),16)];
}

void lh(unsigned int instruction){
	unsigned short *p = (unsigned short *)&memory[registers[RS(instruction)]+sign_extend(IMD(instruction),16)];
	registers[RT(instruction)]= sign_extend(*p,8);
}

void lhu(unsigned int instruction){
	unsigned short *p = (unsigned short *)&memory[registers[RS(instruction)]+sign_extend(IMD(instruction),16)];
	registers[RT(instruction)]= (unsigned int)*p;
}

void lw(unsigned int instruction){
	unsigned int *p = (unsigned int *)&memory[registers[RS(instruction)] + sign_extend(IMD(instruction),16)];
	registers[RT(instruction)] = *p;
}

void lui(unsigned int instruction){
	unsigned int immediate = IMD(instruction);
	registers[RT(instruction)]= (immediate<<16);
}

void sb(unsigned int instruction){
	memory[registers[RS(instruction)]+sign_extend(IMD(instruction),16)]=registers[RT(instruction)];
}

void sh(unsigned int instruction){
	unsigned short *p =(unsigned short *)&memory[registers[RS(instruction)]+sign_extend(IMD(instruction),16)];
	*p=registers[RT(instruction)];
}

void sw(unsigned int instruction){
	unsigned int *p = (unsigned int *)&(memory[registers[RS(instruction)]+sign_extend(IMD(instruction),16)]);
	*p=registers[RT(instruction)];
}
