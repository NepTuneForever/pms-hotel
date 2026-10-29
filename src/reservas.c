#include <stdio.h>
#include <stdlib.h>

#include "reservas.h"

// José Paulo Romão //
//
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

static Reserva reservas[MAX_RESERVAS];
int atual = 0;

void criar_reserva()
{
    Reserva res;
}

void listar_reservas()
{
    printf("Reservas: ");
    for (int i = 0; i < MAX_RESERVAS; i++) {
        Reserva res = reservas[i];
        char* status;
        switch (res.status) {
            case RESERVA_DISPONIVEL:
                status = "Disponivel";
                break;
            case RESERVA_OCUPADA:
                status = "Ocupada";
                break;
        }
        printf("Codigo: %d"
                "Codigo Hospede: %d"
                "Numero Quarto: %d"
                "Data Entrada: %s"
                "Data Saida: %s"
                "Status: %s", 
                    res.cod, 
                    res.cod_hospede, 
                    res.num_quarto, 
                    res.data_entrada, 
                    res.data_saida, 
                    status);
    }
}

void cancelar_reserva()
{

}

void realizar_check_in()
{

}

void realizar_check_out()
{

}

