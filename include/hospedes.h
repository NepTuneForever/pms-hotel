#ifndef HOSPEDES_H
#define HOSPEDES_H

#include "quartos.h"

typedef struct 
{
    int id;
    char *nome;
    int idade;
    quarto quarto;
} hospede;

void painel_hospedes();
hospede cadastrar_hospede(int id, char nome[], int idade);
void listar_hospedes();
hospede buscar_hospede(int id);

#endif
