#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Ponto;

// Função para calcular a área do triângulo
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float deter, area;
    deter = abs((A.x * B.y) + (A.y * C.x) + (B.x * C.y)) - ((B.y * C.x) + (A.x * C.y) + (A.y * B.x));
	area = deter / 2;
    return area;
}

int main() {
    Ponto A, B, C;
    float area;
    FILE *p;
    p = fopen("TrianguloABC.txt", "w");
    if(p == NULL){
    	printf("Erro ao abrir o arquivo");
    	exit(1);
	}

    // Solicitar as coordenadas dos vértices ao usuário
    printf("Digite as vertices do ponto A: ");
    scanf("%f %f", &A.x, &A.y);

    printf("Digite as vertices do ponto B: ");
    scanf("%f %f", &B.x, &B.y);

    printf("Digite as vertices do ponto C: ");
	scanf("%f %f", &C.x, &C.y);

    area = AreaTriangulo(A, B, C);

    // Exibir o resultado
    fprintf(p,"%.2f %.2f\n", A.x, A.y);
    fprintf(p,"%.2f %.2f\n", B.x, B.y);
    fprintf(p,"%.2f %.2f\n", C.x, C.y);
    
    fprintf(p,"A area do triangulo e: %.2f\n", area);
    
	fclose(p);
    return 0;
}
