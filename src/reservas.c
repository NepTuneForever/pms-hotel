#include <stdio.h>
#include <stdlib.h>

#include "reservas.h"

// José Paulo Romão //

/*

TODO: 
    criar_reserva;
    listar_reservas;
    cancelar_reserva;
    realizar_check_in;
    realizar_check_out;

*/

void painel_reservas()
{
    printf(
        "+================================================================+\n"
        "|                  PMS HOTEL - PAINEL DE RESERVAS                |\n"
        "+================================================================+\n"
        "|                                                                |\n"
        "|  [1] Criar reserva                                             |\n"
        "|  [2] Listar reservas                                           |\n"
        "|  [3] Cancelar reserva                                          |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}
