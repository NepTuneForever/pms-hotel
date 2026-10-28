// Nativos: //
#include <stdio.h>
#include <stdlib.h>

// Serviços: //
#include "src/quartos.c"
#include "src/hospedes.c"
#include "src/reservas.c"

/*

TODO: 
    Laço de repetição;
    Integrar o fluxo do sistema;
    Opção de encerrar o programa;
    Integrar todas as funcionalidades de cada componente do sistema;

*/

int main() {
    hospede *hospedes = (hospede *) malloc(sizeof(hospede));

    hospede h1 = cadastrar_hospedes("Filipe", 18);
    hospedes[0] = h1;

    return 0;
}