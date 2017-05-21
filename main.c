#include <stdio.h>
#include <string.h>

void jump2(int *instruction, char *jump){
	*instruction = *instruction & 0xFFF8;
	if(!(strcmp(jump, "JGT")))	    *instruction = *instruction | 0b001;
	else if(!(strcmp(jump, "JEQ")))	*instruction = *instruction | 0b010;	
	else if(!(strcmp(jump, "JGE")))	*instruction = *instruction | 0b011;
	else if(!(strcmp(jump, "JLT")))	*instruction = *instruction | 0b100;
	else if(!(strcmp(jump, "JNE")))	*instruction = *instruction | 0b101;
	else if(!(strcmp(jump, "JLE")))	*instruction = *instruction | 0b110;
	else if(!(strcmp(jump, "JMP")))	*instruction = *instruction | 0b111;
}

void jump(int *instruction, char *read){
	int i;
	*instruction = *instruction & 0xFFF8;
	for(i = 0; read[i] != '\0'; i++){
		if(!(strncmp(&read[i], ";", 1))){
			jump2(instruction, &read[i + 1]);
			break;
		}
	}
}

void dest2(int *instruction, char *dest){
	*instruction = *instruction & 0xFFC7;
	if(!(strcmp(dest, "M")))  	    *instruction = *instruction | 0b001000;
	else if(!(strcmp(dest, "D")))   *instruction = *instruction | 0b010000;
	else if(!(strcmp(dest, "MD")))  *instruction = *instruction | 0b011000;
	else if(!(strcmp(dest, "A")))   *instruction = *instruction | 0b100000;
	else if(!(strcmp(dest, "AM")))  *instruction = *instruction | 0b101000;
	else if(!(strcmp(dest, "AD")))  *instruction = *instruction | 0b110000;
	else if(!(strcmp(dest, "AMD"))) *instruction = *instruction | 0b111000;
}

void dest(int *instruction, char *read){
	char dest[1000];
	int i;

	strcpy(dest, read);
	for(i = 0; dest[i] != '\0'; i++){
		if(!(strncmp(&dest[i], "=", 1))){
			dest[i] = '\0';
			dest2(instruction, dest);
			break;	
		}
	}
}

void restate(char *string){
	int i, j;
	char aux[1000];
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
	}
}

int main(){
	char read[1000] = "MD=D+1 //comentário";
	int i, instruction = 0xFFFF;

	//restate(read);
	//jump(&instruction, read);
	//dest(&instruction, read);
	printf("%X\n", instruction);	
}