#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista.h"
#include "../include/prato.h"

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

// funcao para retornar uma copia da lista original
No *copiar_no(No *original)
{
    if (original == NULL)
    {
        return NULL;
    }

    No *copia = malloc(sizeof(No));
    copia->qtd_total_pratos = original->qtd_total_pratos;

    if (original->qtd_total_pratos > 0) // Averiguando se há pratos na lista
    {
        copia->pratos = malloc(original->qtd_total_pratos * sizeof(Prato)); // Alocando espaço para caber os pratos
        if (copia->pratos == NULL)
        {
            printf("Erro ao alocar memória para os pratos.\n");
            free(copia);
            return NULL;
        }

        for (int i = 0; i < original->qtd_total_pratos; i++)
        {
            copia->pratos[i].qtd_prato = original->pratos[i].qtd_prato;

            copia->pratos[i].nome_prato = malloc(strlen(original->pratos[i].nome_prato) + 1);
            if (copia->pratos[i].nome_prato == NULL)
            {
                printf("Erro ao alocar memória para nome do prato.\n");
                // Libera tudo o que já foi alocado antes
                for (int j = 0; j < i; j++)
                {
                    free(copia->pratos[j].nome_prato);
                }
                free(copia->pratos);
                free(copia);
                return NULL;
            }
            strcpy(copia->pratos[i].nome_prato, original->pratos[i].nome_prato);
        }
    }
    else
    {
        copia->pratos = NULL;
    }

    copia->proximo = NULL;
    return copia;
}

void remover_no(No **cabeca, No *alvo)
{
    if (*cabeca == NULL || alvo == NULL)
    {
        return;
    }

    No *anterior = NULL;
    No *atual = *cabeca;

    if (atual == alvo)
    {
        *cabeca = atual->proximo; // Aponte para o próximo
    }
    else
    {
        while (atual->proximo != NULL && atual != alvo)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == NULL)
        {
            return; // Nó não encotrado
        }

        // Remove o nó da lista
        anterior->proximo = atual->proximo;
    }

    if (alvo->pratos != NULL)
    {
        free(alvo->pratos);
    }
    free(alvo);
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
    if (pedido == NULL || pedido->pratos == NULL)
    {
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
                free(pedido->pratos[i].nome_prato);

                for (int j = i; j < pedido->qtd_total_pratos - 1; j++) // Desloca os pratos para a esquerda.
                {
                    pedido->pratos[j] = pedido->pratos[j + 1];
                }
                pedido->qtd_total_pratos--; // Diminui os pratos existentes no nó.

                if (pedido->qtd_total_pratos > 0)
                {
                    // Rearanja para acomadar a nova quantidade total de pratos no nó.
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
                    // Não tem mais pratos...
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
void remocao_no_inicio(No **cabeca)
{
    if (*cabeca == NULL)
    {
        return;
    }

    No *temp = *cabeca;
    *cabeca = temp->proximo;

    if (temp->pratos != NULL)
    {
        free(temp->pratos);
    }
    free(temp);
}

// Imprime a lista de pedidos e seus pratos
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

// Imprime apenas um no da lista
void imprime_no(No *atual)
{
    printf("\nPratos do pedido:\n");
    for (int i = 0; i < atual->qtd_total_pratos; i++)
    {
        printf("%s - Quantidade: %d\n", atual->pratos[i].nome_prato, atual->pratos[i].qtd_prato);
    }
}

//
void imprime_a_lsl_fila(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }

    No *atual = cabeca;
    while (atual != NULL)
    {
        for (int i = 0; i < atual->qtd_total_pratos; i++)
        {
            printf("%s - Quantidade: %d\n", atual->pratos[i].nome_prato, atual->pratos[i].qtd_prato);
        }
        atual = atual->proximo;
    }
    printf("\n");
}
