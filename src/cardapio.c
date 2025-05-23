#include "..\include\cardapio.h"
#include <stdio.h>

void menuPrincipal()
{
    printf("\n--- Menu Lista ---\n");
    printf("1. Ver menu de atendimento.\n");
    printf("2. Ver menu de cozinha.\n");
    printf("3. Sair.\n");
    printf("Escolha uma opção: ");
}
void menuSalao()
{
    printf("\n--- Menu Lista ---\n");
    printf("1. Ver cardapio\n");
    printf("2. Finalizar pedido.\n");
    printf("3. Remover item do pedido.\n");
    printf("4. Imprimir lista de pedidos.\n");
    printf("5. Enviar primeiro pedido para cozinha.\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}
void menuCozinha()
{
    printf("\n--- Menu Lista ---\n");
    printf("1. Imprimir lista da cozinha.\n");
    printf("2. Liberar pedido da cozinha.\n");
    printf("3. Sair\n");
}

void cardapio_entrada()
{
    printf("Cardápio\n\n");
    printf("Entradas:\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarão ao Alho\n\n");
}

void cardapio_principal()
{
    printf("Cardápio\n\n");
    printf("Pratos Principais:\n");
    printf("1. Lasanha à Bolonhesa\n");
    printf("2. Filé Mignon com Fritas\n");
    printf("3. Frango Grelhado com Legumes\n");
    printf("4. Bacalhau à Gomes de Sá\n");
    printf("5. Risoto de Cogumelos\n\n");
}

void cardapio_sobremesa()
{
    printf("Cardápio\n\n");
    printf("Sobremesas:\n");
    printf("1. Tiramisu\n");
    printf("2. Cheesecake de Frutas Vermelhas\n");
    printf("3. Mousse de Chocolate\n");
    printf("4. Pudim de Leite\n");
    printf("5. Sorvete de Baunilha com Calda de Morango\n\n");
}

const char *entrada[5] = {
    "Sopa de Cebola",     // 0
    "Salada Caesar",      // 1
    "Bruschetta",         // 2
    "Carpaccio de Carne", // 3
    "Camarão ao Alho",    // 4
};

const char *principal[5] = {
    "Lasanha à Bolonhesa",         // 0
    "Filé Mignon com Fritas",      // 1
    "Frango Grelhado com Legumes", // 2
    "Bacalhau à Gomes de Sá",      // 3
    "Risoto de Cogumelos",         // 4
};

const char *sobremesa[5] = {
    "Tiramisu",                                 // 0
    "Cheesecake de Frutas Vermelhas",           // 1
    "Mousse de Chocolate",                      // 2
    "Pudim de Leite",                           // 3
    "Sorvete de Baunilha com Calda de Morango", // 4
};
