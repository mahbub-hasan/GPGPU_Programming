#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void matrixInit(float **matrix, int M, int N,  int value) {
    for (int i = 0; i < M; ++i) {
        matrix[i] = (float **) malloc(sizeof(float *) * N);
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = value;
        }
    }
}

void matrixAdd(float **dA, float **dB, float **dC, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j <N; ++j) {
            dC[i][j] = dA[i][j] + dB[i][j];
        }
    }
}

int main(){

    int M = 1 << 12;
    int N = 1 << 16;
    clock_t t;

    float **A, **B, **C;

    A = (float **) malloc(sizeof(float *)*N*M);
    B = (float **) malloc(sizeof(float *)*N*M);
    C = (float **) malloc(sizeof(float *)*N*M);

    t = clock();

    matrixInit(A,M, N,1);
    matrixInit(B, M,N, 2);
    matrixInit(C, M,N, 0);

    matrixAdd(A, B, C, M, N);

    t = clock() - t;

    printf("Program executed at %f seconds", ((double)t)/CLOCKS_PER_SEC);

    return 0;
}