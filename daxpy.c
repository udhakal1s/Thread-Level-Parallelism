#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000
#define NUM_THREADS 2

void daxpy(double *x, double *y, double a, int n) {
    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < n; i++) {
        y[i] = a * x[i] + y[i];
    }
}

int main() {
    double *x = (double *)malloc(sizeof(double) * N);
    double *y = (double *)malloc(sizeof(double) * N);
    double a = 2.5;

    for (int i = 0; i < N; i++) {
        x[i] = i * 1.0;
        y[i] = i * 2.0;
    }

    daxpy(x, y, a, N);

    printf("y[0] = %f\n", y[0]);
    printf("y[N-1] = %f\n", y[N-1]);

    free(x);
    free(y);
    return 0;
}

