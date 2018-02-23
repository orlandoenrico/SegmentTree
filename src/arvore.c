/*
arvore.c
Autor: Orlando Enrico Liz Silvério Silva
Data: 27/08/17
*/

#include "arvore.h"

// Devolve índice correspondente aos filhos da esquerda de um nó
int esquerda(int i){
	return 2*i;
}

// Devolve índice correspondente aos filhos da direita de um nó
int direita(int i){
	return 2*i + 1;
}

// Devolve índice correspondente ao meio do vetor
int meio(int l, int r){
	return (l+r)/2;
}

// Constrói a Árvore de Segmentação com seus 2n-1 nós, calculando a tupla
// correspondente apenas uma vez.
// A construção começa pelos nós folha e vai subindo na árvore.
void constroiArvore(T arvore[], int v[], int index, int l, int r){
	// se o intervalo de interesse [l,r] com l=r chegamos em um nó folha
	if (l == r){ 
		// faz o nó folha receber a tupla correspondente do vetor v
		arvore[index].min = v[l];
		arvore[index].max = v[l];
		arvore[index].sum = v[l]; 
	}else{ 
		constroiArvore(arvore, v, esquerda(index), l, meio(l, r));
		constroiArvore(arvore, v, direita(index), meio(l, r) + 1, r);
		// o min e o max de um nó interno será o min e max dos seus filhos da esquerda e direita
		arvore[index].min = min(arvore[esquerda(index)].min, arvore[direita(index)].min);
		arvore[index].max = max(arvore[esquerda(index)].max, arvore[direita(index)].max);
		// a soma de um nó interno será a soma dos filhos da esquerda e direita
		arvore[index].sum = arvore[esquerda(index)].sum + arvore[direita(index)].sum;
	}
}

// Adiciona 1 aos elementos no intervalo [L, R] e atualiza os nós anteriores até a raiz
void add(T arvore[], int index, int l, int r, int L, int R){		
	// se o intervalo de interesse [L, R] está fora do intervalo analisado no momento [l, r]
	if ((l > r) || (l > R) || (r < L))
		return;
	// se chegou em um nó folha soma 1
	if (l == r){
		arvore[index].min += 1;
		arvore[index].max += 1;
		arvore[index].sum += 1;
	}else{ 
		add(arvore, esquerda(index), l, meio(l, r), L, R);
		add(arvore, direita(index), meio(l, r) + 1, r, L, R);
		// atualiza os min, max e sum dos nós internos a partir de seus filhos		
		arvore[index].min = min(arvore[esquerda(index)].min, arvore[direita(index)].min);
		arvore[index].max = max(arvore[esquerda(index)].max, arvore[direita(index)].max);
		arvore[index].sum = arvore[esquerda(index)].sum + arvore[direita(index)].sum;
	}
}

// Subtrai 1 dos elementos no intervalo [L, R] e atualiza os nós anteriores até a raiz
void sub(T arvore[], int index, int l, int r, int L, int R){		
	if ((l > r) || (l > R) || (r < L))
		return;
	// se chegou em um nó folha subtrai 1
	if (l == r){
		arvore[index].min -= 1;
		arvore[index].max -= 1;
		arvore[index].sum -= 1;
	}else{
		sub(arvore, esquerda(index), l, meio(l, r), L, R);
		sub(arvore, direita(index), meio(l, r) + 1, r, L, R);		
		arvore[index].min = min(arvore[esquerda(index)].min, arvore[direita(index)].min);
		arvore[index].max = max(arvore[esquerda(index)].max, arvore[direita(index)].max);
		arvore[index].sum = arvore[esquerda(index)].sum + arvore[direita(index)].sum;
	}
}

// Consulta a soma de um intervalo [l, r] na árvore 
int consultaSum(T arvore[], int index, int l, int r, int L, int R){
	// caso o intervalo de interesse [L, R] esteja fora do intervalo analisado no momento [l, r]
	if ((l > R) || (r < L))
		return 0;  //elemento neutro 

	// se o intervalo de interesse estiver presente na árvore retorna a soma desse nó
	if ((l >= L) && (r <= R))
		return arvore[index].sum; 	

	// se não consulta os nós filhos da esquerda e da direita que formem [l, r]
	int sL = consultaSum(arvore, esquerda(index), l, meio(l, r), L, R);
	int sR = consultaSum(arvore, direita(index), meio(l, r) + 1, r, L, R);

	return sL + sR;
}

// Consulta o mínimo de um intervalo [l, r] na árvore
int consultaMin(T arvore[], int index, int l, int r, int L, int R){
	if ((l > R) || (r < L))
		return 2147483647;  //elemento neutro

	// se o intervalo de interesse estiver presente na árvore retorna o mínimo desse nó
	if ((l >= L) && (r <= R))
		return arvore[index].min;	

	int minL = consultaMin(arvore, esquerda(index), l, meio(l, r), L, R);
	int minR = consultaMin(arvore, direita(index), meio(l, r) + 1, r, L, R);

	return min(minL, minR);
}

// Consulta o máximo de um intervalo [l, r] na árvore
int consultaMax(T arvore[], int index, int l, int r, int L, int R){
	if ((l > R) || (r < L))
		return -2147483648;  //elemento neutro

	// se o intervalo de interesse estiver presente na árvore retorna o máximo desse nó
	if ((l >= L) && (r <= R))
		return arvore[index].max;	

	int maxL = consultaMax(arvore, esquerda(index), l, meio(l, r), L, R);
	int maxR = consultaMax(arvore, direita(index), meio(l, r) + 1, r, L, R);

	return max(maxL, maxR);
}