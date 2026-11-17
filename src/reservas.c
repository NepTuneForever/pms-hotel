#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "reservas.h"
#include "hospedes.h"

// OS //
#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

// José Paulo Romão //

/*
pagar reserva
frequencia de reservas (diaria/semanal)
quartos suites, detalhatamento etc
*/

// funcoes auxiliares pra ajudar no pagamento
static bool ano_bissexto(int ano)
{
    return (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
}

static int dias_no_mes(int mes, int ano)
{
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes == 2 && ano_bissexto(ano))
    {
        return 29;
    }

    return dias[mes - 1];
}

// dias contados desde 01/01/1900 (que vale 1)
static int dias_desde_epoca(int dia, int mes, int ano)
{
    int total = 0;

    for (int a = 1900; a < ano; a++)
    {
        total += ano_bissexto(a) ? 366 : 365;
    }

    for (int m = 1; m < mes; m++)
    {
        total += dias_no_mes(m, ano);
    }

    return total + dia;
}

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
        "|  [4] Listar Frequências                                        |\n"
        "|  [5] Pagar reserva                                             |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}

static Reserva reservas[MAX_RESERVAS];
int atual = 0;

void pagar_reserva(int id)
{
    getchar();

    if (reservas[id - 1].status != RESERVA_OCUPADA) {
        printf("Reserva nao encontrada;\n");
        printf("Pressione Enter para continuar;");
        getchar();
        return;
    }

    int restante = reservas[id - 1].valor_total - reservas[id - 1].valor_pago;

    printf("Valor total: R$ %d\n"
           "Valor pago: R$ %d\n"
           "Restante: R$ %d\n",
           reservas[id - 1].valor_total,
           reservas[id - 1].valor_pago,
           restante);

    if (restante <= 0) {
        printf("Reserva ja esta paga;\n");
        printf("Pressione Enter para continuar;");
        getchar();
        return;
    }

    int valor;
    printf("Digite o valor a pagar: ");
    scanf("%d", &valor);
    getchar();

    if (valor <= 0 || valor > restante) {
        printf("Insira um valor valido;\n");
    }
    else {
        reservas[id - 1].valor_pago += valor;
        printf("Pagamento registrado! Restante: R$ %d\n", restante - valor);
    }

    printf("Pressione Enter para continuar;");
    getchar();
}


