#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo; 
    struct no *esq, *dir;
}No;
// INSERÇÃO
No* inserir(No* raiz, int valor){
  if(raiz == NULL){
    No *novo = (No*)malloc(sizeof(No)); 
    novo->conteudo = valor; 
    novo->esq = NULL; 
    novo->dir = NULL; 
  }
  else{
    if(valor < raiz->conteudo)
      raiz->esq = inserir(raiz->dir, valor);
    if(valor > raiz->conteudo)
      raiz->esq = inserir(raiz->dir, valor);
    return raiz;
  }
}
// Contar o tamanho da subárvore esquerda.
int tamSubArvEsqCont(No *raiz) {
    if (raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL))
        return 0;
    else
        return tamSubArvEsqCont(raiz->esq) + 1 + tamSubArvEsqCont(raiz->esq->dir);
}
// Desconsiderar a Raiz na contagem
int tamSubArvEsq(No *raiz) {
    int t = tamanhoSubArvoreEsquerdaCont(raiz);
    return t - 1;
}
// MOSTRAR A ARVORE BINARIA
void imprimir(No *raiz){ 
  if(raiz != NULL){ 
    imprimir(raiz->esq); 
    printf("%d ", raiz->conteudo); 
    imprimir(raiz->dir); 
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
        imprimir(raiz); // função impressão
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
