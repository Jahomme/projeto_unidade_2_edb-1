#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
No *obter_ultimo_no(No *cabeca)
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
    for (int i = 0; i < pedido->qtd_total_pratos; i++)
    {
        if (strcmp(prato.nome_prato, pedido->pratos[i].nome_prato) == 0)
        { // Verifica se o prato já existe
            pedido->pratos[i].qtd_prato++;
            return;
        }
    }

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
void remover_prato_do_pedido(const char *nome, int qtd, No *pedido)
{
    if (pedido == NULL || pedido->pratos == NULL) {
        printf("Pedido vazio.\n");
        return;
    }

    for (int i = 0; i < pedido->qtd_total_pratos; i++)
    {
        if (strcmp(nome, pedido->pratos[i].nome_prato) == 0)
        {
            if (qtd > pedido->pratos[i].qtd_prato || qtd <= 0)
            {
                printf("Quantidade inválida para remoção.\n");
                return;
            }

            pedido->pratos[i].qtd_prato -= qtd;
            printf("Quantidade do prato removida com sucesso!\n");

            if (pedido->pratos[i].qtd_prato == 0)
            {
                for (int j = i; j < pedido->qtd_total_pratos - 1; j++) //Desloca os pratos para a esquerda.
                {
                    pedido->pratos[j] = pedido->pratos[j + 1];
                }
                pedido->qtd_total_pratos--; //Diminui os pratos existentes no nó.

                if (pedido->qtd_total_pratos > 0)
                {
                    //Rearanja para acomadar a nova quantidade total de pratos no nó.
                    Prato *novo_array = realloc(pedido->pratos, pedido->qtd_total_pratos * sizeof(Prato));
                    if (novo_array != NULL)
                    {
                        pedido->pratos = novo_array;
                    }
                    else
                    {
                        printf("Erro ao realocar memória.\n");
                    }
                }
                else
                {
                    //Não tem mais pratos...
                    free(pedido->pratos);
                    pedido->pratos = NULL;
                }
            }
            return;
        }
    }

    printf("Prato '%s' não encontrado no pedido.\n", nome);
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