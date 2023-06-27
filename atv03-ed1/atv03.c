#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct no{
  int valor; 
  struct no *proximo; 
}No; 

void remover(No **lista, int num){
    No *aux, *no= NULL; 

    if(*lista){ 
      if((*lista)->valor == num){ 
        no = *lista; 
        *lista = no->proximo; 
      }else{ 
        aux = *lista; 
        while(aux->proximo != NULL && aux->proximo->valor != num) 
            aux = aux->proximo; 
        if(aux->proximo != NULL){ 
            no = aux->proximo; 
            aux->proximo = no->proximo; 
    } 
  } 
} 
  if(no != NULL){
    free(no); 
  }
}