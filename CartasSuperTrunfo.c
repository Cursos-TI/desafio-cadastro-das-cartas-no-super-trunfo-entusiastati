#include <stdio.h> // Biblioteca para entrada e saída de dados (printf, scanf).
#include <string.h> // Biblioteca para manipulação de strings (strcmp).

// Definição de constantes
#define NUM_ESTADOS 8 // Número total de estados no jogo.
#define NUM_CIDADES 4 // Número de cidades por estado.
#define MAX_CARTAS (NUM_ESTADOS * NUM_CIDADES) // Número máximo de cartas permitido.

// Definição da estrutura que representa uma carta no jogo.
typedef struct {
    char codigo[4]; // Código único da carta (ex.: A01).
    int populacao; // População da cidade/estado.
    float area; // Área em quilômetros quadrados.
    float pib; // Produto Interno Bruto.
    int pontos_turisticos; // Número de pontos turísticos na cidade/estado.
    float densidade_populacional; // Densidade populacional (população/área).
    float pib_per_capita; // PIB per capita (PIB/população).
} Carta;

// Declaração de um vetor para armazenar todas as cartas.
Carta cartas[MAX_CARTAS];
// Contador para acompanhar o número de cartas cadastradas.
int num_cartas = 0;

// Função que calcula propriedades derivadas (densidade e PIB per capita).
void calcular_propriedades(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area; // Calcula densidade.
    carta->pib_per_capita = carta->pib / carta->populacao; // Calcula PIB per capita.
}

// Função para cadastrar uma nova carta no jogo.
void cadastrar_carta() {
    // Verifica se o número máximo de cartas foi atingido.
    if (num_cartas >= MAX_CARTAS) {
        printf("\nLimite de cartas atingido!\n");
        return;
    }

    // Cria uma nova carta temporária.
    Carta nova_carta;

    // Solicita ao usuário os dados da carta.
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

    // Calcula as propriedades derivadas da carta.
    calcular_propriedades(&nova_carta);

    // Adiciona a carta ao vetor de cartas e incrementa o contador.
    cartas[num_cartas++] = nova_carta;
    printf("\nCarta cadastrada com sucesso!\n");
}

// Função para exibir todas as cartas cadastradas.
void exibir_cartas() {
    // Verifica se existem cartas cadastradas.
    if (num_cartas == 0) {
        printf("\nNenhuma carta cadastrada ainda.\n");
        return;
    }

    // Exibe os dados de cada carta.
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

// Função para comparar duas cartas cadastradas.
void comparar_cartas() {
    // Verifica se há pelo menos duas cartas para comparar.
    if (num_cartas < 2) {
        printf("\nSao necessarias pelo menos duas cartas para comparar.\n");
        return;
    }

    // Solicita ao usuário os códigos das cartas a serem comparadas.
    char codigo1[4], codigo2[4];
    printf("\nDigite o codigo da primeira carta: ");
    scanf("%s", codigo1);
    printf("Digite o codigo da segunda carta: ");
    scanf("%s", codigo2);

    // Declara ponteiros para as cartas encontradas.
    Carta *carta1 = NULL, *carta2 = NULL;

    // Busca as cartas no vetor com base nos códigos fornecidos.
    for (int i = 0; i < num_cartas; i++) {
        if (strcmp(cartas[i].codigo, codigo1) == 0) {
            carta1 = &cartas[i];
        } else if (strcmp(cartas[i].codigo, codigo2) == 0) {
            carta2 = &cartas[i];
        }
    }

    // Verifica se ambas as cartas foram encontradas.
    if (!carta1 || !carta2) {
        printf("\nUma ou ambas as cartas nao foram encontradas.\n");
        return;
    }

    // Exibe os resultados das comparações entre as cartas.
    printf("\nComparacao entre %s e %s:\n", carta1->codigo, carta2->codigo);
    printf("Densidade Populacional: %s\n", carta1->densidade_populacional < carta2->densidade_populacional ? carta1->codigo : carta2->codigo);
    printf("Populacao: %s\n", carta1->populacao > carta2->populacao ? carta1->codigo : carta2->codigo);
    printf("Area: %s\n", carta1->area > carta2->area ? carta1->codigo : carta2->codigo);
    printf("PIB: %s\n", carta1->pib > carta2->pib ? carta1->codigo : carta2->codigo);
    printf("Pontos Turisticos: %s\n", carta1->pontos_turisticos > carta2->pontos_turisticos ? carta1->codigo : carta2->codigo);
}

// Função principal do programa.
int main() {
    int opcao; // Variável para armazenar a escolha do usuário.

    do {
        // Exibe o menu principal.
        printf("\n--- Super Trunfo - Pais ---\n");
        printf("1. Cadastrar carta\n");
        printf("2. Exibir cartas\n");
        printf("3. Comparar cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executa a ação correspondente à opção escolhida.
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
    } while (opcao != 0); // Repete o menu até que o usuário escolha sair.

    return 0; // Finaliza o programa.
