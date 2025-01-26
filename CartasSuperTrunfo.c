#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4
#define MAX_CARTAS (NUM_ESTADOS * NUM_CIDADES)

typedef struct {
    char codigo[4]; // Código da carta (ex.: A01)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

Carta cartas[MAX_CARTAS];
int num_cartas = 0;

// Função para calcular propriedades derivadas
void calcular_propriedades(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para cadastrar uma nova carta
void cadastrar_carta() {
    if (num_cartas >= MAX_CARTAS) {
        printf("\nLimite de cartas atingido!\n");
        return;
    }

    Carta nova_carta;

    printf("\nDigite o código da carta (ex.: A01): ");
    scanf("%s", nova_carta.codigo);

    printf("Digite a populacao: ");
    scanf("%d", &nova_carta.populacao);

    printf("Digite a area: ");
    scanf("%f", &nova_carta.area);

    printf("Digite o PIB: ");
    scanf("%f", &nova_carta.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &nova_carta.pontos_turisticos);

    calcular_propriedades(&nova_carta);

    cartas[num_cartas++] = nova_carta;
    printf("\nCarta cadastrada com sucesso!\n");
}

// Função para exibir os dados de todas as cartas
void exibir_cartas() {
    if (num_cartas == 0) {
        printf("\nNenhuma carta cadastrada ainda.\n");
        return;
    }

    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < num_cartas; i++) {
        Carta c = cartas[i];
        printf("\nCodigo: %s\n", c.codigo);
        printf("Populacao: %d\n", c.populacao);
        printf("Area: %.2f\n", c.area);
        printf("PIB: %.2f\n", c.pib);
        printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
        printf("Densidade Populacional: %.2f\n", c.densidade_populacional);
        printf("PIB per capita: %.2f\n", c.pib_per_capita);
    }
}

// Função para comparar duas cartas
void comparar_cartas() {
    if (num_cartas < 2) {
        printf("\nSao necessarias pelo menos duas cartas para comparar.\n");
        return;
    }

    char codigo1[4], codigo2[4];
    printf("\nDigite o codigo da primeira carta: ");
    scanf("%s", codigo1);
    printf("Digite o codigo da segunda carta: ");
    scanf("%s", codigo2);

    Carta *carta1 = NULL, *carta2 = NULL;

    for (int i = 0; i < num_cartas; i++) {
        if (strcmp(cartas[i].codigo, codigo1) == 0) {
            carta1 = &cartas[i];
        } else if (strcmp(cartas[i].codigo, codigo2) == 0) {
            carta2 = &cartas[i];
        }
    }

    if (!carta1 || !carta2) {
        printf("\nUma ou ambas as cartas nao foram encontradas.\n");
        return;
    }

    printf("\nComparacao entre %s e %s:\n", carta1->codigo, carta2->codigo);

    printf("Densidade Populacional: %s\n", carta1->densidade_populacional < carta2->densidade_populacional ? carta1->codigo : carta2->codigo);
    printf("Populacao: %s\n", carta1->populacao > carta2->populacao ? carta1->codigo : carta2->codigo);
    printf("Area: %s\n", carta1->area > carta2->area ? carta1->codigo : carta2->codigo);
    printf("PIB: %s\n", carta1->pib > carta2->pib ? carta1->codigo : carta2->codigo);
    printf("Pontos Turisticos: %s\n", carta1->pontos_turisticos > carta2->pontos_turisticos ? carta1->codigo : carta2->codigo);
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n--- Super Trunfo - Pais ---\n");
        printf("1. Cadastrar carta\n");
        printf("2. Exibir cartas\n");
        printf("3. Comparar cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_carta();
                break;
            case 2:
                exibir_cartas();
                break;
            case 3:
                comparar_cartas();
                break;
            case 0:
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

