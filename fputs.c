#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f;
	f = fopen("hello.txt", "w");
	
	if(f == NULL){
		printf("Erro na abertura");
		exit(1);
	}
	fputs("hello ", f);
	fputs("word!", f);
	fclose(f);
	return 0;

}
