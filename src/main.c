#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\lista.h"
#include "..\include\prato.h"
#include "..\include\cardapio.h"
#include "..\include\fila.h"

void menu()
{
    printf("\n--- Menu Lista ---\n");
    printf("1. Atender cliente\n");
    printf("2. Enviar pedido para a cozinha\n");
    printf("3. Mostra pedidos na cozinha\n");
    printf("4. Imprimir lista\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

void atendimento() {
    printf("\n--- Opcoes de atendimento ---\n");
    printf("1. Exibir cardapio\n");
    printf("2. Enviar pedido para a cozinha\n");
    printf("3. Exibir pedido\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

void switchCardapio(int op_cardapio, int resposta, int qtd, No** pedido, Prato prato) {

    switch (op_cardapio)
        {
        case 1:
            cardapio_entrada();
            scanf("%d", &resposta);
            printf("Qual quantidade?\n");
            scanf("%d", &qtd);
            criar_prato(entrada[resposta - 1], qtd, &prato);
            insercao_no_fim_da_lsl(pedido, prato);
            printf("Prato inserido no inicio.\n");

            break;

        case 2:
            cardapio_principal();
            scanf("%d", &resposta);
            printf("Qual quantidade?\n");
            scanf("%d", &qtd);
            criar_prato(principal[resposta - 1], qtd, &prato);
            insercao_no_fim_da_lsl(pedido, prato);
            printf("Prato inserido no inicio.\n");

            break;

        case 3:
            cardapio_sobremesa();
            scanf("%d", &resposta);
            printf("Qual quantidade?\n");
            scanf("%d", &qtd);
            criar_prato(sobremesa[resposta - 1], qtd, &prato);
            insercao_no_fim_da_lsl(pedido, prato);
            printf("Prato inserido no inicio.\n");

            break;

        default:
            printf("Não existe a opção desejada!");
            break;
        }
}

int main()
{
    No *pedido = NULL;
    Fila fila;
    Prato prato;
    int opcao;
    int op_cardapio; // opção dos cardápios
    int op_atendimento; // opção de atendimento  ao cliente
    int resposta, qtd;
    char buffer[100];
    int pos;

    inicializar_fila(&fila);

    do
    {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            do {    
                atendimento();
                scanf("%d", &op_atendimento);
                getchar(); // limpa buffer

                switch (op_atendimento)
                    {
                    case 1:
                        printf("Qual e o cardapio que voce deseja acessar: 1- Entrada, 2- Principais, 3 - Sobremesa:\n");
                        scanf("%d", &op_atendimento);
                        switchCardapio(op_atendimento, resposta, qtd, &pedido, prato);
                        break;

                    case 2:
                        if(pedido == NULL) {
                            printf("Nao existem pratos inseridos no pedido, insira algum prato para enviar para a cozinha!\n");
                            break;
                        }

                        //Copiamos a lista original e enviamos para a fila
                        No* copia_do_pedido = copiar_lista(pedido);
                        inserir_fila(&fila, copia_do_pedido);

                        //esvaziamos a lista para poder fazer um novo pedido
                        while (pedido != NULL) {
                            remocao_no_inicio_da_lsl(&pedido);
                        }

                        printf("Pedido enviado para a cozinha com sucesso!\n");
                        break;

                    case 3:
                        imprime_a_lsl(pedido);
                        break;

                    default:
                        printf("Não existe a opção desejada!");
                        break;
                    }
            } while (op_atendimento != 4);

        case 2:
    
            if(pedido == NULL) {
                printf("Nao existem pratos inseridos no pedido, insira algum prato para enviar para a cozinha!\n");
                break;
            }

            //Copiamos a lista original e enviamos para a fila
            No* copia_do_pedido = copiar_lista(pedido);
            inserir_fila(&fila, copia_do_pedido);

            //esvaziamos a lista para poder fazer um novo pedido
            while (pedido != NULL) {
                remocao_no_inicio_da_lsl(&pedido);
            }

            printf("Pedido enviado para a cozinha com sucesso!\n");
            break;

        case 3:
            printf("Pedidos na cozinha:\n");
            exibir_fila(&fila);
            break;

        case 4:
            imprime_a_lsl(pedido);
            break;

        case 5:
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    while (pedido != NULL)
    {
        remocao_no_inicio_da_lsl(&pedido);
    }

    return 0;
}
