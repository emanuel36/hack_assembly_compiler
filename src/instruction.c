#include <stdio.h>
#include <string.h>
#include "instruction.h"

int jump2(int *instruction, char *jump){
	if(!(strcmp(jump, "JGT"))){
		*instruction = *instruction | JGT;
		return 0;
	}	    
	else if(!(strcmp(jump, "JEQ"))){
		*instruction = *instruction | JEQ;
		return 0;
	}	
	else if(!(strcmp(jump, "JGE"))){
		*instruction = *instruction | JGE;
		return 0;
	}			
	else if(!(strcmp(jump, "JLT"))){
		*instruction = *instruction | JLT;
		return 0;
	}	
	else if(!(strcmp(jump, "JNE"))){
		*instruction = *instruction | JNE;
		return 0;
	}	
	else if(!(strcmp(jump, "JLE"))){
		*instruction = *instruction | JLE;
		return 0;
	}	
	else if(!(strcmp(jump, "JMP"))){
		*instruction = *instruction | JMP;
		return 0;
	}	
	else return 1;
}

int jump(int *instruction, char *read){
	int i;
	*instruction = *instruction & ZERA_JUMP;
	for(i = 0; read[i] != '\0'; i++){
		if(!(strncmp(&read[i], ";", 1))){
			if(jump2(instruction, &read[i + 1])){
				char *aux = &read[i + 1];
				strcpy(read, aux);
				return 1;
			}
			return 0;
		}
	}
}

int dest2(int *instruction, char *dest){
	if(!(strcmp(dest, "M"))){
		*instruction = *instruction | M;
		return 0;
	}		
	else if(!(strcmp(dest, "D"))){
		*instruction = *instruction | D;
		return 0;
	}	
	else if(!(strcmp(dest, "MD"))){
		*instruction = *instruction | MD;
		return 0;
	}	
	else if(!(strcmp(dest, "A"))){
		*instruction = *instruction | A;
		return 0;
	}	
	else if(!(strcmp(dest, "AM"))){
		*instruction = *instruction | AM;
		return 0;
	}	
	else if(!(strcmp(dest, "AD"))){
		*instruction = *instruction | AD;
		return 0;
	}	
	else if(!(strcmp(dest, "AMD"))){
		*instruction = *instruction | AMD;
		return 0;
	}	
	else return 1;
}

int dest(int *instruction, char *read){
	char dest[100];
	int i;

	*instruction = *instruction & ZERA_DEST;
	strcpy(dest, read);
	for(i = 0; dest[i] != '\0'; i++){
		if(!(strncmp(&dest[i], "=", 1))){
			dest[i] = '\0';
			if(dest2(instruction, dest)){
				strcpy(read, dest);
				return 1;
			}
			return 0;
		}
	}
}

int comp2(int *instruction, char *comp){
	if(!(strcmp(comp, "0"))){
		*instruction = *instruction | ZERO;
		return 0;
	}
	else if(!(strcmp(comp, "1"))){
	    *instruction = *instruction | UM;
		return 0;
	}
	else if(!(strcmp(comp, "-1"))){
	    *instruction = *instruction | MENOS_UM;
		return 0;
	}
	else if(!(strcmp(comp, "D"))){
	    *instruction = *instruction | DX;
	 	return 0;
	}
	else if(!(strcmp(comp, "A"))){
	    *instruction = *instruction | AX;
	 	return 0;
	}
	else if(!(strcmp(comp, "!D"))){
	    *instruction = *instruction | ND;
		return 0;
	}
	else if(!(strcmp(comp, "!A"))){
		*instruction = *instruction | NA;
		return 0;
	}
	else if(!(strcmp(comp, "-D"))){
	    *instruction = *instruction | LD;
		return 0;
	}
	else if(!(strcmp(comp, "-A"))){
	 	*instruction = *instruction | LA;
	 	return 0;
	 }
	else if(!(strcmp(comp, "D+1"))){
	   *instruction = *instruction | D_P_1;
		return 0;
	}	
	else if(!(strcmp(comp, "A+1"))){
	   *instruction = *instruction | A_P_1;
		return 0;
	}	
	else if(!(strcmp(comp, "D-1"))){
	   *instruction = *instruction | D_L_1;
		return 0;
	}	
	else if(!(strcmp(comp, "A-1"))){
	   *instruction = *instruction | A_L_1;
		return 0;
	}
	else if(!(strcmp(comp, "D+A"))){
	   *instruction = *instruction | DPA;
		return 0;
	}
	else if(!(strcmp(comp, "D-A"))){
		*instruction = *instruction | DLA;
		return 0;
	}
	else if(!(strcmp(comp, "A-D;"))){
		*instruction = *instruction | ALD;
		return 0;
	}
	else if(!(strcmp(comp, "D&A"))){
		*instruction = *instruction | DEA;
		return 0;
	}
	else if(!(strcmp(comp, "D|A"))){
	   *instruction = *instruction | DOA;
	   return 0;	
	}
	else if(!(strcmp(comp, "M"))){
		*instruction = *instruction | MX;
		return 0;
	}
	else if(!(strcmp(comp, "!M"))){
		*instruction = *instruction | NM;
		return 0;
	}
	else if(!(strcmp(comp, "-M"))){
	 	*instruction = *instruction | LM;
	 	return 0;
	}
	else if(!(strcmp(comp, "M+1"))){
	   *instruction = *instruction | M_P_1;
		return 0;
	}
	else if(!(strcmp(comp, "M-1"))){
	   *instruction = *instruction | M_L_1;
		return 0;
	}
	else if(!(strcmp(comp, "D+M"))){
	   *instruction = *instruction | DPM;
		return 0;
	}
	else if(!(strcmp(comp, "D-M"))){
	   *instruction = *instruction | DLM;
		return 0;
	}
	else if(!(strcmp(comp, "M-D"))){
	   *instruction = *instruction | MLD;
		return 0;
	}
	else if(!(strcmp(comp, "D&M"))){
	   *instruction = *instruction | DEM;
		return 0;
	}
	else if(!(strcmp(comp, "D|M"))){
	   *instruction = *instruction | DOM;
		return 0;
	}
	else return 1;
}

int comp(int *instruction, char *read){
	int i;
	char comp[100];
	*instruction = *instruction & ZERA_COMP;
	strcpy(comp, read);
	for(i = 0; read[i] != '\0'; i++){
		//dest=comp
		if(!(strncmp(&comp[i], "=", 1))){
			char *aux = &comp[i + 1];
			strcpy(comp, aux);
		}
		//comp;jump
		else if(!(strncmp(&comp[i], ";", 1))){
			comp[i] = '\0';
		}
	}
	if(comp2(instruction, comp)){
		strcpy(read, comp);
		return 1;
	}
}