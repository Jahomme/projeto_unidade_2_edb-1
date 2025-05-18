#include "..\include\cardapio.h"
#include <stdio.h>

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
    "Sopa de Cebola", // 0
    "Salada Caesar", // 1
    "Bruschetta", // 2
    "Carpaccio de Carne", // 3
    "Camarão ao Alho", // 4
};

const char *principal[5] = {
    "Lasanha à Bolonhesa", // 0
    "Filé Mignon com Fritas", // 1
    "Frango Grelhado com Legumes", // 2
    "Bacalhau à Gomes de Sá", // 3
    "Risoto de Cogumelos", // 4
};

const char *sobremesa[5] = {
    "Tiramisu", // 0
    "Cheesecake de Frutas Vermelhas", // 1
    "Mousse de Chocolate", // 2
    "Pudim de Leite", // 3
    "Sorvete de Baunilha com Calda de Morango", // 4
};


