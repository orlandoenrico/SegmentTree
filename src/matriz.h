/*
matriz.h
Autor: Orlando Enrico Liz Silvério Silva
*/
#ifndef MATRIZ_H
#define MATRIZ_H

#include "T.h"

typedef struct {
    T **data; //matriz 
    int size; //tamanho da matriz
} Matrix;

/*------------------------------------------------------------------------------
 Função:  aloca a matriz de tamanho size x size.
 Entrada: ponteiro para a estrutura que possui a matriz e o seu tamanho.
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void criaMatriz(Matrix *matrix, int size) ;

/*------------------------------------------------------------------------------
 Função:  calcula o mínimo, máximo e a soma de um intervalo [n1, n2].
 Entrada: ponteiro para o vetor e os inteiros que formam o intervalo [n1, n2].
 Saída:   uma tupla (struct T) cuja composição é (min, max, sum).
------------------------------------------------------------------------------*/
T somaMinMax(int v[], int n1, int n2);

/*------------------------------------------------------------------------------
 Função:  computa todas as possíveis tuplas (min, max, sum) para cada intervalo
 e constrói a matriz.
 Entrada: ponteiro para a matriz, ponteiro para o vetor e seu tamanho (N).
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void processaMatriz(Matrix *matriz, int v[], int tam);

/*------------------------------------------------------------------------------
 Função:  adiciona 1 a cada elemento contido no intervalo [n1, n2].
 Entrada: ponteiro para a matriz, ponteiro para o vetor e o seu tamanho (N).
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void addMatriz(Matrix *matriz, int v[], int tam, int n1, int n2);

/*------------------------------------------------------------------------------
 Função:  subtrai 1 de cada elemento presente no intervalo [n1, n2].
 Entrada: ponteiro para a matriz, ponteiro para o vetor e o seu tamanho (N).
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void subMatriz(Matrix *matriz, int v[], int tam, int n1, int n2);

/*------------------------------------------------------------------------------
 Função:  libera a memória alocada pela matriz.
 Entrada: ponteiro para a estrutura Matrix, contendo a matriz a ser desalocada.
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void freeMatrix(Matrix *matrix) ;

#endif


