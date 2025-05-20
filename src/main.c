#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\lista.h"
#include "..\include\prato.h"
#include "..\include\cardapio.h"
#include "..\include\fila.h"

void menuSalao()
{
    printf("\n--- Menu Lista ---\n");
    printf("1. Ver cardapio\n");
    printf("2. Finalizar pedido.\n");
    printf("3. Imprimir lista\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main()
{
    No *pedido = NULL;          // Ponteiro para o início da lista de pedidos
    No *pedido_atual = NULL;    // Ponteiro para o nó onde serão inseridos os pratos do pedido atual

    Fila fila;
    Prato prato;
    int opcao;
    int op_cardapio; // opção dos cardápios
    int resposta, qtd;

    inicializar_fila(&fila);

    do
    {
        menuSalao();
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Qual e o cardapio que voce deseja acessar: 1- Entrada, 2- Principais, 3 - Sobremesa:\n");
            scanf("%d", &op_cardapio);
            getchar(); // limpa buffer

            switch (op_cardapio)
            {
            case 1:
                cardapio_entrada();
                scanf("%d", &resposta);
                printf("Qual quantidade?\n");
                scanf("%d", &qtd);

                criar_prato(entrada[resposta - 1], qtd, &prato);

                // Se não existe pedido atual, cria um novo nó para o pedido
                if (pedido_atual == NULL)
                {
                    criar_novo_no(&pedido);  // cria o primeiro nó ou novo nó no final da lista
                    pedido_atual = obter_ultimo_no(pedido); // pedido_atual aponta para o último nó criado
                }

                // Adiciona prato no pedido atual
                adicionar_prato_ao_pedido(pedido_atual, prato);

                printf("Prato inserido.\n");
                break;

            case 2:
                cardapio_principal();
                scanf("%d", &resposta);
                printf("Qual quantidade?\n");
                scanf("%d", &qtd);

                criar_prato(principal[resposta - 1], qtd, &prato);

                if (pedido_atual == NULL)
                {
                    criar_novo_no(&pedido);
                    pedido_atual = obter_ultimo_no(pedido);
                }

                adicionar_prato_ao_pedido(pedido_atual, prato);

                printf("Prato inserido.\n");
                break;

            case 3:
                cardapio_sobremesa();
                scanf("%d", &resposta);
                printf("Qual quantidade?\n");
                scanf("%d", &qtd);

                criar_prato(sobremesa[resposta - 1], qtd, &prato);

                if (pedido_atual == NULL)
                {
                    criar_novo_no(&pedido);
                    pedido_atual = obter_ultimo_no(pedido);
                }

                adicionar_prato_ao_pedido(pedido_atual, prato);

                printf("Prato inserido.\n");
                break;

            default:
                printf("Não existe a opção desejada!\n");
                break;
            }
            break;

        case 2:
            // Finalizar pedido atual, ou seja, parar de inserir pratos nesse pedido
            if (pedido_atual == NULL)
            {
                printf("Não existem pratos inseridos no pedido para finalizar!\n");
            }
            else
            {
                printf("\nPedido finalizado.\n");
                pedido_atual = NULL; // Ao finalizar, zera o pedido_atual para criar novo pedido depois
            }
            break;

        case 3:
            imprime_a_lsl(pedido);  // Imprime todos os pedidos com seus pratos
            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 4);

    // Liberar memória da lista de pedidos ao sair
    while (pedido != NULL)
    {
        remocao_no_inicio_da_lsl(&pedido);
    }

    return 0;
}
