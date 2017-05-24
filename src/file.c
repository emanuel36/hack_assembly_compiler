#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
	char caminho[] = "app.bin";
	int i;
	FILE *f;
	f = fopen(caminho, "a");

	if(f == NULL){
		printf("Arquivo nao encontrado.");
	}
	else{
		for(i = 15; i > 0; i--){
			if(instruction & (1 << i))	fprintf(f, "1");
			else						fprintf(f, "0");
		}
		fprintf(f, "\n");
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
		//converte letra para maiuscula
		string[i] = toupper(string[i]);		
	}
}

int validateInstructionA(char *read){
	int i;
	if(!(read[1] >= '0' && read[1] <= '9') && (read[1] != '(')){
		printf("IF 1");
		return 1;
	}
	if(read[1] == '('){
		for(i = 0; read[i] != '\0'; i++){
			if(read[i] == ')'){
				return 0;
			}
		}
		return 1;
	}
	else{
		for(i = 2; read[i] != '\0'; i++){
			if(!(read[i] >= '0' && read[i] <= '9')){
				return 1;
			}
		}
	}
	return 0;
}

int validateInstructionB(char *read){
	int i;
	for(i = 0; read[i] != '\0'; i++){
		if(read[i] == '='){
			while(read[i] != '\0'){
				i++;
				if(read[i] == ';'){
					return 1;
				}
			}
		}
	}
	return 0;
}

int validateInstruction(char *read){
	int i;
	if(read[0] == '@'){
		return (validateInstructionA(read));
	}else{
		return (validateInstructionB(read));
	}
}