#ifndef PRATO_H
#define PRATO_H
    
typedef struct prato {
    char *nome_prato;
    int qtd_prato;
} Prato;

void criar_prato(const char *nome, int qtd, Prato *prato);

#endif