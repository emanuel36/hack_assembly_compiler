#include <stdio.h>
#include "instruction.h"
#include "file.h"

int main(){
	int linha = 0;
	char read[100];
	int i, erro = 0, instruction = 0xFFFF;
	remove("app.bin");

	while(readFile(read, linha)){
		linha++;
		
		if(emptyLine(read)){
			continue;
		}			

		restate(read);

		if(validateInstruction(read)){
			printf("Line %d  error: invalid instruction!\n", linha);
			erro = 1;
			continue;
		}

		if(read[i] == '@'){
			//Instrunções tipo A
		}else{
			//Instruções tipo C
			if(comp(&instruction, read)){
				printf("Line %d: error: invalid '%s' COMP;\n", linha, read);
				erro = 1;
				continue;
			}
			if(dest(&instruction, read)){
				printf("Line %d: error: invalid '%s' DEST;\n", linha, read);	
				erro = 1;
				continue;
			}
			else if(jump(&instruction, read)){
				printf("Line %d: error: invalid '%s' JUMP;\n", linha, read);
				erro = 1;
				continue;
			}
		} 	         
		writeFile(instruction);
	}
	if(!erro){
		printf("\nCompiled successfully!\n\n");
	}else{
		remove("app.bin");		
	}
}