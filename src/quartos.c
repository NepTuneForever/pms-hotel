#include <stdio.h>
#include <stdlib.h>

#include "quartos.h"

// Rafael Donato // 

/*

TODO: 
    cadastrar_quarto;
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
        "|  [1] Cadastrar quarto                                          |\n"
        "|  [2] Listar quartos                                            |\n"
        "|  [3] Buscar quarto                                             |\n"
        "|  [4] Consultar quartos                                         |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}
