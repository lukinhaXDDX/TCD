#include <stdio.h>
#include "functions/mainf.h"
#include <stdlib.h>

int main(){

    system("chcp 1252 > nul"); //altera o terminal para portugues

    FILE *fp = NULL;
    char arq[50];

    int opcao = 0, subop = 0;//arquivo a ser carregado

    while (opcao!=5)
    {
  
        menu();
        if (scanf("%d", &opcao) != 1) { // se o que o usuario digitar não for um numero inteiro 
            printf("Entrada inválida!\n");
            while (getchar() != '\n'); // limpa buffer
            opcao = 0;
        }
        switch (opcao){ //switch tem um menor tempo de execução do que varios if's
        
        case 1:
            system("cls");
            fgets(arq, 50, stdin);
            fp = fopen(arq,"r");
            //pedir um nome de um arquivo que está na pasta /TCD/
            break;

        case 2:
            
            system("cls");
            
            if(fp == NULL)
            { //não abriu o arquivo
                printf("Erro ao abrir arquivo.\n");
            }else
            {
                submenu2();
                scanf("%d",&subop);
                switch (subop)
                {
                    case 1:
                        
                        int posicao = buscaLinear(); //PARAMETROS DA F: array do arquivo juntamente o elemento que se quer encontrar
                        if(posicao!=-1){
                            printf("O elemento se encontra na posição %d\n",posicao);
                        }else{
                            printf("Posicao nao encontrada ou nao existente!\n");
                        }
                        break;
                    case 2:
                        
                        int posicao = buscaBin(); //PARAMETROS DA F: array do arquivo juntamente o elemento que se quer encontrar
                        if(posicao!=-1){
                            printf("O elemento se encontra na posição %d\n",posicao);
                        }else{
                            printf("Posicao nao encontrada ou nao existente!\n");
                        }
                        break;
                    
                    default:
                        break;
                }
            }
            break;
        
        case 3:

            system("cls");
            
            if(fp == NULL)
            {    //não abriu o arquivo
                printf("Erro ao abrir arquivo.\n");
            }else
            {
                submenu3();
                scanf("%d",&subop);
                

            }
            

            break;
        
        case 4:

            system("cls");
            //esta opcao so pode ser executada se algum algoritmo for executado anteriormente.

            break;
        
        case 5:
            printf("Saindo\n");
            break;


        default:
            system("cls");
            printf("Opção inválida!\n");
            break;
        }
    }
    
    fclose(fp); //fecha o arquivo aberto
    //A opção 5, antes de ser executada, deverá liberar toda a memora alocada
    

    return 0;
}