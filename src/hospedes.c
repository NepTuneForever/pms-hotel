#include <stdio.h>
#include <stdlib.h>

#include "hospedes.h"
#include "quartos.h"

#define MAX_HOSPEDES 50

// Filipe Paredes //

/*

TODO: 
    cadastrar_hospede; /////////////////////
    listar_hospedes; 
    buscar_hospede; ////////////////////////
    editar_hospedes;

*/

static hospede hospedes[MAX_HOSPEDES];

hospede cadastrar_hospede(int id, char nome[], int idade)
{
    hospede hosp;
    hosp.id = id;
    hosp.nome = nome;
    hosp.idade = idade;

    hospedes[id] = hosp;
    return hosp;
}

hospede buscar_hospede(int id)
{
    return hospedes[id];
}

void painel_hospedes()
{
    printf(
        "+================================================================+\n"
        "|                  PMS HOTEL - PAINEL DE HOSPEDES                |\n"
        "+================================================================+\n"
        "|                                                                |\n"
        "|  [1] Cadastrar hospede                                         |\n"
        "|  [2] Listar hospedes                                           |\n"
        "|  [3] Buscar hospede                                            |\n"
        "|  [4] Editar hospede                                            |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}

void listar_hospedes()
{

    for (int i = 1; i < MAX_HOSPEDES; i++)
    {

        if (hospedes[i].id != 0) 
        {
            printf("%d %s %d\n", hospedes[i].id, hospedes[i].nome, hospedes[i].idade);
        }
        
    }
}
