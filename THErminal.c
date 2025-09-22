#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Struct do aplicativo de agenda.
typedef struct{
    char nome[100];
    char telefone[15];
} Contatos;

// Quantidade maxima de contatos suportada e numero de contatos.
Contatos agenda[50];
int numcont;

//Funcoes que serao chamadas futuramente dos aplicativos.
void calculadora (int a, int b, char c); // OK
void editor (char *a, char *b);

//Funcao que sai dos aplicativos e do terminal
void sair(){
    printf("Saindo...");
    exit(0);
}

int main(){
    while(1){
        // Essa funcao chama o terminal.
        char comando[100];
        printf("Seja bem vindo ao THErminal! A lista de aplicacoes e:\n-Calculadora\n-Agenda\n-Editor\nEm breve, mais recursos!\n");
        printf("THErminal>> ");
        scanf("%s", comando);
        if(strcmp("exit",comando) == 0){
            sair();
        }
        // Essa funcao chama a funcao calculadora.
        if(strcmp("calculadora",comando) == 0){
            while(1){
                int a, b;
                char c;
                printf("Calculadora...\n");
                printf("Insira dois inteiros valores e seu operador, respectivamente:");
                scanf("%d %d %c", &a, &b, &c);
                printf("Os valores inseridos foram: %d e %d e o operador foi %c.\n", a, b, c);
                calculadora(a, b, c);
                if(strcmp("exit", comando) == 0){
                    sair();
                }
            }
        }
        // Essa funcao chama a funcao de agenda.
        
        if(strcmp("agenda", comando) == 0){
            char comando1[9];
            FILE* caderno;
            caderno = fopen("caderninho.txt", "a");
            printf("Agenda...\n");
            printf("Para criar um contato na agenda, digite 'criar'.\nPara verificar sua agenda, digite 'verificar'.\nDigite aqui: ");
            scanf("%s", comando1);
        // Criacao de um novo contato
            if(strcmp("criar", comando1) == 0){
                Contatos contato;
                char verifica[3];
                printf("Digite o nome: ");
                scanf("%99s", contato.nome);
                printf("Agora, o telefone: ");
                scanf("%14s", contato.telefone);
                printf("Confirme se as informacoes digitadas estao corretas:\n");
                printf("Nome: %s\n", contato.nome);
                printf("Telefone: %s\n", contato.telefone);
                printf("Digite 'sim' para confirmar, ou 'nao' para alterar os dados: ");
                scanf("%s", verifica);
                if(strcmp("sim", verifica) == 0){        
                    fprintf(caderno, "%s", "\nNome: ");
                    fprintf(caderno, "%s", contato.nome);
                    fprintf(caderno, "%s", "\nTelefone: ");
                    fprintf(caderno, "%s", contato.telefone);
                    fprintf(caderno, "%s", "\n--------------------");
                    fclose(caderno);
                    printf("O contato foi criado e gravado!\nSaindo...\n");
                } 
                if(strcmp("nao", verifica) == 0){
                    char altera[9];
                    printf("Digite o que deseja alterar:\nnome ou telefone: ");
                    scanf("%8s", altera);
                    if(strcmp("nome", altera) == 0){
                        printf("Digite o nome corrigido: ");
                        scanf("%99s",contato.nome);
                        printf("O novo nome e: %s", contato.nome);
                        fprintf(caderno, "%s", "\nNome: ");
                        fprintf(caderno, "%s", contato.nome);
                        fprintf(caderno, "%s", "\nTelefone: ");
                        fprintf(caderno, "%s", contato.telefone);
                        fprintf(caderno, "%s", "\n--------------------");
                        fclose(caderno);
                        printf("O contato foi criado e gravado!\nSaindo...\n");
                    }
                    if(strcmp("telefone", altera) == 0){
                        printf("Digite o telefone corigido: ");
                        scanf("%14s", contato.telefone);
                        printf("O novo telefone e: %s\n", contato.telefone);
                        fprintf(caderno, "%s", "\nNome: ");
                        fprintf(caderno, "%s", contato.nome);
                        fprintf(caderno, "%s", "\nTelefone: ");
                        fprintf(caderno, "%s", contato.telefone);
                        fprintf(caderno, "%s", "\n--------------------");
                        fclose(caderno);
                        printf("O contato foi criado e gravado!\nSaindo...\n");
                    }
                }            
            }
// Editor de texto  
        }
        if(strcmp("editor", comando) == 0){
            char texto[1000];
            char nome[50];
            printf("Editor de texto...\n>> ");
            getchar();
            scanf("%[^\n]", texto);
            printf("Insira o nome do arquivo e sua extensao: ");
            scanf("%49s", nome);
            editor(texto, nome);
        }   
    }
}

    void calculadora (int a, int b, char c){

        switch(c){
            case '+':{
                int soma;
                soma = a + b;
                printf("A soma dos valores e = %d.", soma);
                break;
                }
            case '-':{
                int subtrai;
                subtrai = a - b;
                printf("A subtracao dos valores e = %d.", subtrai);
                break;
            }
            case '*':{
                int multiplica;
                multiplica = a * b;
                printf("A multiplicacao dos valores e = %d.", multiplica);
                break;
            }
            case '/':{
                int divide;
                divide = a / b;
                printf("A divisao dos valores e = %d.", divide);
                break;
            }
            default:
                printf("Os valores inseridos sao invalidos! Tente novamente.");
                exit(0);
        }
    }

    void editor(char *a, char *b){
            FILE* arquivo;

        arquivo = fopen(b, "a");
        if (arquivo == NULL){
            printf("Sem arquivo. Tente Novamente");
            return;
        }
        fprintf(arquivo, "%s\n", a);
        fclose(arquivo);
        printf("Texto salvo!\n");
        
    }