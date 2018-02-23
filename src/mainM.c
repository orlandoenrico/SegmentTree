/*
main.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main(int argc, const char * argv[]) {
	int N=0, M=0;
	int i=0, n1=0, n2=0;
	char op[4];
	
	//ponteiros para ler e escrever em arquivos de
	//entrada e saída 
	FILE *fpr, *fpw;

	if(argc == 3){
		fpr = fopen(argv[1], "r");
		
		if(fscanf(fpr, "%d %d", &N, &M)!=2){
			printf("Erro de leitura de N e/ou M\n");
		}
		
		//aborta o programa se N e M possuirem valores
		//fora dos limites especificados
		if((N<1 || N>1000000) || (M<1 || M>10000000))
			return 0;
		
		int *V = (int *) malloc((N+1)*sizeof(int));
		Matrix matrix;
    	criaMatriz(&matrix, N+1);

		//vetor começa da posição 1, não 0
		for(i=1; i<=N; i++){
			if(fscanf(fpr, "%d", &V[i])!=1){
				printf("Erro de leitura nos elementos do vetor\n");
			}
		}

		//processa a matriz com as tuplas correspondentes aos intervalos
		//possíveis
		processaMatriz(&matrix, V, N);


		fpw = fopen(argv[2], "w");

		for(i=0; i<M; i++){
			if(fscanf(fpr, "%s %d %d", op, &n1, &n2)<=0){
				printf("Erro de leitura nas operacoes\n");
			}
			//execução das operações
			if(strcmp(op, "Add")==0){
				addMatriz(&matrix, V, N, n1, n2);
			}else{
				if(strcmp(op, "Sub")==0){
					subMatriz(&matrix, V, N, n1, n2);
				}else{
					if(strcmp(op, "Min")==0){
						fprintf(fpw, "%d\n", matrix.data[n1-1][n2-1].min);
					}else{
						if(strcmp(op, "Max")==0){
							fprintf(fpw, "%d\n", matrix.data[n1-1][n2-1].max);
						}else{
							if(strcmp(op, "Sum")==0){
								fprintf(fpw, "%d\n", matrix.data[n1-1][n2-1].sum);
							}
						}
					}
				}
			}
		}
		fclose(fpw);
		fclose(fpr);

		freeMatrix(&matrix);
	}else{
		printf("Erro de entrada\n");
	}
	return 0;
}