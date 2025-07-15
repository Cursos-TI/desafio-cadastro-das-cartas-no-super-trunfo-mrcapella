/*
Desafio Super Trunfo Paises
Tema 3 - Nível Novato
Autor: Marco Roberto Capella Soares
Versão: V1.1
Data: 15/07/2025
*/
#include <stdio.h>

//function para o cálculo do PIB per capta e da densidade demográfica
float calculaDensidadePib(float valor, float base) {
    return (float)(valor/base);
}

//function para o cálculo do super poder
float calculaSuperPoder(long int pop, float area, float pib, int pturistico, float ppc, float densidade) {
    float densidade_invertida = (1/densidade);
    return (float)(pop+area+pib+pturistico+ppc+densidade_invertida);
}

//function para a comparação de cada atributo numérico das cartas
char comparaCarta(float valor_1, float valor_2) {
    char resultado;
    
    if (valor_1 > valor_2)
        resultado = '1';
    else
        resultado = '2';
        
    return resultado;
}

int main() {
    //declaração das variáveis, em pares para facilitar o entedimento
    char estado_1[3],estado_2[3];
    char cod_carta_1[5],cod_carta_2[5];
    char nome_cid_1[20],nome_cid_2[20];
    unsigned long int pop_1, pop_2;
    float area_cid_1,area_cid_2;
    float pib_cid_1,pib_cid_2;
    int ponto_tur_1,ponto_tur_2;
    float densidade_1,densidade_2;
    float pib_perc_1,pib_perc_2;
    float super_poder_1,super_poder_2;
    int comparador;
    char vencedor;

    //Título da jogo
    printf("..::Super Trunfo - Países::..\n");
    printf("\n");
    
    //leitura dos valores da primeira carta
    printf("Informe os dados da primeira carta.\n");
    printf("Digite o estado:\n");
    scanf("%s", estado_1);
    printf("Digite o código da carta:\n");
    scanf("%s", cod_carta_1);
    printf("Digite o nome da cidade:\n");
    scanf("%s", nome_cid_1);
    printf("Digite a população:\n");
    scanf("%ld", &pop_1);
    printf("Digite a área em Km2:\n");
    scanf("%f", &area_cid_1);
    printf("Digite o PIB:\n");
    scanf("%f", &pib_cid_1);
    printf("Digite o total de pontos turísticos:\n");
    scanf("%d", &ponto_tur_1);
    printf("\n");
    densidade_1 = calculaDensidadePib(pop_1,area_cid_1);
    pib_perc_1 = calculaDensidadePib(pib_cid_1,pop_1);
    super_poder_1 = calculaSuperPoder(pop_1,area_cid_1,pib_cid_1,ponto_tur_1,pib_perc_1,densidade_1);
    //fim da leitura da primeira carta
    
   
    //leitura dos valores da segunda carta
    //nome_cid_2 = "teste";
    printf("Informe os dados da segunda carta.\n");
    printf("Digite o estado:\n");
    scanf("%s", estado_2);
    printf("Digite o código da carta:\n");
    scanf("%s", cod_carta_2);
    printf("Digite o nome da cidade:\n");
    scanf("%s", nome_cid_2);
    printf("Digite a população:\n");
    scanf("%ld", &pop_2);
    printf("Digite a área em Km2:\n");
    scanf("%f", &area_cid_2);
    printf("Digite o PIB:\n");
    scanf("%f", &pib_cid_2);
    printf("Digite o total de pontos turísticos:\n");
    scanf("%d", &ponto_tur_2);
    densidade_2 = calculaDensidadePib(pop_2,area_cid_2);
    pib_perc_2 = calculaDensidadePib(pib_cid_2,pop_2);
    super_poder_2 = calculaSuperPoder(pop_2,area_cid_2,pib_cid_2,ponto_tur_2,pib_perc_2,densidade_2);
    printf("\n");
    //fim da leitura da segunda carta 
    
    //imprime dados da primeira carta
    printf("*** Carta 1 ***\n");
    printf("Estado: %s\n", estado_1);
    printf("Código da carta: %s%s\n", estado_1, cod_carta_1);
    printf("Cidade: %s\n", nome_cid_1);
    printf("População: %ld\n", pop_1);
    printf("Área em km2: %.2f\n", area_cid_1);
    printf("PIB: %.2f\n", pib_cid_1);
    printf("Pontos turísticos: %d\n", ponto_tur_1);
    printf("Densidade demográfica: %.2f\n", densidade_1);
    printf("PIB per capta: %.2f\n", pib_perc_1);
    printf("Super poder: %.2f\n", super_poder_1);
    printf("\n");
    
    //imprime dados da segunda carta
    printf("*** Carta 2 ***\n");
    printf("Estado: %s\n", estado_2);
    printf("Código da carta: %s%s\n", estado_2, cod_carta_2);
    printf("Cidade: %s\n", nome_cid_2);
    printf("População: %ld\n", pop_2);
    printf("Área em km2: %.2f\n", area_cid_2);
    printf("PIB: %.2f\n", pib_cid_2);
    printf("Pontos turísticos: %d\n", ponto_tur_2);
    printf("Densidade demográfica %.2f\n", densidade_2);
    printf("PIB per capta %.2f\n", pib_perc_2);
    printf("Super poder: %.2f\n", super_poder_2);
    printf("\n");
    
    //chama a function comparaCarta para comparar os valores do atributo
    vencedor = comparaCarta(pib_cid_1, pib_cid_2);
    
    //imprime o resultado da comparação entre as cartas
    printf("Comparação de cartas (Atributo PIB)\n");
    printf("Carta 1 %s(%s): %.2f\n", nome_cid_1, estado_1,pib_cid_1);
    printf("Carta 2 %s(%s): %.2f\n", nome_cid_2, estado_2,pib_cid_2);
    printf("A carta vencedora é %c: ", vencedor);
}
