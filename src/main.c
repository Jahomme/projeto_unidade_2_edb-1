#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista.h"
#include "../include/prato.h"
#include "../include/cardapio.h"
#include "../include/fila.h"

int main()
{
    No *pedido = NULL;       // Ponteiro para o início da lista de pedidos
    No *pedido_atual = NULL; // Ponteiro para o nó onde serão inseridos os pratos do pedido atual

    Fila fila;
    Prato prato;
    int opcao;
    int opcao_cozinha;
    int op_cardapio; // opção dos cardápios
    int resposta, qtd;

    inicializar_fila(&fila);

    do
    {
        menuPrincipal();
        scanf("%d", &opcao);
        getchar();
        if (opcao == 1)
        {
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
                    getchar();

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
                            criar_novo_no(&pedido);                 // cria o primeiro nó ou novo nó no final da lista
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
                        do
                        {
                            printf("Você quer mandar ele para fila da cozinha?\n1- Sim\n2 - Não\n");
                            scanf("%d", &opcao);
                            getchar();
                            if (opcao == 1)
                            {
                                No *copia_do_pedido = copiar_no(pedido_atual);
                                inserir_fila(&fila, copia_do_pedido);
                                remover_no(&pedido, pedido_atual);
                                pedido_atual = NULL;
                                printf("Pedido enviado para a cozinha com sucesso!\n");
                                break;
                            }
                            else if (opcao == 2)
                            {
                                printf("\nPedido finalizado.\n");
                                pedido_atual = NULL; // Ao finalizar, zera o pedido_atual para criar novo pedido depois
                                break;
                            }

                            else{
                                printf("Opção inválida.\n");
                            }
                        }

                        while (opcao != 2 || opcao != 1);
                    }
                    break;

                case 3:
                    imprime_no(pedido_atual);
                    printf("Qual é o prato que você quer remover? 1- Entrada, 2- Principais, 3 - Sobremesa:\n");
                    scanf("%d", &op_cardapio);
                    getchar(); // limpa buffer

                    switch (op_cardapio)
                    {
                    case 1:
                        cardapio_entrada();
                        scanf("%d", &resposta);
                        printf("Qual quantidade?\n");
                        scanf("%d", &qtd);
                        remover_prato_do_pedido(entrada[resposta - 1], qtd, pedido_atual);
                        break;
                    case 2:
                        cardapio_principal();
                        scanf("%d", &resposta);
                        printf("Qual quantidade?\n");
                        scanf("%d", &qtd);
                        remover_prato_do_pedido(principal[resposta - 1], qtd, pedido_atual);
                        break;
                    case 3:
                        cardapio_sobremesa();
                        scanf("%d", &resposta);
                        printf("Qual quantidade?\n");
                        scanf("%d", &qtd);
                        remover_prato_do_pedido(sobremesa[resposta - 1], qtd, pedido_atual);
                        break;
                    default:
                        printf("Não existe a opção desejada!\n");
                        break;
                    }
                    break;

                case 4:
                    imprime_a_lsl(pedido); // Imprime todos os pedidos com seus pratos
                    break;

                case 5:
                    if (pedido == NULL)
                    { // Se não tiver pedido, não manda.
                        printf("Pedido vazio, não há como mandar para cozinha!\n");
                        break;
                    }

                    No *copia_do_pedido = copiar_no(pedido);
                    inserir_fila(&fila, copia_do_pedido);

                    remocao_no_inicio(&pedido);

                    printf("Pedido enviado para a cozinha com sucesso!\n");
                    break;

                    break;
                case 6:
                    printf("Saindo...\n");
                    break;

                default:
                    printf("Opção inválida!\n");
                }
            } while (opcao != 6);
        }

        else if (opcao == 2)
        {
            do
            {
                menuCozinha();
                scanf("%d", &opcao_cozinha);
                getchar();
                switch (opcao_cozinha)
                {
                case 1:
                    exibir_fila(&fila);
                    break;
                case 2:
                    printf("Pedido que saiu para o salao: ");
                    imprime_a_lsl(remover_fila(&fila));
                    break;
                case 3:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            } while (opcao_cozinha != 3);
        }

        else if (opcao == 3)
        {
            printf("Saindo...");
        }

        else
        {
            printf("Opção inválida.");
        }

    } while (opcao != 3);

    // Liberar memória da lista de pedidos ao sair
    while (pedido != NULL)
    {
        remocao_no_inicio(&pedido);
    }
    No *pedido_percorrer = remover_fila(&fila);

    while(pedido_percorrer != NULL){
        remocao_no_inicio(&pedido_percorrer);
        pedido_percorrer = remover_fila(&fila);
    }
    return 0;
}
