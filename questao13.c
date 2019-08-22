#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SUCESSO 1
#define FALHA -1
#define TAM 1000
 
typedef struct Dados dado;
 
struct Dados{
    char nome[TAM];
    dado *prox;
    dado *ant;
};
 
typedef struct Descricao Descritor;
 
struct Descricao{
    unsigned int tam;
    dado *inicio;
    dado *fim;
};
 
dado *Cabeca;
Descritor *descritor;
 
int crialista(dado **Cabeca, Descritor **descritor){
    Cabeca=(dado**)malloc(sizeof(dado*));
    (*descritor)=(Descritor*)malloc(sizeof(Descritor));
    if(Cabeca!=NULL && (*descritor)!=NULL){
        Cabeca=(dado**)NULL;
        (*descritor)->inicio=(dado*)NULL;
        (*descritor)->fim=(dado*)NULL;
        (*descritor)->tam=0;
        return SUCESSO;
    }
        else{FALHA;}
}
 
int insere(dado *no){
    dado *aux;
    aux=(dado*)malloc(sizeof(dado));
    if(aux==NULL)return FALHA;
    else{
        if(descritor->tam==0){
            strcpy(aux->nome, no->nome);
            descritor->inicio=aux;
            descritor->fim=aux;
            aux->ant=descritor->fim;
            aux->prox=descritor->inicio;
            descritor->tam++;
            Cabeca=descritor->inicio;
            return SUCESSO;
        }
        strcpy(aux->nome, no->nome);
        (descritor->fim)->prox=aux;
        aux->ant=descritor->fim;
        aux->prox=descritor->inicio;
        (descritor->inicio)->ant=aux;
        descritor->fim=aux;
        descritor->tam++;
    }
    Cabeca=descritor->inicio;
    return SUCESSO;
}
 
int excluir(dado **x){
    int i;
    dado *aux=NULL;
    dado *aux2=NULL;
    aux=descritor->inicio;
    for(i=0; i<descritor->tam; i++){
        if(strcmp((descritor->inicio)->nome, (*x)->nome)==0){
            aux=descritor->inicio;
            aux2=aux->prox;
            aux2->ant=aux->ant;
            descritor->inicio=aux2;
            (descritor->fim)->prox=aux2;
            free(aux);
            descritor->tam--;
            Cabeca=descritor->inicio;
            return (SUCESSO);
        }
        if(strcmp((descritor->fim)->nome, (*x)->nome)==0){
            aux=descritor->fim;
            aux2=aux->ant;
            aux2->prox=aux->prox;
            descritor->fim=aux2;
            (descritor->inicio)->ant=aux2;
            free(aux);
            descritor->tam--;
            return (SUCESSO);
        }
        if(strcmp(aux->nome, (*x)->nome)==0){
            aux2=aux->ant;
            aux2->prox=aux->prox;
            aux2=aux->prox;
            aux2->ant=aux->ant;
            free(aux);
            descritor->tam--;
            return (SUCESSO);
        }
        aux=aux->prox;
    }
}
 
int verifica_direita(dado **p, dado *no){
    dado *aux;
    int i;
    aux=(*p);
    if(strcmp(aux->nome, "vovo")==0)aux=aux->prox;
        for(i=0;i<2;i++){
            if(strcmp(aux->nome, no->nome)==0){
                excluir(&no);
                return SUCESSO;
            }
            aux=aux->prox;
        }
        return FALHA;
}
 
int verifica_esquerda(dado **p, dado *no){
    dado *aux;
    int i;
    aux=(*p);
    if(strcmp(aux->nome, "vovo")==0)aux=aux->ant;
        for(i=0;i<2;i++){
            if(strcmp(aux->nome, no->nome)==0){
                excluir(&no);
                return SUCESSO; 
            }
            aux=aux->ant;
        }
        return FALHA;
}
 
int main(){
    dado nomes;
    unsigned int cont=0, i=0, resultado=0;
    char esq_dir[10];
    if(crialista(&Cabeca, &descritor)==FALHA)puts("falha");
    strcpy(nomes.nome, "vovo");
    insere(&nomes);
    do{
        scanf("%s", nomes.nome);
        getchar();
        if(strcmp(nomes.nome, "FIM")!=0){
            insere(&nomes);
            cont+=1;
        }
    }while(strcmp(nomes.nome, "FIM")!=0);
    for(i=0; i<cont; i++){
        scanf("%s", nomes.nome);
        getchar();
        scanf("%s", esq_dir);
        getchar();
        if(strcmp(esq_dir, "direita")==0){
            if(verifica_direita(&Cabeca, &nomes)==SUCESSO)resultado+=1;
        }
            else{
                if(verifica_esquerda(&Cabeca, &nomes)==SUCESSO)resultado+=1;
            }
    }
    printf("%d\n", resultado);
    return 0;
}
