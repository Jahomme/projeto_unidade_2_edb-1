#ifndef FILA_H
#define FILA_H

#include "../include/lista.h"

#define TAMANHO_MAX 100

typedef struct {
    No* dados[TAMANHO_MAX];
    int tamanho;
} Fila;

void inicializar_fila(Fila *fila);
int fila_vazia(Fila *fila);
int fila_cheia(Fila *fila);
void inserir_fila(Fila *fila, No *lista);
int remover_fila(Fila *fila);
No *consultar_primeiro(Fila *fila);

void exibir_fila(Fila *fila);

#endif