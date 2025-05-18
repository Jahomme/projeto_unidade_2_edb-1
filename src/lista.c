#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "..\include\lista.h"

// Função de inserção no início da lista.
void insercao_no_inicio_da_lsl(No **cabeca, const Prato prato)
{
  No *novo_no = malloc(sizeof(No));

  novo_no->prato = prato;

  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
}

// Função de inserção no fim da lista.
void insercao_no_fim_da_lsl(No **cabeca, const Prato prato)
{
  No *novo_no = malloc(sizeof(No));
  novo_no->prato = prato;

  novo_no->proximo = NULL;

  if (*cabeca == NULL)
  {
    *cabeca = novo_no;
    return;
  }

  No *atual = *cabeca;

  while (atual->proximo != NULL)
  {
    atual = atual->proximo;
  }

  atual->proximo = novo_no;
}

// Função de inserção em uma posição intermediária da lista.
void insercao_no_meio_da_lsl(No **cabeca, const Prato prato, int posicao)
{
  if (posicao == 0)
  {
    insercao_no_inicio_da_lsl(cabeca, prato);
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;
  int i = 0;

  while (atual != NULL && i < posicao)
  {
    anterior = atual;
    atual = atual->proximo;
    i++;
  }

  if (atual == NULL)
  {
    printf("Posição inválida!\n");
    return;
  }

  No *novo_no = malloc(sizeof(No));
  novo_no->prato = prato;
  novo_no->proximo = atual;

  if (anterior != NULL)
  {
    anterior->proximo = novo_no;
  }
  else
  {
    *cabeca = novo_no;
  }
}

// Função de remoção no início da lista.
void remocao_no_inicio_da_lsl(No **cabeca)
{
  if (*cabeca == NULL)
  {
    printf("A lista está vazia!\n");
    return;
  }

  No *temp = *cabeca;
  *cabeca = (*cabeca)->proximo;
  free(temp);
}

// Função de remoção no fim da lista.
void remocao_no_fim_da_lsl(No **cabeca)
{
  if (*cabeca == NULL || (*cabeca)->proximo == NULL)
  {
    remocao_no_inicio_da_lsl(cabeca);
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while (atual->proximo != NULL)
  {
    anterior = atual;
    atual = atual->proximo;
  }

  anterior->proximo = NULL;

  free(atual);
}

// Função de remoção em uma posição intermediária da lista.
void remocao_no_meio_da_lsl(No **cabeca, const Prato prato)
{
  if (*cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while (atual != NULL)
  {
    // Comparar prato atual com o prato recebido — suposição: comparar pelo nome
    if (strcmp(atual->prato.nome_prato, prato.nome_prato) == 0)
    {
      // Nó encontrado: remover
      if (anterior == NULL)
      {
        *cabeca = atual->proximo;
      }
      else
      {
        anterior->proximo = atual->proximo;
      }
      free(atual);
      printf("Prato %s removido da lista.\n", prato.nome_prato);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }
  printf("Prato %s não encontrado na lista.\n", prato.nome_prato);
}

// Busca por prato na lista
void busca_por_valor_na_lsl(No *cabeca, const Prato prato)
{
  No *atual = cabeca;

  while (atual != NULL)
  {
    if (strcmp(atual->prato.nome_prato, prato.nome_prato) == 0)
    {
      printf("Prato %s encontrado!\n", prato.nome_prato);
      return;
    }
    atual = atual->proximo;
  }

  printf("Prato %s não encontrado!\n", prato.nome_prato);
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
void imprime_a_lsl(No *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  No *atual = cabeca;

  while (atual != NULL)
  {
    printf("%s - Quantidade: %d\n", atual->prato.nome_prato, atual->prato.qtd_prato);
    atual = atual->proximo;
  }
  printf("\n");
}

// funcao para retornar uma copia da lista original
No* copiar_lista(No* original) {
    if (original == NULL) return NULL;

    No* nova_lista = NULL;
    No* atual = original;

    while (atual != NULL) {
        insercao_no_fim_da_lsl(&nova_lista, atual->prato);
        atual = atual->proximo;
    }

    return nova_lista;
}