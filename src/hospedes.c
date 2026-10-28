#include <stdio.h>
#include <stdlib.h>

#include "hospedes.h"
#include "quartos.h"

// Filipe Paredes //

/*

TODO: 
    cadastrar_hospede;
    listar_hospedes;
    buscar_hospede;
    editar_hospedes;

*/

hospede hospedes[100];

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