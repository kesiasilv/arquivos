#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Ponto;

//calcula a área do triângulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float deter, area;//variaveis do tipo float deter(determinante) área(area)
    deter = ((A.x * B.y) + (A.y * C.x) + (B.x * C.y)) - ((B.y * C.x) + (A.x * C.y) + (A.y * B.x));//calcula o determinante
    area = deter / 2;//calcula a área dividindo o determinante por 2
    return area;//retorna área
}

//calcula a área do polígono
float AreaPoligono(Ponto *lados, int numLados) {
    float areaTotal = 0.0;//variavel do tipo float para area total
    int i;
    // Dividir o polígono em triângulos e somar as áreas
    for (i = 1; i < numLados - 1; i++) {
        areaTotal += AreaTriangulo(lados[0], lados[i], lados[i + 1]);
    }
    return areaTotal;//retorna a area total
}

Ponto* lerVertices(FILE *arquivo, int *numLados) {
    // Ler o número de lados do polígono no arquivo
    fscanf(arquivo, "%d", numLados);

    // Aloca memória 
    Ponto *lados = (Ponto*) malloc(*numLados * sizeof(Ponto));
    if (lados == NULL) {
        printf("Erro ao alocar memoria\n");//mensagem de erro caso apresente erro ao alocar a memória 
        exit(1);//encerra o programa se apresentar erro ao alocar a memória
    }

    // Ler as coordenadas dos vértices do triangulo, determinadas no arquivo
    int i;
    for (i = 0; i < *numLados; i++) {
        fscanf(arquivo, "%f %f", &lados[i].x, &lados[i].y);
    }
    return lados;//retorna as coordenadas 
}

int main() {
    int numLados;
	
    FILE *arquivo;//abre arquivo
    arquivo = fopen("TrianguloABC.txt", "r");//abre o arquivo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");//mensagem de erro, caso apresente erros ao abrir o arquivo
        return 1;
    }

    Ponto *lados = lerVertices(arquivo, &numLados);//ler os dados do arquivo
    fclose(arquivo);//fecha o arquivo

    float area = AreaPoligono(lados, numLados);//chama a função que calcula a área do polígono
    
    if (area < 0) {
        area *= -1; // Multiplica por -1 para tornar positiva, se caso a área for negativa
    }
    printf("A area do poligono e: %.2f\n", area);//imprime a área do polígono no prompt de comando
   
    // Libera memória alocada
    free(lados);
    return 0;
}
