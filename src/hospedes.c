#include <stdio.h>
#include <stdlib.h>

#include "hospedes.h"
#include "quartos.h"

#define MAX_HOSPEDES 200

// OS //
#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

// Filipe Paredes //

static hospede hospedes[MAX_HOSPEDES];

hospede cadastrar_hospede(int id, char nome[], int idade)
{
    hospede hosp;
    hosp.id = id;
    snprintf(hosp.nome, sizeof(hosp.nome), "%s", nome);
    hosp.idade = idade;

    hospedes[id] = hosp;
    return hosp;
}

hospede buscar_hospede(int id)
{
    system(LIMPAR_TELA);
    printf("Hospede:\n"
                "Id: %d\n"
                "Nome: %s"
                "Idade: %d\n",
                hospedes[id].id+1,
                hospedes[id].nome,
                hospedes[id].idade
            );

    printf("----------------------------------------------------------------------\n");
    
    printf("Pressione Enter para continuar;\n");
    getchar();

    printf("----------------------------------------------------------------------\n");
    return hospedes[id];
}

void painel_hospedes()
{
    printf(
        "+================================================================+\n"
        "|                  PMS HOTEL - PAINEL DE HOSPEDES                |\n"
        "+================================================================+\n"
        "|                                                                |\n"
        "|  [1] Listar hospedes                                           |\n"
        "|  [2] Buscar hospede                                            |\n"
        "|  [3] Editar hospede                                            |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}

void limpar_hospede(int id)
{
    if (hospedes[id].idade)
    {
        hospede hsp = {0};
        hospedes[id] = hsp;
    }
}

void listar_hospedes()
{

    for (int i = 0; i < MAX_HOSPEDES; i++)
    {

        if (hospedes[i].id >= 0 && hospedes[i].idade)
        {
            printf("Hospedes:\n"
                   "Id: %d\n"
                   "Nome: %s"
                   "Idade: %d\n",
                    hospedes[i].id,
                    hospedes[i].nome,
                    hospedes[i].idade
            );
            printf("----------------------------------------------------------------------\n");
        }
        
    }
}
