#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>//biblioteca que guarda letras minusculas e devolve maiuscula

int main(){
	FILE *f1, *f2;
	f1 = fopen("minusculo.txt", "r");
	f2 = fopen("maiusculo.txt", "w");
	if(f1 == NULL || f2 == NULL){
		printf("Erro na abertura!");
		exit(1);
	}
	char c = fgetc(f1);
	while(c != EOF){
		fputc(toupper(c), f2);//faz parte da biblioteca ctype para devolver letra maiuscula
		c = fgetc(f1);//esta lendo todo o arquivo até ser igual a EOF
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
