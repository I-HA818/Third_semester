
#include <stdio.h>

#define ROW1 3
#define COL1 3
#define ROW2 3
#define COL2 3

int main() {
  int matrix1[ROW1][COL1];
  int matrix2[ROW2][COL2];
     
    int result[ROW1][COL2];
    int i, j, k;
    
    printf("Enter element of first matrix: ");
    for(i=0;i<ROW1;i++){
        for(j=0;j<COL1;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
     printf("Enter element of second matrix: ");
    for(i=0;i<ROW2;i++){
        for(j=0;j<COL2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
   
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            result[i][j] = 0;
        }
    }

   
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            for (k = 0; k < COL1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Resultant Matrix:\n");
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

