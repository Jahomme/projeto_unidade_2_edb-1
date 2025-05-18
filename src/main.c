#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include\lista.h"

void menu() {
    printf("\n--- Menu Lista ---\n");
    printf("1. Inserir no início\n");
    printf("2. Inserir no fim\n");
    printf("3. Inserir em posição\n");
    printf("4. Remover por valor\n");
    printf("5. Buscar valor\n");
    printf("6. Imprimir lista\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    No *lista = NULL;
    int opcao;
    char buffer[100];
    int pos;

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                printf("Digite o prato para inserir no início: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; 
                insercao_no_inicio_da_lsl(&lista, buffer);
                printf("Prato inserido no início.\n");
                break;

            case 2:
                printf("Digite o prato para inserir no fim: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                insercao_no_fim_da_lsl(&lista, buffer);
                printf("Prato inserido no fim.\n");
                break;

            case 3:
                printf("Digite a posição para inserir: ");
                scanf("%d", &pos);
                getchar();
                printf("Digite o prato para inserir na posição %d: ", pos);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                insercao_no_meio_da_lsl(&lista, buffer, pos);
                printf("Prato inserido na posição %d.\n", pos);
                break;

            case 4:
                printf("Digite o prato para remover: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                remocao_no_meio_da_lsl(&lista, buffer);
                break;

            case 5:
                printf("Digite o prato para buscar: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                busca_por_valor_na_lsl(lista, buffer);
                break;

            case 6:
                imprime_a_lsl(lista);
                break;

            case 7:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 7);

    while(lista != NULL) {
        remocao_no_inicio_da_lsl(&lista);
    }

    return 0;
}
