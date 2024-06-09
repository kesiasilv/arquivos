#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Ponto;

//calcula a �rea do tri�ngulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float deter, area;
    deter = ((A.x * B.y) + (A.y * C.x) + (B.x * C.y)) - ((B.y * C.x) + (A.x * C.y) + (A.y * B.x));//calcula determinante
    area = deter / 2;//area
    return area;
}

//calcula a �rea do pol�gono
float AreaPoligono(Ponto *lados, int numLados) {
    float areaTotal = 0.0;
    int i;
    // Dividir o pol�gono em tri�ngulos e somar as �reas
    for (i = 1; i < numLados - 1; i++) {
        areaTotal += AreaTriangulo(lados[0], lados[i], lados[i + 1]);
    }
    return areaTotal;
}

Ponto* lerVertices(FILE *arquivo, int *numLados) {
    // Ler o n�mero de lados do pol�gono do arquivo
    fscanf(arquivo, "%d", numLados);

    // Aloca mem�ria para os v�rtices
    Ponto *lados = (Ponto*) malloc(*numLados * sizeof(Ponto));
    if (lados == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    // Ler as coordenadas dos v�rtices do triangulo, determinadas no arquivo
    int i;
    for (i = 0; i < *numLados; i++) {
        fscanf(arquivo, "%f %f", &lados[i].x, &lados[i].y);
    }

    return lados;
}

int main() {
    int numLados;
    FILE *arquivo;//abre arquivo
    arquivo = fopen("TrianguloABC.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    Ponto *lados = lerVertices(arquivo, &numLados);//ler os dados do arquivo
    fclose(arquivo);//fecha o arquivo

    float area = AreaPoligono(lados, numLados);//calcula a area do pol�gono
    
    if (area < 0) {
        area *= -1; // Multiplica por -1 para tornar positiva se caso a area for negativa
    }
    printf("A area do poligono e: %.2f\n", area);//imprime a area do poligano no prompt
   
    // Liberar mem�ria alocada
    free(lados);
    return 0;
}

