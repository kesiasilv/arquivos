#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Ponto;

//calcula a área do triângulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float deter, area;
    deter = ((A.x * B.y) + (A.y * C.x) + (B.x * C.y)) - ((B.y * C.x) + (A.x * C.y) + (A.y * B.x));//calcula o determinante
    area = deter / 2;//calcula a área dividindo o determinante por 2
    return area;
}

//calcula a área do polígono
float AreaPoligono(Ponto *lados, int numLados) {
    float areaTotal = 0.0;
    int i;
    // Dividir o polígono em triângulos e somar as áreas
    for (i = 1; i < numLados - 1; i++) {
        areaTotal += AreaTriangulo(lados[0], lados[i], lados[i + 1]);
    }
    return areaTotal;
}

Ponto* lerVertices(FILE *arquivo, int *numLados) {
    // Ler o número de lados do polígono no arquivo
    fscanf(arquivo, "%d", numLados);

    // Aloca memória 
    Ponto *lados = (Ponto*) malloc(*numLados * sizeof(Ponto));
    if (lados == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    // Ler as coordenadas dos vértices do triangulo, determinadas no arquivo
    int i;
    for (i = 0; i < *numLados; i++) {
        fscanf(arquivo, "%f %f", &lados[i].x, &lados[i].y);
    }
    return lados;
}

int main() {
    int numLados;
	
    FILE *arquivo;//abre arquivo
    arquivo = fopen("TrianguloABC.txt", "r");//abre o arquivo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    Ponto *lados = lerVertices(arquivo, &numLados);//ler os dados do arquivo
    fclose(arquivo);//fecha o arquivo

    float area = AreaPoligono(lados, numLados);//função que calcula a área do polígono
    
    if (area < 0) {
        area *= -1; // Multiplica por -1 para tornar positiva, se caso a área for negativa
    }
    printf("A area do poligono e: %.2f\n", area);//imprime a área do polígono no prompt
   
    // Liberar memória alocada
    free(lados);
    return 0;
}
