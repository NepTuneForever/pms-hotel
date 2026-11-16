#ifndef RESERVAS_H
#define RESERVAS_H

#define MAX_RESERVAS 50
#define TAM_DATA 11

// precos para diferentes tipos de hoteis em reais
#define PRECO_BASE 60
#define PRECO_SUITE 120

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
    int valor_total; // em reais
    int valor_pago; // em reais
    quarto quarto; // Numero e Cap Maxima
    char data_entrada[TAM_DATA];
    char data_saida[TAM_DATA];
    StatusCheck check;
    StatusReserva status;
} Reserva;

void painel_reservas();
void criar_reserva();
void listar_reservas();
void listar_frequencia();
void cancelar_reserva(int id);
void realizar_check_in(int id);
void realizar_check_out(int id);
void pagar_reserva(int id);
Reserva obter_reserva_quarto(int numero);

#endif
