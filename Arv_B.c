#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int conteudo; 
    struct no *sae, *sad; // Ponteiros para os campos ESQ e DIR
}No;
// INSERÇÃO VERSÃO CURTA, SEM USAR A STRUCT ARVORE
No* inserir(No* raiz, int valor){
  if(raiz == NULL){
    No *novo = (No*)malloc(sizeof(No)); 
    novo->conteudo = valor; 
    novo->sae = NULL; 
    novo->sad = NULL; 
  }
  else{
    if(valor < raiz->conteudo)
      raiz->sae = inserir(raiz->sae, valor);
    if(valor > raiz->conteudo)
      raiz->sad = inserir(raiz->sad, valor);
    return raiz;
  }
}
// Conta o tamanho da subárvore esquerda.
int tamSubArvEsqCont(No *raiz) {
    if (raiz == NULL || (raiz->sae == NULL && raiz->sad == NULL))
        return 0;
    return tamSubArvEsqCont(raiz->sae) + 1 + tamSubArvEsqCont(raiz->sae->sad);
}

int tamSubArvEsq(No *raiz) {
    int t = tamSubArvEsqCont(raiz);
    return t - 1;
}
// MOSTRAR A ARVORE BINARIA
void show(No *raiz){ 
  if(raiz != NULL){ 
    printf("%d ", raiz->conteudo); 
    show(raiz->sae); 
    show(raiz->sad); 
  }
}

int main(){
    int opcao, valor; 

    No *raiz = NULL; // Iniciando a Arv sem precisa da Struct Raiz
    do{
      printf("MENU ARVORE\n0 - sair\n1 - Inserir\n2 - Imprimir\n3 - Tamanho"
             "\nOpcao: "); // menu
      scanf("%d", &opcao); 
      switch (opcao)
      {
      case 0: // SAIR
        printf("\nSaindo...\n");
        break;
      case 1: // INSERÇÃO
        printf("\nDigite um valor: \n");
        scanf("%d", &valor);
        raiz = inserir(raiz, valor);
        printf("\n");
        break;
      case 2: // IMPRESSÃO
        printf("\nImpressao da Arvore Binaria:\n");
        show(raiz); // função impressão
        printf("\n");
        break;
        case 3: // TAMANHO
        printf("Tamanho: %d\n", tamSubArvEsq(raiz));
        printf("\n");
        break;
      default:
        printf("\nOpcao Invalida!\n");
        break;
      }
    }while(opcao != 0); // opção para saida
}
