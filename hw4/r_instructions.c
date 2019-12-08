//These are the R-instructions implemented by the simulted MIPS processor
#include "cpu.h"
#define MASK6 		0x3F
#define MASK5		0x1F
#define MASK32		0xFFFFFFFF
#define OPCODE(x) 	(x>>26)&0x0
#define RS(x) 		(x>>21)&MASK5
#define RT(x) 		(x>>16)&MASK5
#define RD(x) 		(x>>11)&MASK5
#define SHAMT(x) 	(x>>6)&MASK5
#define FUNCT(x) 	x&MASK6


void add(unsigned int instruction){
	registers[RD(instruction)] = (unsigned int)((int)registers[RS(instruction)]+(int)registers[RT(instruction)]);
}

void addu(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)]+registers[RT(instruction)];
}

void sub(unsigned int instruction){
	registers[RD(instruction)] = (unsigned int)((int)registers[RS(instruction)]-(int)registers[RT(instruction)]);
}

void subu(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)]-registers[RT(instruction)];
}

void mult(unsigned int instruction){
	long res = (long) registers[RS(instruction)]* (long) (registers[RT(instruction)]);
	HI = (res>>32)&MASK32;
	LO = res&MASK32;
}

void multu(unsigned int instruction){
	unsigned long res = (unsigned long) registers[RS(instruction)] * (unsigned long) registers[RT(instruction)];
	HI = (res>>32)&MASK32;
	LO = res&MASK32;
}

void div(unsigned int instruction){
	LO = (int)registers[RS(instruction)]/(int)registers[RT(instruction)];
	HI = (int)registers[RS(instruction)]%(int)registers[RT(instruction)];
}

void divu(unsigned int instruction){
	LO = registers[RS(instruction)]/registers[RT(instruction)];
	HI = registers[RS(instruction)]%registers[RT(instruction)];
}

void and(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)]&registers[RT(instruction)];
}

void nor(unsigned int instruction){
	registers[RD(instruction)] = ~(registers[RS(instruction)]|registers[RT(instruction)]);
}

void or(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)]|registers[RT(instruction)];
}

void xor(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)]^registers[RT(instruction)];
}

void sll(unsigned int instruction){
	registers[RD(instruction)] = registers[RT(instruction)]<<SHAMT(instruction);
}

void sllv(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)]<<registers[RT(instruction)];
}

void srl(unsigned int instruction){
	registers[RD(instruction)] = registers[RT(instruction)] >> SHAMT(instruction);
}

void sra(unsigned int instruction){
	unsigned int shift = SHAMT(instruction);
	registers[RD(instruction)] = registers[RT(instruction)] >> shift;
	unsigned int test = (registers[RT(instruction)]>>31)&0x1;
	if (test != 0x0){
		registers[RD(instruction)]=registers[RD(instruction)]&(((1<<shift)-1)<<(32-shift));
	}
} 

void srlv(unsigned int instruction){
	registers[RD(instruction)] = registers[RS(instruction)] >> registers[RT(instruction)];
}

void srav(unsigned int instruction){
	unsigned int shift = registers[RT(instruction)];
	registers[RD(instruction)] = registers[RS(instruction)] >> shift;
	unsigned int test = (registers[RS(instruction)]>>31)&0x1;
	if (test != 0x0){
		registers[RD(instruction)]=registers[RD(instruction)]&(((1<<shift)-1)<<(32-shift));
	}
}

void slt(unsigned int instruction){
	if((int)registers[RS(instruction)]<(int)registers[RT(instruction)]){
		registers[RD(instruction)] = 1;
	}else{
		registers[RD(instruction)] = 0;
	}
}

void sltu(unsigned int instruction){
	if(registers[RS(instruction)]<registers[RT(instruction)]){
		registers[RD(instruction)] = 1;
	}else{
		registers[RD(instruction)] = 0;
	}
}

void jr(unsigned int instruction){
	npc = registers[RS(instruction)];
}

void jalr(unsigned int instruction){
	registers[31] = pc + 4;
	npc = registers[RS(instruction)];
}

void mfhi(unsigned int instruction){
	registers[RD(instruction)] = HI;
} 

void mflo(unsigned int instruction){
	registers[RD(instruction)] = LO;
}


