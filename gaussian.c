#include <stdio.h>

#define N 3 // Define the size of the square matrix (N x N)

void gaussianElimination(double mat[N][N + 1]) {
    int i, j, k;
    
    for (i = 0; i < N; i++) {
        // Find the pivot row and swap if necessary
        int pivot_row = i;
        for (j = i + 1; j < N; j++) {
            if (mat[j][i] > mat[pivot_row][i])
                pivot_row = j;
        }
        if (pivot_row != i) {
            // Swap rows i and pivot_row
            for (j = 0; j <= N; j++) {
                double temp = mat[i][j];
                mat[i][j] = mat[pivot_row][j];
                mat[pivot_row][j] = temp;
            }
        }
        
        // Make the diagonal elements of this row equal to 1
        double pivot = mat[i][i];
        for (j = i; j <= N; j++) {
            mat[i][j] /= pivot;
        }
        
        // Eliminate all other rows
        for (k = 0; k < N; k++) {
            if (k != i) {
                double factor = mat[k][i];
                for (j = i; j <= N; j++) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }
}

int main() {
    double mat[N][N + 1] ;
      
    printf("Enter the co efficint matrix: ");
    for(int i=0;i<N;i++){
        for(int j=0;j<N+1;j++){
            scanf("%lf",&mat[i][j]);
        }
    }
    gaussianElimination(mat);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %lf\n", i + 1, mat[i][N]);
    }

    return 0;
}

