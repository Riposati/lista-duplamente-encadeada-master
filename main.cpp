#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct lista{
    int v;
    struct lista *prox;struct lista *ant;
}typedef Lista;

Lista *insere(Lista *ini,int v){

    Lista *aux = new(Lista);
    aux->v = v;
    aux->prox = aux;
    aux->ant = aux;

    if(ini==NULL)
        ini = aux;
    else{ // jeito legal
        aux->ant = ini->ant;
        ini->ant->prox = aux;
        aux->prox = ini;
        ini->ant = aux;
    }
    return ini;
}

void show(Lista *ini){

    if(ini==NULL){
        printf("A lista esta vazia!\n");
    }else{

        Lista *aux = ini;

        while(aux->prox!=ini){
            printf("%d -> ",aux->v);
            aux = aux->prox;
        }
        printf("%d -> ",aux->v); // sen�o n�o mostra o �ltimo bloco
    }
}

void showBack(Lista *ini){

     if(ini==NULL){
        printf("A lista esta vazia!\n");
    }else{

        Lista *aux = ini;

        while(aux->ant!=ini){
            aux = aux->ant;
            printf("%d -> ",aux->v);
        }
        printf("%d -> ",aux->ant->v); // sen�o n�o mostra o primeiro bloco
    }
}

Lista *deletar(Lista *ini, int chave){

    Lista *aux = ini;

    if(ini->v==chave){ // é o primeiro bloco
        
        aux = ini->prox;
        aux->ant = ini->ant;
        ini->ant->prox=aux;
        
        if(ini->prox==ini && ini->ant==ini){ // se for só um bloco

            free(ini);
            ini = NULL;
    
        }else{
         
            free(ini);
            ini = aux;
        }

    }else if(aux->prox!=ini && aux->v!=chave){

        while(aux->v!=chave && aux->prox!=ini){
            aux = aux->prox;
        }

        if(aux->prox!=ini && aux->v==chave){ // tá no meio

            Lista *aux2 = aux->ant;
            aux2->prox=aux->prox;
            aux2->prox->ant=aux2;
            free(aux);

        }else if(aux->prox==ini && aux->v==chave){ // tá no final da lista

            Lista *aux2 = aux->ant;
            aux2->prox = ini;
            ini->ant = aux2;
            free(aux);
        }
    }

    return ini;
}

int main()
{
    Lista *ini = NULL;
    srand(time(0));

    printf("Lista dupla circular com numeros randomicos\n\n\n");

    for(int i=0;i<=6;i++)
        ini = insere(ini,i);
    show(ini);
    printf("\n\n");
    showBack(ini);
    printf("\n\n");

    ini = deletar(ini,0);
    ini = deletar(ini,1);
    ini = deletar(ini,2);
    ini = deletar(ini,2);
    ini = deletar(ini,3);
    /*ini = deletar(ini,4);
    ini = deletar(ini,6);
    ini = deletar(ini,5);*/

    ini = insere(ini,555);
    ini = deletar(ini,4848);
    ini = deletar(ini,555);
    ini = insere(ini,1);
    ini = insere(ini,2);
    ini = insere(ini,3);

    ini = deletar(ini,3);
    ini = deletar(ini,2);
    ini = deletar(ini,1);

    show(ini);
    printf("\n\n");
    showBack(ini);
    printf("\n\n");

    system("pause");
    return 0;
}
