#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./src/struct.h"
#include "./src/arq.h"
#include "./src/heap.h"

void inserir(Heap *p, char message[]){

    if(p == NULL || p->vet == NULL){
        strcpy(message, "[ ERRO ]: Algo deu Errado!");
        return;
    }

    if(isFull(p)){
        strcpy(message, "[ ERRO ]: Fila Cheia!");
        return;
    }

    Item *item = (Item *)malloc(sizeof(Item));

    system("clear");
    
    printf("\n ===== INSERIR NOVO ITEM =====");

    printf("\n");

    read_string("\n Nome : ", item->name,   MAX_STR);
    read_string("\n Curso: ", item->course, MAX_STR);

    printf("\n Matricula: ");
    scanf("%lld", &item->registration);

    printf("\n Ranking: ");
    scanf("%d", &item->ranking);

    int c; while ((c = getchar()) != '\n' && c != EOF);

    int iterations = insertHeap(p, *item);

    printf("\n  [ SUCESSO ]: Item Inserido. Numero de Iteracoes: %d", iterations);

    printf("\n\n");

    continuar();

    return;
}

void remover(Heap *p, char message[]){

    if(p == NULL || p->vet == NULL){
        strcpy(message, "[ ERRO ]: Algo deu Errado!");
        return;
    }

    if(isEmpty(p)){
        strcpy(message, "[ ERRO ]: Fila Vazia!");
        return;
    }

    system("clear");

    printf("\n ===== REMOVER ITEM =====");

    printf("\n\n");

    Item *item = removeHeap(p);

    printf("  [ SUCESSO ]: Item Removido!");

    printf("\n\n");

    printItem(item);

    printf("\n\n");

    continuar();

    return;
}

void consultar(Heap *p, char message[]){

    if(p == NULL || p->vet == NULL){
        strcpy(message, "[ ERRO ]: Algo deu Errado!");
        return;
    }

    if(isEmpty(p)){
        strcpy(message, "[ ERRO ]: Fila Vazia!");
        return;
    }

    system("clear");

    printf("\n ===== CONSULTAR ITEM =====");

    printf("\n\n");

    Item *item = getLargest(p);

    printf("  [ SUCESSO ]: Item Acessado!");

    printf("\n\n");

    printItem(item);

    printf("\n\n");

    continuar();

    return;

}   

void exibir(Heap *p, char message[]){

    if(p == NULL || p->vet == NULL){
        strcpy(message, "[ ERRO ]: Algo deu Errado!");
        return;
    }

    if(isEmpty(p)){
        strcpy(message, "[ ERRO ]: Fila Vazia!");
        return;
    }

    system("clear");

    printf("\n ===== EXIBIR FILA =====");

    printf("\n\n");

    traverseHeap(p);

    printf("\n\n");

    continuar();

    return;

}

void verificar_fila_cheia(Heap *p, char message[]){


    if(isFull(p)){
        strcpy(message, "Fila Cheia!");
    } else {
        strcpy(message, "Fila Não Cheia!");
    }

    return;
}

void verificar_fila_vazia(Heap *p, char message[]){

    if(isEmpty(p)){
        strcpy(message, "Fila Vazia!");
    } else {
        strcpy(message, "Fila Não Vazia!");
    }

    return;

}

void tamanho_da_fila(Heap *p, char message[]){

    printf("\n  Tamanho da Fila: %d", size(p));

    printf("\n\n");

    continuar();

    return;

}

void quantidade_iteracoes(Heap *p, char message[]){


    printf("\n  Quantidade de Iteracoes: %lld", p->totalIterations);

    printf("\n\n");

    continuar();

}

void carregar_arquivo(Heap *p, char message[]){
    
    printf("\n ===== CONSULTAR ITEM =====");
    
    printf("\n\n");

    int numRecords = 0;

    printf("\n  Insira o NUMERO DE REGISTROS que DESEJA: ");
    scanf("%d", &numRecords);

    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("\n");

    int iterations = 0;
    
    int numInsertions = loadRegistrations(p, "dataset.csv", numRecords, &iterations);

    printf("  [ SUCESSO ]: %d Registros Carregados!", numInsertions);

    printf("\n\n");

    continuar();

    return;
}

void sair(){

    system("clear");

    printf("\n  Saindo...\n");

    return;

}

void invalido(char message[]){

    strcpy(message, "Opcao Invalida!");

    return;
}

void menu(char message[]){

    int thereIsAMessage = strlen(message);

    system("clear");

    printf("\n ======================================");
    printf("\n     Heap Priority Queue - Menu");
    printf("\n ======================================");
    printf("\n");

    if(thereIsAMessage){
        printf("\n   %s", message);
    } else {
        printf("\n");
    }

    printf("\n");
    printf("\n  1.  Inserir Novo Item");
    printf("\n  2.  Remover Item de MAIOR PRIORIDADE");
    printf("\n  3.  Consultar Item de MAIOR PRIORIDADE");
    printf("\n  4.  Verificar Fila Vazia");
    printf("\n  5.  Verificar Fila Cheia");
    printf("\n  6.  Verificar Tamanho da Fila");
    printf("\n  7.  Imprimir TODOS OS ITENS");
    printf("\n  8.  Importar Arquivo CSV");
    printf("\n  9.  Verificar Total de Iteracoes");


    printf("\n");

    printf("\n  0. Sair");

    printf("\n");
    printf("\n  Insira uma OPCAO.");   
    printf("\n");

    printf("\n  >>> ");
}

int main(){

    Heap *p = createHeap();

    int opt = -1;

    char message[32] = "";

    do {

        menu(message);

        scanf("%d", &opt);
        int c; while ((c = getchar()) != '\n' && c != EOF);

        switch(opt){
            case 1:  inserir(p, message);                     break;
            case 2:  remover(p, message);                     break;
            case 3:  consultar(p, message);                   break;
            case 4:  verificar_fila_vazia(p, message);        break;
            case 5:  verificar_fila_cheia(p, message);        break;
            case 6:  tamanho_da_fila(p, message);             break;
            case 7:  exibir(p, message);                      break;
            case 8:  carregar_arquivo(p, message);            break;
            case 9:  quantidade_iteracoes(p, message);        break;
            case 0:  sair();                                  break;
            default: invalido(message);                       break;
        }


    } while (opt != 0);

    destroyHeap(p);

    return 0;
}

// INTERFACE

// Inserir na Fila
// Remover Item de Maior Prioridade
// Consultar Item de Maior Prioridade

// Exibir Fila

// Verificar Fila Cheia
// Verificar Fila Vazia

// Tamanho da Fila

// Carregar Arquivo CSV

// Sair