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
    printf("\n===== QUARTOS CADASTRADOS =====\n");

    for (int i = 1; i <= MAX_RESERVAS; i++)
    {
        Reserva res = obter_reserva_quarto(i);

        printf("Quarto: %03d\n", i);
        printf("Capacidade: 4\n");

        if (res.status == RESERVA_OCUPADA)
        {
            printf("Hospedes: %d\n", res.quarto.nump);
            printf("Status: Ocupado\n");
        }
        else
        {
            printf("Status: Disponivel\n");
        }

        printf("--------------------\n");
    }
}

quarto buscar_quarto(int numero)
{
    quarto q = {0};

    if (numero < 1 || numero > MAX_RESERVAS)
    {
        printf("Quarto nao encontrado.\n");
        return q;
    }

    Reserva res = obter_reserva_quarto(numero);

    printf("\n===== QUARTO =====\n");
    printf("Numero: %03d\n", numero);
    printf("Capacidade: 4\n");

    if (res.status == RESERVA_OCUPADA)
    {
        q = res.quarto;
        printf("Hospedes: %d\n", q.nump);
        printf("Status: Ocupado\n");
    }
    else
    {
        sprintf(q.num, "%03d", numero);
        q.capmax = 4;
        printf("Status: Disponivel\n");
    }

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

        if (res.status != RESERVA_OCUPADA && res.quarto.capmax >= quantidade)
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