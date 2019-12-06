
//These are the i-instructions implemented by the simulted MIPS processor
#include "cpu.h"
#define MASK5		0x1F
#define RS(x) 		(x>>21)&MASK5
#define RT(x) 		(x>>16)&MASK5
#define IMD(x)		x&0xFFFF

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
	registers[RT(instruction)]=(registers[RS(instruction)]|IMD(instruction)<<16)>>16;
	//make sure the upper 16 bits are zero
}

void xori(unsigned int instruction){
	registers[RT(instruction)]=(registers[RS(instruction)]^IMD(instruction)<<16)>>16;
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
		npc= pc+4+(sign_extend(IMD(instruction),16)<<2)
	}
}

void bne(unsigned int instruction){
	if(registers[RS(instruction)]!=registers[RT(instruction)]){
		npc= pc+4+(sign_extend(IMD(instruction),16)<<2)
	}
}

void lb(unsigned int instruction){//check
	registers[RT(instruction)]=sign_extend(memory[(int)registers[RS(instruction)]+(int)sign_extend(IMD(instruction),16)],8);
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
unsigned int sign_extend(unsigned int immediate,int bits){
	unsigned int result = 0x0;
	unsigned int test = (immediate>>(bits-1))&0x1;
	if (test != 0x0){
		unsigned int sign_extended = immediate|(0xFFFF<<16)
		result = sign_extended;
	}else{
		result = immediate;
	}
	return result;
}
