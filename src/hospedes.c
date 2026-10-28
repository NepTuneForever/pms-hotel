#include <stdio.h>
#include <stdlib.h>

// Filipe Paredes //

typedef struct hospede {
    char *nome;
    int idade;
} hospede;

/*

TODO: 
    Cadastrar hospede;
    Listar hospedes;
    Buscar hospedes;
    Editar hospedes;

*/

hospede cadastrar_hospedes(char nome[], int idade) {
    hospede hosp;
    hosp.nome = nome;
    hosp.idade = idade;

    return hosp;
}

void listar_hospedes() {

}