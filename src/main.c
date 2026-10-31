// Nativos: //
#include <stdio.h>
#include <stdlib.h>

// OS //
#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

// Serviços: //
#include "quartos.h"
#include "hospedes.h"
#include "reservas.h"

int main()
{
    int opcao;
    int loop = 1;
    int painel = 0;
    system(LIMPAR_TELA);
    while (loop) 
    {
        
        switch (painel) 
        {

            // Painel Principal
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
                        system(LIMPAR_TELA);
                        painel=1;
                        break;
                    case 2:
                        system(LIMPAR_TELA);
                        painel=2;
                        break;
                    case 3:
                        system(LIMPAR_TELA);
                        painel=3;
                        break;
                    
                }

                break;
            
            // Painel de Hospedes
            case 1:
                getchar();
                painel_hospedes();
                
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 0:
                        system(LIMPAR_TELA);
                        painel=0;
                        break;
                }
            break;

            // Painel de Quartos
            case 2:
                getchar();
                painel_quartos();
                
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 0:
                        system(LIMPAR_TELA);
                        painel=0;
                        break;
                }
            break;

            // Painel de reservas
            case 3:
                getchar();
                painel_reservas();
                
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 0:
                        system(LIMPAR_TELA);
                        painel=0;
                        break;
                    
                    case 2:
                        system(LIMPAR_TELA);
                        listar_reservas();
                        break;

                    case 1:
                        criar_reserva();
                        system(LIMPAR_TELA);
                        break;
                }
            break;
        }
        
        
    }

    return 0;
}
