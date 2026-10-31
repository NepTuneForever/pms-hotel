#include <stdio.h>
#include <stdlib.h>

#include "quartos.h"

// Rafael Donato // 

/*

TODO: 
    listar_quartos;
    buscar_quarto;
    consultar_quartos;

*/

void painel_quartos()
{
    printf(
        "+================================================================+\n"
        "|                   PMS HOTEL - PAINEL DE QUARTOS                |\n"
        "+================================================================+\n"
        "|                                                                |\n"
        "|  [1] Listar quartos                                            |\n"
        "|  [2] Buscar quarto                                             |\n"
        "|  [3] Consultar quartos                                         |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}
