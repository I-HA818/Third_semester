#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char A[100],B[100],C[100];

int max(int a,int b){
        if(a>b) return a;
        else return b;
    }

void print(char C[]){
        for(int k=0;k<strlen(C);k++){
       printf("%c",C[k]);
    }
    }
int LCS(int i,int j,int k){

        if(A[i]=='\0' || B[j]=='\0') return 0;

         if(A[i]==B[j]) {
            C[k]=A[i];
                return 1+LCS(i+1,j+1,k+1);
        }

        else {
            int len1 = LCS(i, j + 1, k);
        int len2 = LCS(i + 1, j, k);
        return max(len1, len2);
        };

    }
int main()
{

    printf("Enter the first string: ");
    scanf("%s",A);
    printf("Enter the second string: ");
    scanf("%s",B);


   int res= LCS(0,0,0);
   printf("String length of LCS is %d \n",res);
   printf("The LCS is: ");
    print(C);
    return 0;
}
