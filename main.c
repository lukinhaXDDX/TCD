#include <stdio.h>
#include "functions/mainf.h"
#include "functions/buscaf.h"
#include "functions/ordenaf.h"
#include <stdlib.h>

int main()
{

    system("chcp 1252 > nul"); //altera o terminal para portugues

    FILE *fp = NULL; // arquivo nao aberto ainda
    int tam=1; // tamanho inicial do vetor
    int *vet=(int*)malloc(tam*sizeof(int));
    int i=0; // variavel para rodar o vetor ao ser editado
    int elemento; // elemento a ser procurado no vetor
    char arq[50]; // nome do arquivo
    int resultado;
    int opcao = 0, subop = 0;//arquivo a ser carregado

    while (opcao!=5)
    {
  
        menu();
        if (scanf("%d", &opcao) != 1) 
        { // se o que o usuario digitar não for um numero inteiro 
            printf("Entrada inválida!\n");
            while (getchar() != '\n'); // limpa buffer
            opcao = 0;
        }
        switch (opcao)
        { //switch tem um menor tempo de execução do que varios if's
        
            case 1:
                system("cls");
                printf("Insira o nome do arquivo:\n ");
                fgets(arq, 50, stdin);
                fp = fopen(arq,"r");
                //pedir um nome de um arquivo que está na pasta /TCD/
                while(fscanf(fp,"%d",&vet[i])!=NULL) // pegar os dados dentro do arquivo e passar para o vetor
                {
                    i++; // rodar o vetor
                    tam++; // aumentar o tamanho
                    fp = realloc(fp,tam*sizeof(int));
                }
                fp = realloc(fp,(tam-1)*sizeof(int));//reajustar o tamanho para nao sobrar nada
                break;

            case 2:
            
                system("cls");
            
                if(fp == NULL){ //não abriu o arquivo
                    printf("Erro ao abrir arquivo.\n");
                    break;
                }
                else
                {
                    submenu2();
                    printf("Insira uma opcao: \n"); // escolha de qual tipo de busca
                    scanf("%d",&subop);
                    printf("Qual elemento voce deseja procurar?\n"); // escolha do que buscar
                    scanf("%d",&elemento);
                }
                switch(subop)
                {
                    case 1: // usar a busca linear
                
                        resultado = buscaLinear(vet,elemento,tam);
                        break;
                        switch(resultado)
                        {
                            case -1:  // funcao retorna -1 caso o numero nao fora achado                           
                                printf("Esse numero nao esta no array!\n");
                                break;                           
                            default :// retornou um positivo, ou seja, a posicao dele no vetor                           
                                printf("O numero esta na posicao %d\n",resultado);
                                break;                                
                        }
                    
                    case 2: // usar a busca binaria
                    
                        
                        resultado = buscaBin(vet,elemento,tam);
                        switch(resultado)
                        { 
                            case -2: // funcao retorna -2 caso o array nao esteja ordenado
                                printf("array nao ordenado!\n");
                                break;                           
                            case -1:// funcao retorna -1 caso o valor nao esteja                           
                                printf("Valor nao encontrado no array\n");
                                break;                                                    
                            default:// ultima opcao de retorno da função, um numero positivo, ou seja, a posicao no vetor
                            
                                printf("Valor na posicao %d\n",resultado);   
                                break;   
                            
                        }                   
                    default :                   
                        printf("Opcao inexistente\n");
                        break;              
                }
            case 3:
            
                system("cls");    
                if(fp == NULL) // nao abriu o arquivo
                {    
                    printf("Erro ao abrir arquivo.\n");
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
                printf("Opcao invalida!\n");
                break;
        }
    }
    
    
    fclose(fp); //fecha o arquivo aberto
    //A opção 5, antes de ser executada, deverá liberar toda a memora alocada
        return 0;
}
