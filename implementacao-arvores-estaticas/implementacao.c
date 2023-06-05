#include <stdio.h>
#include <stdlib.h>

#define tamanho 100
#define E 0
#define D 1
#define R -1

struct str_no {
    char dado;
    int esquerda;
    int direita;
    int pai;
};

struct str_no arvore[tamanho];
int lado, indice = 0;
int opt = -1;
char pai, no;

//prototipação
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);
void menu_mostrar(void);

//procura no
int arvore_procura(char dado){
    if(indice != 0){
        for(int i = 0; i < indice; i++){
            if(arvore[i].dado == dado){
                return (i);
            }
        }
    } else {
        return (0);
    }
}

//inserir no
void arvore_insere(int pai, char dado, int lado){
    switch(lado){
        case E:
            arvore[pai].esquerda = indice;
            arvore[indice].dado = dado;
            arvore[indice].pai = pai;
            arvore[indice].esquerda = -1;
            arvore[indice].direita = -1;
            indice++;
            break;
        case D:
            arvore[pai].direita = indice;
            arvore[indice].dado = dado;
            arvore[indice].pai = pai;
            arvore[indice].esquerda = -1;
            arvore[indice].direita = -1;
            indice++;
            break;
        case R:
            arvore[indice].dado = dado;
            arvore[indice].pai = -1;
            arvore[indice].esquerda = -1;
            arvore[indice].direita = -1;
            indice++;
            break;
    }
}

//desenha o menu na tela
void menu_mostrar(void){
    system("cls");
    for(int i = 0; i < indice; i++){
        printf("| %c ", arvore[i].dado);
    }
    printf("\n1 - Inserir um NO na arvore");
    printf("\n2 - Pesquisar um NO na arvore");
    printf("\n0 - Sair...\n\n");
}

int main(void){
    int temp;
    do{
        menu_mostrar();
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("\nDigite o valor do PAI (char): ");
                scanf("%c", &pai);
                scanf("%c", &pai);
                printf("Digite o valor do NO (char): ");
                scanf("%c", &no);
                scanf("%c", &no);
                printf("digite o lado da subarvore E=%d/D=%d/R=%d (int): ", E, D, R);
                scanf("%d", &lado);
                break;
            case 2:
                printf("Digite o valor do NO: (char)");
                scanf("%c", &no);
                scanf("%c", &no);
                fflush("stdin");
                temp = arvore_procura(no);
                printf("No %c\nFilho esquerda: %c\nFilho Direita: %c\n\n", arvore[temp].dado, arvore[arvore[temp].esquerda].dado, arvore[arvore[temp].direita].dado);
                system("pause");
                break;
        }
    } while(opt != 0);
    system("pause");
    return (0);
}
