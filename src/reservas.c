#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    for (int i = 0; i < MAX_RESERVAS; ++i)
    {
        if (reservas[i].status != RESERVA_OCUPADA)
        {

            Reserva res;

            if (i < 9) 
            {
                sprintf(res.quarto.num, "%03d", i + 1);
            } else
            {
                sprintf(res.quarto.num, "0%d", i + 1);
            }

            res.quarto.capmax = 4;
            res.cod = i + 1;
            res.cod_hospede = i + 1;

            printf("----------------------------------------------------------------------\n");

            bool aprovado = false;
            int qtdp;

            do
            {
                printf("Digite a quantidade de pessoas(1-4): ");
                scanf("%d", &qtdp);

                if (qtdp > 4) 
                {
                    printf("Opção Invalida, tente novamente;\n");
                    printf("Pressione Enter para continuar;");
                    getchar(); getchar();
                    return;
                }
                if (qtdp < 5)
                {
                    res.quarto.nump = qtdp;
                    break;
                }
            } while (aprovado);

            printf("----------------------------------------------------------------------\n");

            int dia_entrada;
            int dia_saida;

            int mes_saida;
            int mes_entrada;

            int ano_entrada;
            int ano_saida;

            printf("Digite o dia de entrada: ");
            scanf("%d", &dia_entrada);

            printf("Digite o mes de entrada: ");
            scanf("%d", &mes_entrada);

            printf("Digite o ano de entrada: ");
            scanf("%d", &ano_entrada);

            printf("Digite o dia de saída: ");
            scanf("%d", &dia_saida);

            printf("Digite o mes de saída: ");
            scanf("%d", &mes_saida);

            printf("Digite o ano de saída: ");
            scanf("%d", &ano_saida);

            /////////////////////////

            sprintf(res.data_entrada, "%02d/%02d/%d", dia_entrada, mes_entrada, ano_entrada);
            sprintf(res.data_saida, "%02d/%02d/%d", dia_saida, mes_saida, ano_saida);

            res.status = RESERVA_OCUPADA;
            reservas[i] = res;

            break;
        }
    }

}

void listar_reservas()
{
    printf("Reservas: \n");
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
        printf("Codigo: %d\n"
                "Codigo Hospede: %d\n"
                "Numero Quarto: %s\n"
                "Data Entrada: %s\n"
                "Data Saida: %s\n"
                "Status: %s\n", 
                    res.cod, 
                    res.cod_hospede, 
                    res.quarto.num, 
                    res.data_entrada, 
                    res.data_saida, 
                    status);
        printf("----------------------------------------------------------------------\n");
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

