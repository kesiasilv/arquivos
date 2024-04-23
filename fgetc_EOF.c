#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	f = fopen("arquivo.txt", "r");
	if (f == NULL){
		printf("Erro na abertura!\n");
		exit(1);
	}
	char c = fgetc(f);
	while(c != EOF){//vai ler todos os caracteres 
		printf("%c", c);
		c = fgetc(f);
	}
	printf("\nFim\n");
	fclose(f);
	return 0;
}
