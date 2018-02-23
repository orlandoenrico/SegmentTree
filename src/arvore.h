/*
arvore.h
Autor: Orlando Enrico Liz Silvério Silva
Data: 27/08/17
*/

#ifndef ARVORE_H
#define ARVORE_H
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#include "T.h"

/*------------------------------------------------------------------------------
 Função:  retorna índice correspondente aos filhos da esquerda de um nó
 Entrada: inteiro i que indica a posição atual no vetor.
 Saída:   inteiro com a nova posição.
------------------------------------------------------------------------------*/
int esquerda(int i);

/*------------------------------------------------------------------------------
 Função:  retorna índice correspondente aos filhos da direita de um nó
 Entrada: inteiro i que indica a posição atual no vetor.
 Saída:   inteiro com a nova posição.
------------------------------------------------------------------------------*/
int direita(int i);

/*------------------------------------------------------------------------------
 Função:  devolve o meio do vetor.
 Entrada: inteiros l e r que representam o intervalo do vetor [l, r].
 Saída:   inteiro com a posição.
------------------------------------------------------------------------------*/
int meio(int l, int r);

/*------------------------------------------------------------------------------
 Função:  constrói a Árvore de Segmentação com seus 2n-1 nós, calculando a tupla
 		  correspondente apenas uma vez.
 Entrada: vetor do tipo T (tupla) que será a árvore, vetor v que contem os
 		  elementos que serão utilizados como referência, um índice da raiz
 		  e os inteiros correspondentes ao intervalo do vetor v ([l=1, r=N]).
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void constroiArvore(T arvore[], int v[], int index, int l, int r);

/*------------------------------------------------------------------------------
 Função:  adiciona 1 nos elementos do intervalo (nós folha) [L, R] e atualiza
 		  todos os seus nós anteriores até a raiz.
 Entrada: vetor do tipo T que será a árvore, un índice da raiz (1),
 		  intervalo do vetor v [l=1, r=N] e o intervalo sobre o qual se quer
 		  realizar a operação [L, R].
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void add(T arvore[], int index, int l, int r, int L, int R);

/*------------------------------------------------------------------------------
 Função:  subtrai 1 dos elementos do intervalo (nós folha) [L, R] e atualiza
 		  todos os seus nós anteriores até a raiz.
 Entrada: vetor do tipo T que será a árvore, um índice da raiz (1),
 		  intervalo do vetor v [l=1, r=N] e o intervalo sobre o qual se quer
 		  realizar a operação [L, R].
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void sub(T arvore[], int index, int l, int r, int L, int R);

/*------------------------------------------------------------------------------
 Função:  consulta a soma de um intervalo dado.
 Entrada: vetor do tipo T que será a árvore, um índice da raiz (1), 
 		  intervalo do vetor v [l=1, r=N] e o intervalo sobre o qual se quer
 		  extrair a soma [L, R].
 Saída:   a soma do intervalo em questão.
------------------------------------------------------------------------------*/
int consultaSum(T arvore[], int index, int l, int r, int L, int R);

/*------------------------------------------------------------------------------
 Função:  consulta o valor mínimo de um intervalo dado.
 Entrada: vetor do tipo T que será a árvore, um índice da raiz (1),
 		  intervalo do vetor v [l=1, r=N] e o intervalo sobre o qual se quer
 		  extrair o mínimo [L, R].
 Saída:   o valor mínimo do intervalo em questão.
------------------------------------------------------------------------------*/
int consultaMin(T arvore[], int index, int l, int r, int L, int R);

/*------------------------------------------------------------------------------
 Função:  consulta o valor máximo de um intervalo dado.
 Entrada: vetor do tipo T que será a árvore, um índice da raiz (1),
 		  intervalo do vetor v [l=1, r=N] e o intervalo sobre o qual se quer
 		  extrair o máximo [L, R].
 Saída:   o valor máximo do intervalo em questão.
------------------------------------------------------------------------------*/
int consultaMax(T arvore[], int index, int l, int r, int L, int R);

#endif
