
#include <stdio.h>
#include "quartos.h"
#include "reservas.h"

void painel_quartos()
{
    printf(
        "+================================================================+\n"
        "|                   PMS HOTEL - PAINEL DE QUARTOS                |\n"
        "+================================================================+\n"
        "|  [1] Listar quartos                                            |\n"
        "|  [2] Buscar quarto                                             |\n"
        "|  [3] Consultar quartos                                         |\n"
        "|  [0] Voltar                                                    |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}

void listar_quartos()
{
    int encontrou = 0;

    printf("\n===== QUARTOS CADASTRADOS =====\n");

    for (int i = 1; i <= MAX_RESERVAS; i++)
    {
        Reserva res = obter_reserva_quarto(i);

        if (res.status == RESERVA_OCUPADA)
        {
            printf("Quarto: %s\n", res.quarto.num);
            printf("Capacidade: %d\n", res.quarto.capmax);
            printf("Hospedes: %d\n", res.quarto.nump);
            printf("--------------------\n");

            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum quarto cadastrado.\n");
    }
}

quarto buscar_quarto(int numero)
{
    quarto q = {0};

    Reserva res = obter_reserva_quarto(numero);

    if (res.status != RESERVA_OCUPADA)
    {
        printf("Quarto nao encontrado.\n");
        return q;
    }

    q = res.quarto;

    printf("\n===== QUARTO =====\n");
    printf("Numero: %s\n", q.num);
    printf("Capacidade: %d\n", q.capmax);
    printf("Hospedes: %d\n", q.nump);

    return q;
}

void consultar_quartos()
{
    int quantidade;
    int encontrou = 0;

    printf("Quantidade de hospedes: ");
    scanf("%d", &quantidade);

    if (quantidade < 1 || quantidade > 4)
    {
        printf("Quantidade invalida.\n");
        return;
    }

    printf("\n===== QUARTOS DISPONIVEIS =====\n");

    for (int i = 1; i <= MAX_RESERVAS; i++)
    {
        Reserva res = obter_reserva_quarto(i);

        if (res.status != RESERVA_OCUPADA)
        {
            printf("Quarto %03d - Capacidade: 4\n", i);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhum quarto disponivel.\n");
    }
}
