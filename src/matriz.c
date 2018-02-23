/*
matriz.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// Aloca a matriz. Size é definido na struct pra poder percorrer
// a matriz de forma direta, sem a necessidade de parâmetros adicionais
void criaMatriz(Matrix *matrix, int size) {
    matrix->size = size;
    matrix->data = (T**) calloc(matrix->size, sizeof(T*));
 
    int i;
    for (i = 0; i < matrix->size; i++) {
        matrix->data[i] = (T*) calloc(matrix->size, sizeof(T));
    }
}

// Calcula o mínimo, máximo e a soma de  um intervalo
T somaMinMax(int v[], int n1, int n2){
	int i=0;
	T t;
	
	t.sum = 0;
	t.min = v[n1]; //inicializa o mínimo com o primeiro valor do intervalo
	t.max = v[n1]; 
	
	for(i=n1; i<=n2; i++){
		if(v[i]>t.max){
			t.max = v[i]; // máximo
		}else{
			if(v[i]<t.min){
				t.min = v[i]; // mínimo
			}
		}
		t.sum += v[i]; // soma
	}
	return t; //retorna a tupla
}

// Constrói a matriz com as tuplas (min, max, sum)
void processaMatriz(Matrix *matriz, int v[], int tam){
	int i=0, j=0;
	
	//percorre posições em que i<=j calculando as tuplas
	//correspondentes ao intervalo em questão
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			if(i <= j){
				matriz->data[i][j] = somaMinMax(v, i+1, j+1);
			}else{
				matriz->data[i][j] = matriz->data[j][i];
			}
		}
	}
}


// Adiciona +1 a cada elemento dentro do intervalo [n1, n2]
void addMatriz(Matrix *matriz, int v[], int tam, int n1, int n2){
	int i=0;

	for(i=n1; i<=n2; i++){
		v[i]++;
	}

	//processa a matriz novamente uma vez que os valores do vetor
	//sofreram alterações
	processaMatriz(matriz, v, tam);
}

// Subtrai 1 de cada elemento dentro do intervalo [n1, n2]
void subMatriz(Matrix *matriz, int v[], int tam, int n1, int n2){
	int i=0;

	for(i=n1; i<=n2; i++){
		v[i]--;
	}

	//processa a matriz novamente uma vez que os valores do vetor
	//sofreram alterações
	processaMatriz(matriz, v, tam);
}
 
// Libera a memória alocada para a matriz (Perceba a utilização de "size" aqui)
void freeMatrix(Matrix *matrix) {
    int i;
    for (i = 0; i < matrix->size; i++) {
        free(matrix->data[i]);
    }
 
    free(matrix->data);
}
