#include <stdio.h>

//function para o cálculo do PIB per capta e da densidade demográfica
float calculoDensidadePib(float valor, float base) {
    float valor_calulado;
    valor_calulado = valor/base;
    return valor_calulado;
}

int main() {
    //declaração das variáveis, em pares para facilitar o entedimento
    char estado_1, estado_2;
    char cod_carta_1[3],cod_carta_2[3];
    char nome_cid_1[20],nome_cid_2[20];
    int pop_1,pop_2;
    float area_cid_1,area_cid_2;
    float pib_cid_1,pib_cid_2;
    int ponto_tur_1,ponto_tur_2;
    float densidade_1, densidade_2;
    float pib_perc_1, pib_perc_2;
    
    //Título da jogo
    printf("***Super Trunfo - Cidades***\n\n");
    //leitura dos valores da primeira carta
    printf("Informe os dados da primeira carta.\n\n");
    printf("Digite o estado:\n");
    scanf("%c", &estado_1);
    printf("Digite o código da carta:\n");
    scanf("%s", &cod_carta_1);
    printf("Digite o nome da cidade:\n");
    scanf("%s", &nome_cid_1);
    printf("Digite a população:\n");
    scanf("%d", &pop_1);
    printf("Digite a área em Km2:\n");
    scanf("%f", &area_cid_1);
    printf("Digite o PIB:\n");
    scanf("%f", &pib_cid_1);
    printf("Digite o total de pontos turísticos:\n");
    scanf("%d", &ponto_tur_1);
    densidade_1 = calculoDensidadePib(pop_1,area_cid_1);
    pib_perc_1 = calculoDensidadePib(pib_cid_1,pop_1);
    //fim da leitura da primeira carta

    //leitura dos valores da segunda carta
    printf("Informe os dados da segunda carta.\n\n");
    printf("Digite o estado:\n");
    scanf(" %c", &estado_2);
    printf("Digite o código da carta:\n");
    scanf("%s", &cod_carta_2);
    printf("Digite o nome da cidade:\n");
    scanf("%s", &nome_cid_2);
    printf("Digite a população:\n");
    scanf("%d", &pop_2);
    printf("Digite a área em Km2:\n");
    scanf("%f", &area_cid_2);
    printf("Digite o PIB:\n");
    scanf("%f", &pib_cid_2);
    printf("Digite o total de pontos turísticos:\n");
    scanf("%d", &ponto_tur_2);
    densidade_2 = calculoDensidadePib(pop_2,area_cid_2);
    pib_perc_2 = calculoDensidadePib(pib_cid_2,pop_2);
    //fim da leitura da segunda carta

    //imprime dados da primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado_1);
    printf("Código da carta: %c%s\n", estado_1,cod_carta_1);
    printf("Cidade: %s\n", nome_cid_1);
    printf("População: %d\n", pop_1);
    printf("Área em km2: %.2f\n", area_cid_1);
    printf("PIB: %.2f\n", pib_cid_1);
    printf("Pontos turísticos %d\n", ponto_tur_1);
    printf("Densidade demográfica %.2f\n", densidade_1);
    printf("PIB per capta %.2f\n\n", pib_perc_1);
    
    //imprime dados da segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado_2);
    printf("Código da carta: %c%s\n", estado_2,cod_carta_2);
    printf("Cidade: %s\n", nome_cid_2);
    printf("População: %d\n", pop_2);
    printf("Área em km2: %.2f\n", area_cid_2);
    printf("PIB: %.2f\n", pib_cid_2);
    printf("Pontos turísticos %d\n", ponto_tur_2);
    printf("Densidade demográfica %.2f\n", densidade_2);
    printf("PIB per capta %.2f\n\n", pib_perc_2);
    return 0;
}
