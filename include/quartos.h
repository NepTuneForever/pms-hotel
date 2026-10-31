#ifndef QUARTOS_H
#define QUARTOS_H

#include "hospedes.h"

typedef struct {
    char num[20]; // numero do quarto;
    int capmax; // capacidade maxima;
    int nump; // numero de pessoas;
    hospede hospedes[4];
} quarto;

void painel_quartos();
void listar_quartos();
quarto buscar_quarto(int numero);
void consultar_quartos();

#endif
