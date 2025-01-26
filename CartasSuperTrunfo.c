#include <stdio.h>
#include <string.h>

// Definição da struct Carta
typedef struct {
    char codigo[4];     // Código da carta (ex: A01)
    int populacao;      // População da cidade
    float area;         // Área da cidade
    float pib;          // PIB da cidade
    int pontosTuristicos; // Número de pontos turísticos
} Carta;

#define NUM_CARTAS 32

void cadastrarCartas(Carta cartas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n---- Cadastro da Carta %d ----\n", i + 1);
        
        // Código da carta
        printf("Digite o código da cidade (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        // População
        printf("Digite a população: ");
        scanf("%d", &cartas[i].populacao);

        // Área
        printf("Digite a área (em km²): ");
        scanf("%f", &cartas[i].area);

        // PIB
        printf("Digite o PIB (em milhões): ");
        scanf("%f", &cartas[i].pib);

        // Número de pontos turísticos
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

    // Cadastrar as cartas
    cadastrarCartas(cartas, NUM_CARTAS);

    // Exibir as cartas cadastradas
    exibirCartas(cartas, NUM_CARTAS);

    return 0;
}
}