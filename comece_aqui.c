#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ultilizando fputc!!
int main(){
	FILE *f;//para trabalhar com arquivos, usa-se um tipo especial de ponteiro(FILE *nome_ponteiro)
	f = fopen("arquivo.txt", "w");//abrindo um arquivo para escrita "w"
	if (f == NULL){//caso encontrar algum erro retorna NULL, e finaliza o programa
		printf("Erro na abertura!\n");
		exit(1);//abortando o programa
	}
	char texto[20] = "Meu programa em c";//string criada para apresentar a mensagem
	int i;
	for(i=0; i<strlen(texto); i++){//strlen calcula o tamanho da string char(texto)
		fputc(texto[i], f);//imprime caractere a caractere
		fputc(' ', f);//caractere com espaço, caso queira imprimir tudo junto só retirar essa linha;
	}
	fclose(f);//fecha o programa
	return 0;
}
