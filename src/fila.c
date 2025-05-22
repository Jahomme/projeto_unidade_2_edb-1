#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"

#define TAMANHO_MAX 100

typedef struct {
    No* dados[TAMANHO_MAX];
    int tamanho;
} Fila;

//-----------------------------------

void inicializar_fila(Fila* fila)
{
  fila->tamanho = 0;
}

//-----------------------------------

int fila_vazia(Fila* fila)
{
  return fila->tamanho == 0;
}

//-----------------------------------

int fila_cheia(Fila* fila)
{
  return fila->tamanho == TAMANHO_MAX;
}

//-----------------------------------

void inserir_fila(Fila* fila, No* lista)
{
  if(fila_cheia(fila)){
    printf("A fila está cheia!");
  }else{
    fila->dados[fila->tamanho] = lista;
    fila->tamanho++;
  }
}

//-----------------------------------

No* remover_fila(Fila* fila)
{
  if(fila_vazia(fila)){
    return NULL;
  }else{
    No* lista_removida = fila->dados[0];
 
    for (int i = 1; i < fila->tamanho; i++) {
      fila->dados[i - 1] = fila->dados[i];
    }
    fila->tamanho--;
    return lista_removida;
  }
}

//-----------------------------------

No* consultar_primeiro(Fila* fila)
{
  if(fila_vazia(fila)){
    printf("A fila está vazia!");
    return NULL;
  }else{
    return fila->dados[0];
  }
}

//-----------------------------------

void exibir_fila(Fila* fila)
{
  if(fila_vazia(fila)){
    printf("A fila está vazia!\n");
  }else{
    printf("\nFila de pedidos:\n\n");
    for(int i = 0; i < fila->tamanho; i++){
        printf("Pedido numero %d: \n", i + 1);
        imprime_a_lsl_fila(fila->dados[i]);
    }
  }
}

