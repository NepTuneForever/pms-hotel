// Nativos: //
#include <stdio.h>
#include <stdlib.h>

// Serviços: //
#include "quartos.h"
#include "hospedes.h"
#include "reservas.h"

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

    hospede hosp = buscar_hospede(1);
    printf("%s %d\n", hosp.nome, hosp.idade);
    
    return 0;
}