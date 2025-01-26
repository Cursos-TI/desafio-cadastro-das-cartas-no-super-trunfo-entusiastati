#include <stdio.h>

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

#define NumeroDeCartas 32

void lerDadosCarta(Carta *carta, int indice) {
    printf("\n---- Cadastro da Carta %d ----\n", indice + 1);
    printf("Digite o código da cidade (ex: A01): ");
    scanf("%s", carta->codigo);
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirDadosCarta(const Carta *carta, int indice) {
    printf("\n---- Carta %d ----\n", indice + 1);
    printf("Código: %s\n", carta->codigo);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f milhões\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontosTuristicos);
}

void cadastrarCartas(Carta cartas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        lerDadosCarta(&cartas[i], i);
    }
}

void exibirCartas(const Carta cartas[], int tamanho) {
    printf("\n==== Cartas Cadastradas ====\n");
    for (int i = 0; i < tamanho; i++) {
        exibirDadosCarta(&cartas[i], i);
    }
}

int main() {
    Carta cartas[NumeroDeCartas];

    printf("Bem-vindo ao cadastro do Super Trunfo - Países!\n");

    cadastrarCartas(cartas, NumeroDeCartas);
    exibirCartas(cartas, NumeroDeCartas);

    return 0;
