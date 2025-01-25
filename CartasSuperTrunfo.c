#include <stdio.h>
#include <string.h>


typedef struct {
    char codigo[4];     
    int populacao;     
    float area;        
    float pib;       
    int pontosTuristicos; 
} Carta;

#define NUM_CARTAS 32

void cadastrarCartas(Carta cartas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n---- Cadastro da Carta %d ----\n", i + 1);
        
        
        printf("Digite o código da cidade: ");
        scanf("%s", cartas[i].codigo);


        printf("Digite a população: ");
        scanf("%d", &cartas[i].populacao);


        printf("Digite a área (em km²): ");
        scanf("%f", &cartas[i].area);


        printf("Digite o PIB (em milhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }
}

void exibirCartas(Carta cartas[], int tamanho) {
    printf("\n==== Cartas Cadastradas ====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("\n---- Carta %d ----\n", i + 1);
        printf("Código: %s\n", cartas[i].codigo);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f milhões\n", cartas[i].pib);
        printf("Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
    }
}

int main() {
    Carta cartas[NUM_CARTAS];

    printf("Bem-vindo ao cadastro do Super Trunfo - Países!\n");


    cadastrarCartas(cartas, NUM_CARTAS);


    exibirCartas(cartas, NUM_CARTAS);

    return 0;
}