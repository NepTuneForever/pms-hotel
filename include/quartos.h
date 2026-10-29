#ifndef QUARTOS_H
#define QUARTOS_H

typedef struct {
    int num; // numero do quarto;
    int capmax; // capacidade maxima;
} quarto;

void painel_quartos();
quarto cadastrar_quarto();
void listar_quartos();
quarto buscar_quarto(int numero);
void consultar_quartos();

#endif
