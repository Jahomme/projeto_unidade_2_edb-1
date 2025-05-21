#ifndef LISTA_H
#define LISTA_H

#include "..\include\prato.h" 

typedef struct No
{
    Prato *pratos;          
    int qtd_total_pratos;
    struct No *proximo;     
} No;


void criar_novo_no(No **cabeca);
No* obter_ultimo_no(No* cabeca);
void adicionar_prato_ao_pedido(No *pedido, Prato prato);
void remocao_no_inicio_da_lsl(No **cabeca);
void imprime_a_lsl(No *cabeca);

#endif 