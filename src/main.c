#include <stdio.h>
#include "instruction.h"
#include "file.h"

int main(){
	int linha = 0, cont = 0, tamanho = 0, cont2 = 16;
	char read[100];
	int erro = 0, instruction = 0xFFFF;
	remove("app.bin");
	remove("simbolos");
	manualWrite(read);
	
	while(readIn(read, linha)){
		linha++;
		cont++;
	
		if(emptyLine(read)){
			continue;
		}			

		restate(read);

		/*if(validateInstruction(read)){
			printf("Line %d  error: invalid instruction!\n", linha);
			erro = 1;
			continue;
		}*/
	
		if(read[0] == '@' || read[0] == '('){
			//Instrunções tipo A
			if(read[0] == '('){
				cont--;
				writeOut2(read, cont);
				continue;
				//escreve no arquivo o nome do label e o número da linha anterior
			}
			else if(read[1] == '('){
				//procura no arquivo o numero da label e escreve seu numero correspondente
				instruction = cmpStr(&read[1]);
			}
			else if(read[1] <= '0' & read[1] <= '9'){
				value(read, &instruction);
			}
			else{
				//escreve no arquivo uma nova variavel, contando a partir do endereço 16
				if(read[1] <= '0' || read[1] >= '9'){
					writeOut2(&read[1], cont2);
					cont2++;
				}
			}	
		}
		else{
			//Instruções tipo C
			if(comp(&instruction, read)){
				printf("Line %d: error: invalid '%s' COMP!\n", linha, read);
				erro = 1;
				continue;
			}
			if(dest(&instruction, read)){
				printf("Line %d: error: invalid '%s' DEST!\n", linha, read);	
				erro = 1;
				continue;
			}
			else if(jump(&instruction, read)){
				printf("Line %d: error: invalid '%s' JUMP!\n", linha, read);
				erro = 1;
				continue;
			}
		}	         
		writeOut(instruction);
	}
	if(!erro){
		printf("\nCompiled successfully!\n\n");
	}else{
		remove("app.bin");		
	}
}