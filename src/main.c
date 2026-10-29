// Nativos: //
#include <stdio.h>
#include <stdlib.h>

// Serviços: //
#include "quartos.h"
#include "hospedes.h"
#include "reservas.h"

// Structs //


/*

TODO: 
    Laço de repetição;
    Integrar o fluxo do sistema;
    Opção de encerrar o programa;
    Integrar todas as funcionalidades de cada componente do sistema;

*/

int main()
{
    hospede h1 = cadastrar_hospede(1, "Filipe", 18);
    hospede h2 = cadastrar_hospede(2, "Maria", 18);
    hospede h3 = cadastrar_hospede(3, "João", 18);

    listar_hospedes();
    return 0;
}