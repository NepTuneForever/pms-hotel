// Nativos: //
#include <stdio.h>
#include <stdlib.h>

// Serviços: //
#include "quartos.h"
#include "hospedes.h"
#include "reservas.h"

int main()
{
    int opcao;
    int loop = 1;

    while (loop) 
    {
        system("clear");
        printf(
            "+================================================================+\n"
            "|                  PMS HOTEL - PAINEL PRINCIPAL                  |\n"
            "+================================================================+\n"
            "|                                                                |\n"
            "|  [1] Hospedes                                                  |\n"
            "|  [2] Quartos                                                   |\n"
            "|  [3] Reservas                                                  |\n"
            "|  [4] Check-in                                                  |\n"
            "|  [5] Check-out                                                 |\n"
            "|                                                                |\n"
            "|  [0] Sair                                                      |\n"
            "|                                                                |\n"
            "+================================================================+\n"
            "  Selecione uma opcao: "
        );

        scanf("%d", &opcao);
        
        switch (opcao)
        {
            case 0:
                loop=0;
                break;
            case 1:
                printf("Hospedes");
                break;
            
        }

    }

    return 0;
}
