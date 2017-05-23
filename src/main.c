#include <stdio.h>
#include "instruction.h"
#include "file.h"

int main(){
	int linha = 0;
	char read[100];
	int i, instruction = 0xFFFF;

	while(readFile(read, linha)){
		linha++;
		printf("Linha %d = %s", linha, read);
			
		/*if(emptyLine(read)){
			continue;
		}
		restate(read);

		comp(&instruction, read);
		printf("%d\n", instruction);

		
		if(comp(&instruction, read)){
			printf("Erro na linha %d: COMP '%s' inválido;\n", linha, read);
			//recomeça while
		}
		if(dest(&instruction, read)){
			printf("Erro na linha %d: DEST '%s' inválido;\n", linha, read);	
			//recomeça while
		}
		else if(jump(&instruction, read)){
			printf("Erro na linha %d: JUMP '%s' inválido;\n", linha, read);
			//recomeça while
		} 	         
		//writeFile(instruction);*/
	}
}