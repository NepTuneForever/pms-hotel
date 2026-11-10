#include <stdio.h>
#include <stdlib.h>

#include "quartos.h"

// Rafael Donato //

/*
    Falta implementar as 3 funcoes abaixo:

    1. listar_quartos()
       Aqui voce vai mostrar todos os quartos cadastrados no hotel.

       A ideia e fazer um for para percorrer os quartos e mostrar:
       - Numero do quarto;
       - Capacidade maxima de pessoas;
       - Quantidade de hospedes atualmente;
       - Situacao do quarto (disponivel ou ocupado).

       Pode usar um printf para organizar as informacoes de cada quarto.
       Lembre de mostrar apenas os quartos que existem no sistema.


    2. buscar_quarto()
       Essa funcao serve para encontrar um quarto especifico.

       Primeiro, peca para o usuario digitar o numero do quarto.
       Depois, procure esse numero entre os quartos cadastrados.

       Se encontrar, mostre as informacoes dele.
       Se nao encontrar, mostre uma mensagem avisando que o quarto
       nao existe.

       Tente seguir a mesma ideia da funcao buscar_hospede()
       que ja foi feita no hospedes.c.


    3. consultar_quartos()
       Essa funcao serve para consultar quais quartos estao disponiveis.

       Percorra os quartos usando um for e verifique quais estao livres.
       Mostre somente os quartos que podem receber uma nova reserva.

       Se nenhum quarto estiver disponivel, avise o usuario.

       Para verificar se um quarto esta ocupado, utilize as informacoes
       de reservas.h, principalmente o status da reserva.

       A consulta deve considerar tambem a quantidade de pessoas:
       nao adianta mostrar um quarto como opcao se ele nao comporta
       a quantidade de hospedes solicitada.


    IMPORTANTE:

    Antes de implementar, confira o arquivo quartos.h para entender
    como a struct do quarto foi definida e quais campos estao disponiveis.

    Tambem confira reservas.h, porque as reservas guardam os dados
    dos quartos e indicam se eles estao ocupados ou disponiveis.

    Nao precisa criar outra estrutura de quartos se as informacoes
    ja estiverem sendo armazenadas dentro das reservas.

    Depois de implementar as funcoes, lembre de adicionar as chamadas
    delas no switch do painel de quartos que esta no main.c.
*/

void painel_quartos()
{
    printf(
        "+================================================================+\n"
        "|                   PMS HOTEL - PAINEL DE QUARTOS                |\n"
        "+================================================================+\n"
        "|                                                                |\n"
        "|  [1] Listar quartos                                            |\n"
        "|  [2] Buscar quarto                                             |\n"
        "|  [3] Consultar quartos                                         |\n"
        "|                                                                |\n"
        "|  [0] Voltar                                                    |\n"
        "|                                                                |\n"
        "+================================================================+\n"
        "  Selecione uma opcao: "
    );
}
