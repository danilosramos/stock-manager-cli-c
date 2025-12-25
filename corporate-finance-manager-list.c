#include <stdio.h>
#include <stdlib.h>

typedef struct dados_financeiros
{
    int ano;
    float entrada;
    float saida;
    float VAR;
    float estoque;
    float materiaPrima;
    float SAP;
    float fornecedor;
    float extras;
    float DLPA; // lucro/prejuízo
    struct dados_financeiros *prox;
} dados_financeiros;

int menu();
int miniMenu();
dados_financeiros *dados_novos();
void ler_dados(dados_financeiros *dadoanual);
void incluir_inicio(dados_financeiros **lista, dados_financeiros *novo);
void incluir_fim(dados_financeiros **lista, dados_financeiros *novo);
void listar_registros(dados_financeiros *lista);
void mostrar_dados_registro(dados_financeiros *registro);

int main()
{
    dados_financeiros *lista = NULL, *aux;
    int opcao, opcao2;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            opcao2 = miniMenu();
            aux = dados_novos();
            ler_dados(aux);
            switch (opcao2)
            {
            case 1:
                incluir_inicio(&lista, aux);
                break;
            case 2:
                incluir_fim(&lista, aux);
                break;
            }
            break;
        case 2:
            break;
        case 3:
            printf("----------------------------------------------------------\n");
            listar_registros(lista);
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            break;
        }

    } while (opcao != 0);

    return 0;
}

int menu()
{
    int opcao;
    printf("1.Inserir Dado Anual\n");
    printf("2.Balanco Patrimonial\n");
    printf("3.Relatorio Lucro/Prejuizo (DLPA)\n");
    printf("4.Caixa da Empresa\n");
    printf("5.Fluxo de Caixa\n");
    printf("0.Sair\n");
    scanf("%d", &opcao);
    getchar();

    return opcao;
}

int miniMenu()
{
    int opcao2;
    printf("1.Inserir no Inicio\n");
    printf("2.Inserir no Fim\n");
    scanf("%d", &opcao2);

    return opcao2;
}

void ler_dados(dados_financeiros *dadoanual)
{
    printf("Ano:\n");
    scanf("%d", &dadoanual->ano);
    printf("Valor de Entrada Anual:\n");
    scanf("%f", &dadoanual->entrada);
    printf("Valor de Saída Anual:\n");
    scanf("%f", &dadoanual->saida);
    printf("Valores a Receber:\n");
    scanf("%f", &dadoanual->VAR);
    printf("Valor do Estoque de Produtos:\n");
    scanf("%f", &dadoanual->estoque);
    printf("Valor da Materia Prima em Estoque:\n");
    scanf("%f", &dadoanual->materiaPrima);
    printf("Salarios a Pagar:\n");
    scanf("%f", &dadoanual->SAP);
    printf("Valor do Fornecedor:\n");
    scanf("%f", &dadoanual->fornecedor);
    printf("Gastos Extras(impostos, alugueis, etc):\n");
    scanf("%f", &dadoanual->extras);
}

dados_financeiros *dados_novos()
{
    dados_financeiros *novo = (dados_financeiros *)malloc(sizeof(dados_financeiros));
    novo->prox = NULL;
    return novo;
}

void incluir_inicio(dados_financeiros **lista, dados_financeiros *novo)
{
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        novo->prox = *lista;
        *lista = novo;
    }
}

void incluir_fim(dados_financeiros **lista, dados_financeiros *novo)
{
    if (*lista == NULL)
    {
        *lista = novo;
        novo->prox = NULL;
    }
    else
    {
        dados_financeiros *aux = *lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
    }
}

void listar_registros(dados_financeiros *lista)
{
    dados_financeiros *aux = lista;

    while (aux != NULL)
    {
        mostrar_dados_registro(aux);
        aux = aux->prox;
    }
}

void mostrar_dados_registro(dados_financeiros *registro)
{
    printf("Ano: %d\n", registro->ano);
    printf("Entrada: %2.f\n", registro->entrada);
    printf("Saida: %2.f\n", registro->saida);
    printf("Valores a Receber: %2.f\n", registro->VAR);
    printf("Valor em Estoque: %2.f\n", registro->estoque);
    printf("Valor da Materia Prima em Estoque: %2.f\n", registro->saida);
    printf("Salarios a Pagar: %2.f\n", registro->SAP);
    printf("Fornecedor: %2.f\n", registro->fornecedor);
    printf("Gastos extras: %2.f\n", registro->extras);
    printf("----------------------------------------------------------\n");
}
