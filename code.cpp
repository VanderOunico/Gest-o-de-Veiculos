#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_LINHAS 10
#define MAX_COLUNAS 10

int matriz[MAX_LINHAS][MAX_COLUNAS];


// Definição da estrutura Veiculo
typedef struct {
    char marca[30];
    char modelo[30];
    int anoFabricacao;
    int anoModelo;
    float preco;
    int ocupado; 
} Veiculo;

// Função para cadastrar um veículo
void cadastrarVeiculo(Veiculo matrizVeiculos[MAX_LINHAS][MAX_COLUNAS]) {
    int i, j;
    printf("Informe a linha (0-9): ");
    scanf("%d", &i);
    printf("Informe a coluna (0-9): ");
    scanf("%d", &j);
    
    if (i < 0 || i >= MAX_LINHAS || j < 0 || j >= MAX_COLUNAS) {
        printf("Posição inválida!\n");
        return;
    }
    
    if (matrizVeiculos[i][j].ocupado) {
        printf("Já existe um veículo nessa posição!\n");
        return;
    }
    
    printf("Marca: ");
    scanf("%s", matrizVeiculos[i][j].marca);
    printf("Modelo: ");
    scanf("%s", matrizVeiculos[i][j].modelo);
    printf("Ano de Fabricação: ");
    scanf("%d", &matrizVeiculos[i][j].anoFabricacao);
    printf("Ano do Modelo: ");
    scanf("%d", &matrizVeiculos[i][j].anoModelo);
    printf("Preço: ");
    scanf("%f", &matrizVeiculos[i][j].preco);
    matrizVeiculos[i][j].ocupado = 1;
    printf("Veículo cadastrado com sucesso!\n");
}

// Função para excluir um veículo
void excluirVeiculo(Veiculo matrizVeiculos[MAX_LINHAS][MAX_COLUNAS]) {
    int i, j;
    printf("Informe a linha (0-9): ");
    scanf("%d", &i);
    printf("Informe a coluna (0-9): ");
    scanf("%d", &j);
    
    if (i < 0 || i >= MAX_LINHAS || j < 0 || j >= MAX_COLUNAS || !matrizVeiculos[i][j].ocupado) {
        printf("Nenhum veículo encontrado nessa posição!\n");
        return;
    }
    
    matrizVeiculos[i][j].ocupado = 0;
    printf("Veículo excluído com sucesso!\n");
}

// Função para consultar um veículo
void consultarVeiculo(Veiculo matrizVeiculos[MAX_LINHAS][MAX_COLUNAS]) {
    int i, j;
    printf("Informe a linha (0-9): ");
    scanf("%d", &i);
    printf("Informe a coluna (0-9): ");
    scanf("%d", &j);
    
    if (i < 0 || i >= MAX_LINHAS || j < 0 || j >= MAX_COLUNAS || !matrizVeiculos[i][j].ocupado) {
        printf("Nenhum veículo encontrado nessa posição!\n");
        return;
    }
    
    printf("Marca: %s\n", matrizVeiculos[i][j].marca);
    printf("Modelo: %s\n", matrizVeiculos[i][j].modelo);
    printf("Ano de Fabricação: %d\n", matrizVeiculos[i][j].anoFabricacao);
    printf("Ano do Modelo: %d\n", matrizVeiculos[i][j].anoModelo);
    printf("Preço: %.2f\n", matrizVeiculos[i][j].preco);
}

// Função para imprimir todos os veículos
void imprimirVeiculos(Veiculo matrizVeiculos[MAX_LINHAS][MAX_COLUNAS]) {
    for (int i = 0; i < MAX_LINHAS; i++) {
        for (int j = 0; j < MAX_COLUNAS; j++) {
            if (matrizVeiculos[i][j].ocupado) {
                printf("Posição [%d][%d]: Marca: %s, Modelo: %s, Ano Fabricação: %d, Ano Modelo: %d, Preço: %.2f\n",
                    i, j,
                    matrizVeiculos[i][j].marca,
                    matrizVeiculos[i][j].modelo,
                    matrizVeiculos[i][j].anoFabricacao,
                    matrizVeiculos[i][j].anoModelo,
                    matrizVeiculos[i][j].preco);
            }
        }
    }
}

int main() {
    
	Veiculo matrizVeiculos[MAX_LINHAS][MAX_COLUNAS] = {0}; 
    setlocale(LC_ALL, "Portuguese");
	int opcao;
    do {
        printf("\nMENU:\n");
        printf("1 - Cadastrar Veículo\n");
        printf("2 - Excluir Veículo\n");
        printf("3 - Consultar Veículo\n");
        printf("4 - Imprimir Todos os Veículos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarVeiculo(matrizVeiculos);
                break;
            case 2:
                excluirVeiculo(matrizVeiculos);
                break;
            case 3:
                consultarVeiculo(matrizVeiculos);
                break;
            case 4:
                imprimirVeiculos(matrizVeiculos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