void criar_reserva()
{  
    for (int i = 0; i < MAX_RESERVAS; ++i)
    {
        if (reservas[i].status != RESERVA_OCUPADA)
        {

            Reserva res = {0};

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
                    getchar();
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

            int suite;
            do {
                printf("Deseja ter acesso a suite da reserva? [1-Sim/0-Nao]: ");
                scanf("%d", &suite);
                getchar();

                if (suite < 0 || suite > 1) {
                    printf("Valor invalido!\n");
                    printf("Pressione enter para continuar.\n");
                    getchar();
                }
            } while (suite < 0 || suite > 1);

            // utilizando o campo bool do struct quarto pra n ter que criar uma 
            // variavel local e poluir mais ainda a funca
            res.quarto.com_suite = suite == 0 ? false : true;

            printf("[ENTRADA] Digite o dia(1-31): ");
            scanf("%d", &dia_entrada);
            getchar();

            printf("[ENTRADA] Digite o mes(1-12): ");
            scanf("%d", &mes_entrada);
            getchar();

            printf("[ENTRADA] Digite o ano(XXXX): ");
            scanf("%d", &ano_entrada);
            getchar();

            printf("[SAIDA] Digite o dia(1-31): ");
            scanf("%d", &dia_saida);
            getchar();

            printf("[SAIDA] Digite o mes(1-12): ");
            scanf("%d", &mes_saida);
            getchar();

            printf("[SAIDA] Digite o ano(XXXX): ");
            scanf("%d", &ano_saida);
            getchar();
            
            // inicio do pagamento
            int noites = dias_desde_epoca(dia_saida, mes_saida, ano_saida)
                        - dias_desde_epoca(dia_entrada, mes_entrada, ano_entrada);
            
            if (res.quarto.com_suite) {
                res.valor_total = noites * PRECO_SUITE;
            } else {
                res.valor_total = noites * PRECO_BASE;
            }
            res.valor_pago = 0;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            sprintf(res.data_entrada, "%02d/%02d/%04d", dia_entrada, mes_entrada, ano_entrada);
            sprintf(res.data_saida, "%02d/%02d/%04d", dia_saida, mes_saida, ano_saida);

            printf("----------------------------------------------------------------------\n");

            for (int j = 0; j<qtdp; j++)
            {
                res.quarto.hospedes[j].id = j+1;
                char nome[50];
                int idade;

                printf("Digite o nome do %d° hospede: ", j+1);
                fgets(nome, sizeof(nome), stdin);

                printf("Digite o idade do %d° hospede: ", j+1);
                scanf("%d", &idade);

                res.quarto.hospedes[j].idade = idade;
                sprintf(res.quarto.hospedes[j].nome, "%s", nome);

                cadastrar_hospede(j, nome, idade);

                getchar();

                // res.quarto.hospedes[j].nome;
            }

            res.status = RESERVA_OCUPADA;
            reservas[i] = res;

            printf("----------------------------------------------------------------------\n");
            printf("Reserva cadastrada no sistema!\n"
                   "Codigo da reserva: %d\n", res.cod);
            
            printf("Pressione Enter para continuar;");
            getchar();
            
            FILE* frequencia = fopen("./frequencia/frequencia.txt", "a+");
            
            if (frequencia != NULL)
            {
                fprintf(frequencia,
                    "-------------------\n"
                    "Data de Entrada: %s\n"
                    "Data de Saída: %s\n"
                    "Numero do quarto: %s\n"
                    "Hospedes:\n",
                    res.data_entrada,
                    res.data_saida,
                    res.quarto.num
                );

                for (int i = 0; i < qtdp; i++)
                {
                    fprintf(frequencia,
                        "   Hospede: %02d\n"
                        "   Nome: %s"
                        "   Idade: %d anos\n",
                        i+1,
                        res.quarto.hospedes[i].nome,
                        res.quarto.hospedes[i].idade
                    );
                }

                fprintf(frequencia,
                    "-------------------\n\n");

                fclose(frequencia);
            } 
            else
            {
                perror("Erro ao abrir report de frequencia. Abortando programa.");
                exit(EXIT_FAILURE); // padrao para error. Eh como se main retornasse -1
            }

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
                "Status: %s\n"
                "Valor a pagar: %d\n"
                "Valor encaminhado: %d\n",
                    res.cod,
                    res.cod_hospede, 
                    res.quarto.num, 
                    res.data_entrada, 
                    res.data_saida,
                    status,
                    res.valor_total,
                    res.valor_pago);
        printf("----------------------------------------------------------------------\n");

    }

    getchar();
    printf("Pressione Enter para continuar;");
    getchar();

    system(LIMPAR_TELA);
}

void listar_frequencia()
{
    system(LIMPAR_TELA);
    FILE* frequencia = fopen("./frequencia/frequencia.txt", "r");

    if (frequencia == NULL) {
        printf("Nenhuma frequencia registrada\n");
        return;
    }

    int c;
    while ((c = fgetc(frequencia)) != EOF)
    {
        putchar(c);
    }

    fclose(frequencia);
}

void cancelar_reserva(int id)
{
    Reserva res = reservas[id - 1];

    if (res.cod)
    {
        Reserva temp = {0};
        hospede hsp = {0};

        for (int i=0;i<reservas[id-1].quarto.nump;i++)
        {
            limpar_hospede(reservas[id-1].quarto.hospedes[i].id-1);
        }

        reservas[id-1] = temp;
    }
}

void realizar_check_in(int id)
{
    reservas[id-1].check = CHECKIN;
}

void realizar_check_out(int id)
{
    reservas[id-1].check = CHECKOUT;
    cancelar_reserva(id);
}

Reserva obter_reserva_quarto(int numero)
{
    Reserva vazia = {0};

    for (int i = 0; i < MAX_RESERVAS; i++)
    {
        if (reservas[i].status == RESERVA_OCUPADA &&
            atoi(reservas[i].quarto.num) == numero)
        {
            return reservas[i];
        }
    }

    return vazia;
}
