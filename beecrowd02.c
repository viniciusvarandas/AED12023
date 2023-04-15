#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    struct No* proximo;
} No;

No* inserir(No* lista, char* nome) {
    No* novo = (No*) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
  
    if (lista == NULL) {
        lista = novo;
    }
    
    else {
        No* atual = lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    
    return lista;
}

No* buscar(No* lista, char* nome) {
    No* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

No* inserirAntesDe(No* lista, No* amigo, No* novos) {
    if (amigo == NULL) {
        return lista;
    }
  
    if (amigo == lista) {
        No* atual = novos;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = lista;
        lista = novos;
    }
    
    else {
        No* anterior = lista;
        while (anterior->proximo != amigo) {
            anterior = anterior->proximo;
        }
        No* atual = novos;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = amigo;
        anterior->proximo = novos;
    }
    return lista;
}

int main() {
    char listaAtual[500];
    fgets(listaAtual, 500, stdin);
    listaAtual[strlen(listaAtual) - 1] = '\0'; 
    
    No* lista = NULL;
    char* nome = strtok(listaAtual, " ");
    while (nome != NULL) {
        lista = inserir(lista, nome);
        nome = strtok(NULL, " ");
    }
    
    char novaLista[500];
    fgets(novaLista, 500, stdin);
    novaLista[strlen(novaLista) - 1] = '\0';
    
    No* novosAmigos = NULL;
    nome = strtok(novaLista, " ");
    while (nome != NULL) {
        novosAmigos = inserir(novosAmigos, nome);
        nome = strtok(NULL, " ");
    }
    
    char amigoIndicado[50];
    fgets(amigoIndicado, 50, stdin);
    amigoIndicado[strlen(amigoIndicado) - 1] = '\0';
    
    No* amigo = buscar(lista, amigoIndicado);
    lista = inserirAntesDe(lista, amigo, novosAmigos);
    
    No* atual = lista;
    while (atual != NULL) {
        printf("%s ", atual->nome);
        atual = atual->proximo;
    }
    
    return 0;
}
