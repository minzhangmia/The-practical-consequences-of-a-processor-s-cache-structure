#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1E8

double *A, *B, *C,*D;//use to malloc

void malloc_memery()
{
	A = malloc( SIZE*sizeof(double) );
	B = malloc( SIZE*sizeof(double) );
	C = malloc( SIZE*sizeof(double) );
	D = malloc( SIZE*sizeof(double) );

	memset(A,1.2,SIZE);
	memset(B,1.2,SIZE);
	memset(C,1.2,SIZE);
	memset(D,1.2,SIZE);
}

void free_memery()
{
	free(A);
	free(B);
	free(C);
	free(D);
}

double walltime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double wtime = (double) (t.tv_sec + t.tv_usec*1e-6);
    return wtime;
}

void main_caculate(FILE * fp)
{
	int N;	
	for (N = 10;N <= SIZE;N = (int)(N*1.05)) //  10 to 1E8
	{	
		double start = walltime();
		int count = SIZE/N;
		int j;
		for (j = 0; j < count; j++)
		{
			int k;
			for (k = 0; k < N; k++)
			A[k] = B[k] + C[k] * D[k];
		}
		double end = walltime();
		double interval = (end - start)/count;
		double GFLOATS = (2*N)/interval/1e9;
		fprintf(fp, "%d  %lf\n", N, GFLOATS);
	}
}


void caculation()
{
	FILE* fp = fopen("result.txt", "w");
	malloc_memery();
	main_caculate(fp);
	free_memery();
	fclose(fp);
	printf("completely.\n");
}

int main() {
	caculation();
	return 0;
}
