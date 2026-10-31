#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "reservas.h"

// OS //
#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

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

                if (qtdp > 4 || qtdp <= 0)
                {
                    printf("Insira um valor valido;\n");

                    getchar();
                    printf("Pressione Enter para continuar;");
                    getchar();
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

            printf("[ENTRADA] Digite o dia(1-31): ");
            scanf("%d", &dia_entrada);

            printf("[ENTRADA] Digite o mes(1-12): ");
            scanf("%d", &mes_entrada);

            printf("[ENTRADA] Digite o ano(XXXX): ");
            scanf("%d", &ano_entrada);

            printf("[SAIDA] Digite o dia(1-31): ");
            scanf("%d", &dia_saida);

            printf("[SAIDA] Digite o mes(1-12): ");
            scanf("%d", &mes_saida);

            printf("[SAIDA] Digite o ano(XXXX): ");
            scanf("%d", &ano_saida);

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            sprintf(res.data_entrada, "%02d/%02d/%d", dia_entrada, mes_entrada, ano_entrada);
            sprintf(res.data_saida, "%02d/%02d/%d", dia_saida, mes_saida, ano_saida);

            res.status = RESERVA_OCUPADA;
            reservas[i] = res;

            printf("----------------------------------------------------------------------\n");
            printf("Reserva cadastrada no sistema!\n"
                   "Codigo da reserva: %d\n", res.cod);
            getchar();
            printf("Pressione Enter para continuar;");
            getchar();

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

    getchar();
    printf("Pressione Enter para continuar;");
    getchar();

    system(LIMPAR_TELA);
}

void cancelar_reserva(int id)
{
    Reserva res = reservas[id - 1];

    if (res.cod)
    {
        Reserva temp = {0};
        reservas[id - 1] = temp;
    }
}

void realizar_check_in(int id)
{

}

void realizar_check_out(int id)
{

}

