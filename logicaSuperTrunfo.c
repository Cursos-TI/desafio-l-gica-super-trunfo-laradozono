#include <stdio.h>

// Definição da estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4];         // Ex: "A01"
    char cidade[50];        // Nome da cidade
    int populacao;          // Número de habitantes
    float area;             // Área em km²
    float pib;              // PIB em bilhões de reais
    int pontosTuristicos;   // Número de pontos turísticos
} Carta;

// Função para exibir os dados de uma carta
void exibirCarta(Carta c, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
}

int main() {
    // Declaração de duas cartas
    Carta carta1, carta2;

    // ===== ENTRADA DOS DADOS DA CARTA 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Digite o Código da Carta (Ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta1.cidade);

    printf("Digite a População: ");
    scanf("%d", &carta1.populacao);

    printf("Digite a Área (km²): ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // ===== ENTRADA DOS DADOS DA CARTA 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Digite o Código da Carta (Ex: B02): ");
    scanf("%s", carta2.codigo);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta2.cidade);

    printf("Digite a População: ");
    scanf("%d", &carta2.populacao);

    printf("Digite a Área (km²): ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // ===== EXIBIÇÃO DAS CARTAS =====
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // ===== CÁLCULOS DERIVADOS =====
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    float pibPerCapita1 = (carta1.pib * 1000000000) / carta1.populacao;
    float pibPerCapita2 = (carta2.pib * 1000000000) / carta2.populacao;

    printf("\n=== Cálculos Adicionais ===\n");
    printf("Carta 1 - %s: Densidade Populacional = %.2f hab/km² | PIB per capita = R$ %.2f\n",
           carta1.cidade, densidade1, pibPerCapita1);
    printf("Carta 2 - %s: Densidade Populacional = %.2f hab/km² | PIB per capita = R$ %.2f\n",
           carta2.cidade, densidade2, pibPerCapita2);

    // ===== COMPARAÇÃO ENTRE AS CARTAS =====
    // Escolha do atributo a ser comparado:
    // Pode ser: populacao, area, pib, densidade populacional ou pib per capita
    // Comparando o PIB per capita como exemplo

    printf("\n=== Comparação de Cartas (Atributo: PIB per Capita) ===\n");

    if (pibPerCapita1 > pibPerCapita2) {
        printf("Carta 1 - %s (R$ %.2f) venceu!\n", carta1.cidade, pibPerCapita1);
        printf("Carta 2 - %s (R$ %.2f)\n", carta2.cidade, pibPerCapita2);
    } 
    else if (pibPerCapita2 > pibPerCapita1) {
        printf("Carta 2 - %s (R$ %.2f) venceu!\n", carta2.cidade, pibPerCapita2);
        printf("Carta 1 - %s (R$ %.2f)\n", carta1.cidade, pibPerCapita1);
    } 
    else {
        printf("Empate! Ambas as cartas têm o mesmo PIB per capita (R$ %.2f)\n", pibPerCapita1);
    }

    return 0;
}