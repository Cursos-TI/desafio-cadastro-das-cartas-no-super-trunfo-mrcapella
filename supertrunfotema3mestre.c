/*
Desafio Super Trunfo Paises
Desafio 3 - Nível Mestre
Autor: Marco Roberto Capella Soares
Versão: V1.0
Data: 16/07/2025
*/

//Inclusão das bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
char comparaCarta(int opcao, float valor_1, float valor_2) {
    char resultado;
    if (valor_1 == valor_2) 
        resultado = '0';
    else if (opcao == 5) 
        resultado = (valor_1 > valor_2) ? '2' : '1';
    else 
        resultado = (valor_1 > valor_2) ? '1' : '2';
    
    return resultado;
}

int main() {
    
    //declaração das variáveis, em pares para facilitar o entedimento
    char estado_1[3],estado_2[3];
    char cod_carta_1[5],cod_carta_2[5];
    char nome_cid_1[21],nome_cid_2[21];
    unsigned long int pop_1, pop_2;
    float area_cid_1,area_cid_2;
    float pib_cid_1,pib_cid_2;
    int ponto_tur_1,ponto_tur_2;
    float densidade_1,densidade_2;
    float pib_perc_1,pib_perc_2;
    float super_poder_1,super_poder_2;
    int comparador,atributo;
    int total_carta_1 = 0, total_carta_2 = 0;
    char vencedor, sair = 'n';
    bool continua = false;
    int attr_selecionados[5], total_attr = 6;
    
    //Título da jogo
    printf("..:: Super Trunfo - Países ::..\n");
    printf("\n");
    
    /*
    Quantidade de atributos para Comparação
    Testa se o valor digitado está dentro do permitodo
    Enquanto estiver fora solici um novo valor
    */
    while ((total_attr > 5) || (total_attr < 1)) { 
        printf("Quantos atributos serão comparados (1 a 5): ");
        scanf("%d", &total_attr);
        if ((total_attr > 5) || (total_attr < 1)) {
            printf("Valor inválido!\n");
        }
    }
    
    while ((sair == 'n') || (sair == 'N')) {
        
        //Menu para escolha do primeiro atributo de Comparação
        printf("Escolha o atributo para comparação:\n");
        printf("1 - População:\n");
        printf("2 - Área:\n");
        printf("3 - PIB:\n");
        printf("4 - Pontos turísticos:\n");
        printf("5 - Densidade demográfica\n");
        printf("0 - Sair do jogo\n");
        printf("\n");
        //Fim do menu
        
        int b = 1;
        for (int i = 1; i <= total_attr; i++) {
            
            switch(b) {
                case 1:
                    printf("Primeiro atributo: ");
                break;
                case 2:
                    printf("Segundo atributo: ");
                break;
                case 3:
                    printf("Terceiro atributo: ");
                break;
                case 4:
                    printf("Quarto atributo: ");
                break;
                case 5:
                    printf("Quinto atributo: ");
                break;
            }
            scanf(" %d", &atributo);
            
            if (atributo == 0) {
                
                printf("Confirma a saída do jogo(s/n)? ");
                scanf(" %c", &sair);
                
                if ((sair == 's') || (sair == 'S')) {
                    printf("### Jogo encerrado! ###");
                    return 0;
                } else {
                    sair = 'n';
                    break;
                }
            }
            if (atributo > 5) {
                printf("### Opção inválida! ###");
                return 0;
            }
            
            for (int a = 1; a <= 5 ; a++) {
                if (attr_selecionados[a] == atributo)
                    continua = true;
            }
            
            if (continua == true) {
                printf("Atributo duplicado, selecione outro!\n");
                total_attr++;
            } else {
                attr_selecionados[b] = atributo;
                b++;
            }
            continua = false;
        }
    }
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
    //Fim da leitura da segunda carta 
    
    //Imprime dados da primeira carta
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
    
    //Imprime dados da segunda carta
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
    printf("### Resultado ###\n\n");
    for (int i = 1; i <= total_attr; i++) {
        switch(attr_selecionados[i]) {
            case 1 : 
                vencedor = comparaCarta(1, pop_1, pop_2);
                total_carta_1 += pop_1;
                total_carta_2 += pop_2;
                printf("Atributo População.\n");
                printf("Carta 1 %s(%s): %ld\n", nome_cid_1, estado_1,pop_1);
                printf("Carta 2 %s(%s): %ld\n", nome_cid_2, estado_2,pop_2);
                printf("Carta %c venceu nesse atributo!\n", vencedor);
                printf("\n");
            break;
            case 2 : 
                vencedor = comparaCarta(2, area_cid_1, area_cid_2);
                total_carta_1 += area_cid_1;
                total_carta_2 += area_cid_2;
                printf("Atributo Área.\n");
                printf("Carta 1 %s(%s): %.2f\n", nome_cid_1, estado_1,area_cid_1);
                printf("Carta 2 %s(%s): %.2f\n", nome_cid_2, estado_2,area_cid_2);
                printf("Carta %c venceu nesse atributo!\n", vencedor);
                printf("\n");
            break;
            case 3 : 
                vencedor = comparaCarta(3, pib_cid_1, pib_cid_2);
                total_carta_1 += pib_cid_1;
                total_carta_2 += pib_cid_2;
                printf("Atributo PIB.\n");
                printf("Carta 1 %s(%s): %.2f\n", nome_cid_1, estado_1, pib_cid_1);
                printf("Carta 2 %s(%s): %.2f\n", nome_cid_2, estado_2, pib_cid_2);
                printf("Carta %c venceu nesse atributo!\n", vencedor);
                printf("\n");
            break;
            case 4 : 
                vencedor = comparaCarta(4, ponto_tur_1, ponto_tur_2);
                total_carta_1 += ponto_tur_1;
                total_carta_2 += ponto_tur_2;
                printf("Atributo Pontos turísticos.\n");
                printf("Carta 1 %s(%s): %d\n", nome_cid_1, estado_1, ponto_tur_1);
                printf("Carta 2 %s(%s): %d\n", nome_cid_2, estado_2, ponto_tur_2);
                printf("Carta %c venceu nesse atributo!\n", vencedor);
                printf("\n");
            break;
            case 5 :
                vencedor = comparaCarta(5, densidade_1, densidade_2);
                total_carta_1 += densidade_1;
                total_carta_2 += densidade_2;
                printf("Atributo Densidade demográfica.\n");
                printf("Carta 1 %s(%s): %.2f\n", nome_cid_1, estado_1, densidade_1);
                printf("Carta 2 %s(%s): %.2f\n", nome_cid_2, estado_2, densidade_2);
                printf("Carta %c venceu nesse atributo!\n", vencedor);
                printf("\n");
            break;
        }
    }//Fim da comparação
    vencedor = comparaCarta(1, total_carta_1, total_carta_2);
    printf("Carta %c venceu na soma total dos atributos!\n", vencedor);
} //Fim do código
