#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "include\lista.h"

// Declaração da estrutura 'no'.
struct no{
  char *prato;
  struct no *proximo;
};

// Definição do tipo 'No'.
typedef struct no No;


// Função de inserção no início da lista.
void insercao_no_inicio_da_lsl(No **cabeca, const char *prato){
  No *novo_no = malloc(sizeof(No));
  novo_no->prato = malloc(strlen(prato) + 1);
  strcpy(novo_no->prato, prato);
  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
}


// Função de inserção no fim da lista.
void insercao_no_fim_da_lsl(No **cabeca, const char *prato){
  No *novo_no = malloc(sizeof(No));
  novo_no->prato = malloc(strlen(prato) + 1);
  strcpy(novo_no->prato, prato);

  novo_no->proximo = NULL;

  if(*cabeca == NULL){
    *cabeca = novo_no;
    return;
  }
  
  No *atual = *cabeca;

  while(atual->proximo != NULL) {
    atual = atual->proximo;
  }
  
  atual->proximo = novo_no;
}


// Função de inserção em uma posição intermediária da lista.
void insercao_no_meio_da_lsl(No **cabeca, const char *prato, int posicao){
  if(posicao == 0){
    insercao_no_inicio_da_lsl(cabeca, prato);
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;
  int i = 0;

  while(atual != NULL && i < posicao){
    anterior = atual;
    atual = atual->proximo;
    i++;
  }

  if(atual == NULL) {
    printf("Posição inválida!\n");
    return;
  }

  No *novo_no = malloc(sizeof(No));
  novo_no->prato = malloc(strlen(prato) + 1);
  strcpy(novo_no->prato, prato);
  novo_no->proximo = atual;

  if(anterior != NULL){
    anterior->proximo = novo_no;
  }else{
    *cabeca = novo_no;
  }
}


// Função de remoção no início da lista.
void remocao_no_inicio_da_lsl(No **cabeca){
  if(*cabeca == NULL){
    printf("A lista está vazia!\n");
    return;
  }

  No *temp = *cabeca;
  *cabeca = (*cabeca)->proximo;
  free(temp->prato);
  free(temp);
}


// Função de remoção no fim da lista.
void remocao_no_fim_da_lsl(No **cabeca){
  if(*cabeca == NULL || (*cabeca)->proximo == NULL){
    remocao_no_inicio_da_lsl(cabeca);
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while(atual->proximo != NULL){
    anterior = atual;
    atual = atual->proximo;
  }

  anterior->proximo = NULL;

  free(atual->prato);
  free(atual);
}


// Função de remoção em uma posição intermediária da lista.
void remocao_no_meio_da_lsl(No **cabeca, const char *prato){
  if(*cabeca == NULL){
    printf("Lista vazia!\n");
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while(atual != NULL && strcmp(atual->prato, prato) != 0){
    anterior = atual;
    atual = atual->proximo;
  }

  if(atual == NULL){
    printf("Valor inexistente na lista!\n");
    return;
  }

  if(anterior == NULL){
    *cabeca = atual->proximo;
  }else{
    anterior->proximo = atual->proximo;
  }

  free(atual->prato);
  free(atual);
}


// Função de busca por valor na lista.
void busca_por_valor_na_lsl(No *cabeca, const char *prato){
  No *atual = cabeca;

  while(atual != NULL && strcmp(atual->prato, prato) != 0){
    atual = atual->proximo;
  }
  
  if(atual != NULL)
    printf("Prato %s encontrado!\n", prato);
  else
   printf("Prato %s não encontrado!\n", prato);
}


// Função de varredura da lista.
// void percorre_a_lsl(No *cabeca){
//   No *atual = cabeca;
//   int total = 0;

//   while(atual != NULL){
//     total = total + atual->prato;
//     atual = atual->proximo;
//   }
//   printf("Total = %d.\n", total);
// }


// Função de impressão de valores da lista.
void imprime_a_lsl(No *cabeca) {
  if(cabeca == NULL){
    printf("Lista vazia!\n");
    return;
  }

  No *atual = cabeca;
  
  while(atual != NULL){
    printf("%s ", atual->prato);
    atual = atual->proximo;
  }
  printf("\n");
}