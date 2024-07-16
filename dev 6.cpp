#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para registrar nomes
void registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings

    FILE *file = fopen(arquivo, "w"); // cria o arquivo
    if (file == NULL) {
        printf("Erro ao criar arquivo!\n");
        return;
    }
    fprintf(file, "%s,", cpf); // salva o valor da variável
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Dados cadastrados com sucesso!\n");
    system("pause");
}

// Função para consultar nomes
void consulta() {
    char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo, não localizado!\n");
        system("pause");
        return;
    }

    printf("\nEssas são as informações do usuário:\n");
    while (fgets(conteudo, 100, file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);
    printf("\n\n");
    system("pause");
}

// Função para deletar registros
void deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Arquivo deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar arquivo! Arquivo não encontrado.\n");
    }
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    int opcao = 0;
    int laco = 1;

    while (laco == 1) {
        system("cls");

        printf("### Cartório da EBAC ###\n\n"); // início do menu
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t0 - Sair\n\n"); // opção para sair do programa
        printf("Opção: "); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usuário

        system("cls");

        switch (opcao) { // início da seleção
            case 1:
                registro();
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 0:
                printf("Saindo do programa...\n");
                laco = 0; // termina o loop
                break;

            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        } // fim da seleção
    }

    return 0;
}

