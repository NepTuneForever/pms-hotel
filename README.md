# PMS — Sistema de Gestão Hoteleira

Sistema de gestão hoteleira desenvolvido em **linguagem C**, com foco na organização das operações de um hotel, incluindo o controle de hóspedes, quartos, reservas, check-in, check-out e informações financeiras.

O projeto tem finalidade acadêmica e busca aplicar conceitos de programação estruturada na resolução de problemas de gestão.

## Objetivo

Centralizar as principais rotinas de um hotel em uma aplicação de terminal, facilitando o cadastro de informações, a consulta de disponibilidade e o acompanhamento das hospedagens.

## Funcionalidades previstas

- **Gestão de hóspedes:** cadastro, consulta, edição e remoção de registros.
- **Gestão de quartos:** identificação, categoria, valor da diária e disponibilidade.
- **Reservas:** criação, consulta, alteração e cancelamento, com verificação de conflitos de datas.
- **Check-in e check-out:** registro de entradas e saídas e cálculo do valor da hospedagem.
- **Controle financeiro:** acompanhamento de pagamentos e valores associados às reservas.
- **Relatórios:** visão geral de ocupação, reservas e movimentações financeiras.

> **Status:** as funcionalidades listadas são previstas e serão atualizadas conforme o desenvolvimento do projeto.

## Tecnologias

- **C** — linguagem principal.
- **Terminal / CLI** — interface de interação com o usuário.
- **GCC** — compilação do projeto.
- **Biblioteca padrão de C** — manipulação de dados, estruturas e arquivos, conforme a implementação.

## Conceitos aplicados

O projeto busca explorar conceitos fundamentais da linguagem C:

- Programação estruturada e modularização.
- Estruturas de dados (`struct`).
- Vetores e matrizes.
- Ponteiros e alocação dinâmica de memória.
- Manipulação de arquivos.
- Validação de entradas.
- Lógica de programação e regras de negócio.
- Manipulação de datas e verificação de disponibilidade.

## Instalação e execução

### Pré-requisitos

- Compilador GCC.
- Sistema operacional compatível com a linguagem C.

### Clonar o repositório

```bash
git clone <URL_DO_REPOSITORIO>
cd <NOME_DO_REPOSITORIO>
```

### Compilar

Caso o projeto utilize um único arquivo `main.c`:

```bash
gcc -std=c11 -Wall -Wextra main.c -o pms
```

### Executar

```bash
./pms
```

> Os comandos de compilação poderão ser atualizados conforme a estrutura final do projeto.

## Estrutura do projeto

A estrutura dos diretórios e arquivos será documentada conforme o desenvolvimento avançar.

## Contexto acadêmico

Projeto desenvolvido como atividade acadêmica do curso de **Ciência da Computação**, com o objetivo de aplicar conhecimentos de programação em C na construção de um sistema de gestão.

## Autor

**Filipe Paredes Dias**

- [GitHub](https://github.com/NepTuneForever)
- [LinkedIn](https://www.linkedin.com/in/filipe-paredes-9825a5304/)
- [Portfólio](https://nepdev.xyz)

**José Paulo Romão**

**Rafael Donato**