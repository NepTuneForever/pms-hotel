#ifndef RESERVAS_H
#define RESERVAS_H

#define MAX_RESERVAS 50
#define TAM_DATA 11

typedef enum {
    RESERVA_DISPONIVEL = 1,
    RESERVA_OCUPADA,
} StatusReserva;

typedef struct {
    int cod;
    int cod_hospede;
    int num_quarto;
    char data_entrada[TAM_DATA];
    char data_saida[TAM_DATA];
    StatusReserva status;
} Reserva;

void painel_reservas();
void criar_reserva();
void listar_reservas();
void cancelar_reserva();
void realizar_check_in();
void realizar_check_out();

#endif
