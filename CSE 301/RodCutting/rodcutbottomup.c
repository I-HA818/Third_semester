#include<stdio.h>
int maxprofit(int *prices,int *maxprices,int size);
int max(int a , int b);
int main(){
    int length,size;
    printf("Enter the length of the Rod: ");
    scanf("%d",&length);
    int prices[length+1],maxprice[length+1];
    prices[0]=0;
    printf("Enter the price of each size cut:\n ");
    for(int i=1;i<=length;i++)
    {
        printf("Price for cut %d :",i);
        scanf("%d",&prices[i]);
    }
    printf("\n\nEnter the desired size: ");
    scanf("%d",&size);
    int profit;
    profit=maxprofit(prices,maxprice,size);
    printf("Maximum Profit for Cut size %d : %d\n",size,profit);
    return 0;
}
int max(int a , int b){
    if(a>b)return a;
    else return b;
}
int maxprofit(int *prices,int *maxprices,int size ){
    maxprices[0]=0;
    int i,j,profit;
    for(j=1;j<=size;j++){
        profit=-10;
        for(i=1;i<=j;i++){
            profit=max(profit,prices[i]+maxprices[j-i]);
        }
        maxprices[j]=profit;
    }
    return maxprices[size];
}