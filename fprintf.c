#include <stdio.h>
#include <stdlib.h>

int main(){
	char nome[20] = "kesia";
	int i = 19;
	float a = 1.52;
	FILE *arq = fopen("arquivo.txt", "w");
	if(arq == NULL){
		printf("Erro na abertura!");
		exit(1);
	}
	printf("Nome: %s \nIdade: %d\nAltura: %.2f\n", nome, i, a);//imprime no prompt de comando
	fprintf(arq,"Nome: %s\nIdade: %d\nAltura: %.2f\n", nome, i, a);//imprime no bloco de notas
	fclose(arq);
	
	return 0;
}
