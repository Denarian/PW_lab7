#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void matrixFill(size_t n, size_t m, double M[n][m])
{
    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < m; j++)
            M[i][j] = rand();   
}
void matrixPrint(size_t n, size_t m, double M[n][m])
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%lf |", M[i][j]);
        printf("\n");
    }
}

void matrixMultiply(size_t n, size_t m,size_t p, double A[n][m], double B[m][p], double W[n][p])
{
    //  NxM MxP
	double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < p; j++)
        {
            for(size_t k = 0; k < m; k++)
                sum += A[i][k] * B[k][i];
            W[i][j] = sum;
            sum = 0;
        }
    }
    return;
}

int main()
{
    double A[30][30];
    double B[30][30];
    double C[60][100];
    double D[100][110];
    double E[500][600];
    double F[600][800];
    double W1[30][30], W2[60][110],W3[500][800];
    double start, end;

    matrixFill(30,30,A);
    matrixFill(30,30,B);
    matrixFill(60,100,C);
    matrixFill(100,110,D);
    matrixFill(500,600,E);
    matrixFill(600,800,F);

    start = omp_get_wtime();
    matrixMultiply(30,30,30,A,B,W1);
    end = omp_get_wtime();
    printf("result: 30x30 and 30x30: %lf\n",end - start);
    
    start = omp_get_wtime();
    matrixMultiply(60,100,110,C,D,W2);
    end = omp_get_wtime();
    printf("result: 60x100 and 100x110: %lf\n",end - start);

    start = omp_get_wtime();
    matrixMultiply(500,600,800,E,F,W3);
    end = omp_get_wtime();
    printf("result: 500x600 and 600x800: %lf\n",end - start);


    return 0;
}