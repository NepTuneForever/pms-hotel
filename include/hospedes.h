#ifndef HOSPEDES_H
#define HOSPEDES_H

typedef struct 
{
    int id;
    char nome[50];
    int idade;
} hospede;

void painel_hospedes();
hospede cadastrar_hospede(int id, char nome[], int idade);
void listar_hospedes();
hospede buscar_hospede(int id);

#endif
