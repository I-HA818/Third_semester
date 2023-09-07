#include <stdio.h>
#include <stdlib.h>
#include<string.h>


char A[50],B[50],S[50][50];
int C[50][50];

int max(int a,int b){
        if(a>b) return a;
        else return b;
    }


void LCS(int a,int b){

int i,j;
    for( i=1;i<=a;i++)
        C[i][0]=0;
    for( j=1;j<=b;j++)
        C[0][j]=0;

    for( i=1;i<=a;i++){
        for( j=1;j<=b;j++){

         if(A[i-1]==B[j-1]) {
            C[i][j]=1+C[i-1][j-1];
            S[i][j]='/';
        }

        else if(C[i][j]>=C[i][j]){
            C[i][j]=C[i-1][j];
            S[i][j]='|';
        }
        else {
                C[i][j]=C[i][j-1];
                S[i][j]='-';
        }
      }
    }
        printf("%d\n",C[i-1][j-1]);
    }
    void print(int i, int j) {
    if (i == 0 || j == 0) return;
    if (S[i][j] == '/') {
        print(i - 1, j - 1);
        printf("%c", A[i - 1]);
    } else if (S[i][j] == '|') {
        print(i - 1, j);
    } else {
        print(i, j - 1);
    }
}
int main()
{

    printf("Enter the first string: ");
    scanf("%s",A);
    printf("Enter the second string: ");
    scanf("%s",B);
       int a=strlen(A);
       int b=strlen(B);

    LCS(a,b);
   print(a,b);
    return 0;
}
