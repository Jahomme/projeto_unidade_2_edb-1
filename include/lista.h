#ifndef LISTA_H
#define LISTA_H
#include "prato.h"

typedef struct no {
    Prato prato;
    struct no *proximo;
} No;

void insercao_no_inicio_da_lsl(No **cabeca, const Prato prato);
void insercao_no_fim_da_lsl(No **cabeca, const Prato prato);
void insercao_no_meio_da_lsl(No **cabeca, const Prato prato, int posicao);
void remocao_no_inicio_da_lsl(No **cabeca);
void remocao_no_fim_da_lsl(No **cabeca);
void remocao_no_meio_da_lsl(No **cabeca, const Prato prato);
void busca_por_valor_na_lsl(No *cabeca, const Prato prato);
void imprime_a_lsl(No *cabeca);

#endif 
