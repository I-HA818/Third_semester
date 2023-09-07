#include <stdio.h>
#include <stdlib.h>

int n=4;;
int p[5]={0,12,10,20,15};
int wt[5]={0,2,1,3,2};
int W=5;
int K[5][5];

int max(int a , int b){
if(a>b) return a;
else return b;
}
int knapsack(){

for(int i=0;i<=n;i++){
    for(int w=0;w<=W;w++){
        if(i==0 || w==0) {
                K[i][w]=0;
        }
        else if(wt[i]<=w) {
                K[i][w]=max(p[i]+K[i-1][w-wt[i]],K[i-1][w]);
        }
        else {
                K[i][w]=K[i-1][w];
        }

        printf("%d ",K[i][w]);
    }
    printf("\n");
}
    return K[n][W];
}
void print(int max,int i,int w){

    if(i==0 || w==0) return;
    if(max==K[i-1][w]) print(max,i-1,w);
    else{
        print(max-p[i],i-1,w-wt[i]);
        printf("%d ",i);
    }

}

int main()
{
    int ans=knapsack();
    printf("Total profit is: %d\n",ans);
    print(K[n][W],n,W);


    return 0;
}
