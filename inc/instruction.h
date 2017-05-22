#include <stdio.h>

int jump2(int *instruction, char *jump);
int jump(int *instruction, char *read);
int dest2(int *instruction, char *dest);
int dest(int *instruction, char *read);
int comp2(int *instruction, char *comp);
int comp(int *instruction, char *read);

#define ZERA_JUMP 0xFFF8
#define JGT 	  0b001
#define JEQ	 	  0b010
#define JGE 	  0b011
#define JLT	  	  0b100
#define JNE 	  0b101
#define JLE 	  0b110
#define JMP 	  0b111

#define ZERA_DEST 0xFFC7
#define M		  0b001000
#define D		  0b010000
#define MD		  0b011000
#define A		  0b100000
#define AM		  0b101000
#define AD		  0b110000
#define AMD		  0b111000

#define ZERA_COMP 0xE03F
#define ZERO	  0b0101010000000
#define UM   	  0b0111111000000
#define MENOS_UM  0b0111010000000
#define DX		  0b0001100000000
#define AX 		  0b0110000000000
#define ND 		  0b0001101000000
#define NA		  0b0110001000000
#define LD		  0b0001111000000
#define LA 		  0b0110011000000
#define D_P_1 	  0b0011111000000
#define A_P_1 	  0b0110111000000
#define D_L_1 	  0b0001110000000
#define A_L_1 	  0b0110010000000
#define DPA		  0b0000010000000
#define DLA    	  0b0010011000000
#define ALD		  0b0000111000000
#define DEA		  0b0000000000000
#define DOA		  0b0010101000000
#define MX		  0b1110000000000
#define NM		  0b1110001000000
#define LM		  0b1110001000000
#define M_P_1	  0b1110111000000
#define M_L_1	  0b1110010000000
#define DPM		  0b1000010000000
#define DLM		  0b1010011000000
#define MLD		  0b1000111000000
#define DEM		  0b1000000000000
#define DOM		  0b1010101000000