#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\lista.h"
#include "..\include\prato.h"
#include "..\include\cardapio.h"

void menu()
{
    printf("\n--- Menu Lista ---\n");
    printf("1. Inserir no fim\n");
    printf("2. Remover por valor\n");
    printf("3. Buscar valor\n");
    printf("4. Imprimir lista\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

int main()
{
    No *lista = NULL;
    Prato prato;
    int opcao;
    int op_cardapio; // opção dos cardápios
    int resposta, qtd;
    char buffer[100];
    int pos;

    do
    {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Qual é o cardápio que você deseja acessar: 1- Entrada, 2- Principais, 3 - Sobremesa:\n");
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
                insercao_no_fim_da_lsl(&lista, prato);
                printf("Prato inserido no início.\n");

                break;

            case 2:
                cardapio_principal();
                scanf("%d", &resposta);
                printf("Qual quantidade?\n");
                scanf("%d", &qtd);
                criar_prato(principal[resposta - 1], qtd, &prato);
                insercao_no_fim_da_lsl(&lista, prato);
                printf("Prato inserido no início.\n");

                break;

            case 3:
                cardapio_sobremesa();
                scanf("%d", &resposta);
                printf("Qual quantidade?\n");
                scanf("%d", &qtd);
                criar_prato(sobremesa[resposta - 1], qtd, &prato);
                insercao_no_fim_da_lsl(&lista, prato);
                printf("Prato inserido no início.\n");

                break;

            default:
                printf("Não existe a opção desejada!");
                break;
            }
            break;

        /*case 2:
            printf("Digite o prato para remover: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            remocao_no_meio_da_lsl(&lista, buffer);
            break;

        case 3:
            printf("Digite o prato para buscar: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            busca_por_valor_na_lsl(lista, buffer);
            break;
*/
        case 4:
            imprime_a_lsl(lista);
            break;

        case 5:
            printf("Saindo...\n");
            break;
        
        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    while (lista != NULL)
    {
        remocao_no_inicio_da_lsl(&lista);
    }

    return 0;
}
