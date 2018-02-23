/*
mainA.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(int argc, const char * argv[]) {
	int N=0, M=0;
	int i=0, n1=0, n2=0;
	char op[4];

	FILE *fpr, *fpw;

	if(argc == 3){
		fpr = fopen(argv[1], "r");
		
		if(fscanf(fpr, "%d %d", &N, &M)!=2){
			printf("Erro de leitura 1 \n");
		}
		
		//vetor base e o vetor que servirá como árvore
		int *v = (int *) malloc(sizeof(int)*(N+1));
		T *arvore = (T *) malloc(sizeof(T)*(4*N+1));
		
		//lê os números do vetor
		for(i=1; i<=N; i++){
			if(fscanf(fpr, "%d", &v[i])!=1){
				printf("Erro de leitura 2 \n");
			}
		}

		constroiArvore(arvore, v, 1, 1, N);

		fpw = fopen(argv[2], "w");

		for(i=0; i<M; i++){
			if(fscanf(fpr, "%s %d %d", op, &n1, &n2)<=0){
				printf("Erro de leitura 3\n");
			}

			if(strcmp(op, "Add")==0){
				add(arvore, 1, 1, N, n1, n2);
			}else{
				if(strcmp(op, "Sub")==0){
					sub(arvore, 1, 1, N, n1, n2);
				}else{
					if(strcmp(op, "Min")==0){
						fprintf(fpw, "%d\n", consultaMin(arvore, 1, 1, N, n1, n2));
					}else{
						if(strcmp(op, "Max")==0){
							fprintf(fpw, "%d\n", consultaMax(arvore, 1, 1, N, n1, n2));
						}else{
							if(strcmp(op, "Sum")==0){
								fprintf(fpw, "%d\n", consultaSum(arvore, 1, 1, N, n1, n2));
							}
						}
					}
				}
			}
		}

		fclose(fpw);
		fclose(fpr);
		
		free(v);
		free(arvore);
		
	}else{
		printf("Erro de entrada\n");
	}
	return 0;
}
