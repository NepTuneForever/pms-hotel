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
    int painel = 0;

    while (loop) 
    {
        system("clear");
        switch (painel) 
        {
            case 0:
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
                        system("clear");
                        painel=1;
                        break;
                    case 2:
                        system("clear");
                        painel=2;
                        break;
                    case 3:
                        system("clear");
                        painel=3;
                        break;
                    
                }

                break;
            
            case 1:
                getchar();
                painel_hospedes();
                
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 0:
                        system("clear");
                        painel=0;
                        break;
                }
            break;

            case 2:
                getchar();
                painel_quartos();
                
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 0:
                        system("clear");
                        painel=0;
                        break;
                }
            break;

            case 3:
                getchar();
                painel_reservas();
                
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 0:
                        system("clear");
                        painel=0;
                        break;
                }
            break;
        }
        
        
    }

    return 0;
}
