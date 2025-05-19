#include <stdio.h>
#include <stdlib.h>
#include "..\include\lista.h"
#include "..\include\prato.h"

// Cria um novo nó pedido e adiciona no final da lista
void criar_novo_no(No **cabeca)
{
    No *novo_no = malloc(sizeof(No));
    if (novo_no == NULL)
    {
        printf("Erro ao alocar memória para novo pedido.\n");
        return;
    }

    novo_no->pratos = NULL;
    novo_no->qtd_total_pratos = 0;
    novo_no->proximo = NULL;

    if (*cabeca == NULL)
    {
        *cabeca = novo_no;
    }
    else
    {
        No *atual = *cabeca;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo_no;
    }
}

// Retorna o último nó da lista
No* obter_ultimo_no(No* cabeca)
{
    if (cabeca == NULL)
        return NULL;

    No *atual = cabeca;
    while (atual->proximo != NULL)
        atual = atual->proximo;
    return atual;
}

// Adiciona um prato ao pedido (nó) passado
void adicionar_prato_ao_pedido(No *pedido, Prato prato)
{
    Prato *temp = realloc(pedido->pratos, (pedido->qtd_total_pratos + 1) * sizeof(Prato));
    if (temp == NULL)
    {
        printf("Erro ao realocar memória para prato.\n");
        return;
    }
    pedido->pratos = temp;
    pedido->pratos[pedido->qtd_total_pratos] = prato;
    pedido->qtd_total_pratos++;
}

// Remove o nó do início da lista e libera memória dos pratos
void remocao_no_inicio_da_lsl(No **cabeca)
{
    if (*cabeca == NULL)
        return;

    No *temp = *cabeca;
    *cabeca = temp->proximo;

    if (temp->pratos != NULL)
        free(temp->pratos);
    free(temp);
}

// Imprime a lista de pedidos e seus pratos
// Função de impressão de valores da lista.
void imprime_a_lsl(No *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  No *atual = cabeca;
  int mesa = 1;
  printf("\n");
  while (atual != NULL)
  {
    printf("Mesa %d:\n", mesa);
    for (int i = 0; i < atual->qtd_total_pratos; i++)
    {
      printf("%s - Quantidade: %d\n", atual->pratos[i].nome_prato, atual->pratos[i].qtd_prato);
    }
    atual = atual->proximo;
    mesa++;
  }
  printf("\n");
}