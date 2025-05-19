#include "..\include\prato.h"
#include <string.h>
#include <stdlib.h>

void criar_prato(const char *nome, int qtd, Prato *prato){
    prato->nome_prato = malloc(strlen(nome) + 1);
    strcpy(prato->nome_prato, nome);
    prato->qtd_prato =  qtd;
}

