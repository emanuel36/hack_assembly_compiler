#include <stdio.h>
#include "instruction.h"
#include "file.h"

int main(){
	int linha = 0;
	char read[100];
	int i, instruction = 0xFFFF;

	while(readFile(read, linha)){
		linha++;
		
		if(emptyLine(read)){
			continue;
		}			

		restate(read);

		//Instruções tipo C
		/*
		if(validateInstruction(read)){
			printf("Erro na linha %d instrução inválida!\n", linha);
		}
		*/

		if(comp(&instruction, read)){
			printf("Erro na linha %d: COMP '%s' inválido;\n", linha, read);
			continue;
		}
		if(dest(&instruction, read)){
			printf("Erro na linha %d: DEST '%s' inválido;\n", linha, read);	
			continue;
		}
		else if(jump(&instruction, read)){
			printf("Erro na linha %d: JUMP '%s' inválido;\n", linha, read);
			continue;
		} 	         
		writeFile(instruction);
	}
}