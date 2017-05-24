#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int readFile(char *linha, int cont){
	char caminho[] = "entrada";
	int interno=0;
	FILE *f;
	f = fopen(caminho, "r");
	
	if(f == NULL){
		printf("Arquivo nao encontrado.");
	}
	else{
		while(interno < cont){
			fgets(linha, 100, f);
			interno++;
		}
		while((fgets(linha, 100, f)) != NULL){
			return 1;
		}
	}
	fclose(f);
	return 0;
}

void writeFile(int instruction){
	//system("rm -f app.bin");
	char caminho[] = "app.bin";
	FILE *f;
	f = fopen(caminho, "a");

	if(f == NULL){
		printf("Arquivo nao encontrado.");
	}
	else{
		fprintf(f, "%X\n", instruction);
	}
	fclose(f);
}

int emptyLine(char *string){
	int i;
	for(i = 0; string[i] != '\0'; i++){
		if(string[i] != ' '){
			if(string[i] != '\n'){
				return 0;		
			}
		} 
	}
	return 1;
}

void restate(char *string){
	int i, j;
	char aux[100];
	for(i = 0; string[i] != '\0'; i++){
		//Tira os Espaços
		if(!(strncmp(&string[i], " ", 1))){
			for(j = i; string[j] != '\0'; j++){
				string[j] = string[j + 1];
			}
			i--;
		} 
		//Tira os comentários
		if(!(strncmp(&string[i], "//", 2))){
			string[i] = '\0';
			break;
		}
		if(!(strncmp(&string[i], "\n", 1))){
			string[i] = '\0';
			break;
		}
	}
}

/*
int validateInstruction(char *read){
	int i;
	for(i = 0; read[i] != '/0'; i++){
		if(read[i] == ';')
	}
}
*/