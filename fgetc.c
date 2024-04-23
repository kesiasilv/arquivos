#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	f = fopen("arquivo.txt", "r");//"r" ler arquivo
	if (f == NULL){
		printf("Erro na abertura!\n");
		exit(1);
	}
	char c;
	int i;
	for(i=1; i<=10; i++){
		c = fgetc(f);
		printf("%c", c);
	}
	printf("\nFim\n");
	fclose(f);
	return 0;
}
