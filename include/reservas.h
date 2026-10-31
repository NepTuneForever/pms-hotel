#ifndef RESERVAS_H
#define RESERVAS_H

#define MAX_RESERVAS 50
#define TAM_DATA 11

#include "quartos.h"
#include <stdbool.h>

typedef enum {
    RESERVA_DISPONIVEL,
    RESERVA_OCUPADA,
} StatusReserva;

typedef enum {
    PENDENTE,
    CHECKIN,
    CHECKOUT,
} StatusCheck;

typedef struct {
    int cod;
    int cod_hospede;
    quarto quarto; // Numero e Cap Maxima
    char data_entrada[TAM_DATA];
    char data_saida[TAM_DATA];
    StatusCheck check;
    StatusReserva status;
} Reserva;

void painel_reservas();
void criar_reserva();
void listar_reservas();
void cancelar_reserva(int id);
void realizar_check_in(int id);
void realizar_check_out(int id);

#endif
