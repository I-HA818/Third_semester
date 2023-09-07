#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define UP 1
#define SIDE 2
#define DIAG 3
#define NO_EDIT 4

 int arrow[100][100];
int ED[100][100];
int m,n;
int min(int a,int b,int c){

    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    if(c<=a && c<=b) return c;
}
void printED(char first[],char second[],int i,int j){

    if(arrow[i][j]==NO_EDIT){
        printED(first,second,i-1,j-1);
    }
    else if(arrow[i][j]==DIAG){
        printED(first,second,i-1,j-1);
         printf("Replace %c with %c\n",first[i],second[j]);
    }
    else if(arrow[i][j]==UP){
        printED(first,second,i-1,j);
        printf("Delete %c from first string.\n", first[i] );
    }
    else if(arrow[i][j]==SIDE){
        printED(first,second,i,j-1);
         printf("Insert %c at positon %d\n",second[j],(i+1));
    }
    return;
}

void printTable(){
for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        printf("%d ",ED[i][j]);
    }
    printf("\n");
   }
    printf("\n\n\n");
}
int main()
{
    char s1[100],s2[100];
    int i,j;

   printf("Enter the first string: ");
   scanf("%s",s1);
   printf("Enter the second string: ");
   scanf("%s",s2);

   m=strlen(s1);
   n=strlen(s2);

    char one[m+1],two[n+1];

   for(int i=0;i<=m;i++){
    one[i+1]=s1[i];
   }
   for(int j=0;j<=n;j++){
    two[j+1]=s2[j];
   }
   for(int i=0; i<=m; i++)ED[i][0] = i;
    for(int i=0; i<=n; i++)ED[0][i] = i;

   printTable();

   for(i=1;i<=m;i++){
    for(j=1;j<=n;j++){
        if(one[i]==two[j]){
            ED[i][j]=ED[i-1][j-1];
            arrow[i][j]=NO_EDIT;
        }
        else{
            ED[i][j]=min(ED[i-1][j-1],ED[i-1][j],ED[i][j-1])+1;
            if(ED[i][j]-1==ED[i-1][j-1]){
                arrow[i][j]=DIAG;
            }
            else if(ED[i][j]-1==ED[i-1][j]){
                arrow[i][j]=UP;
            }
            else arrow[i][j]=SIDE;
        }
    }
   }

   printTable();
   printf("%d\n",ED[i][j]);
   printED(one,two,m,n);

    return 0;
}
