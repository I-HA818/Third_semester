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
    profit=maxprofit(prices,maxprice,4);
    printf("Maximum Profit for Cut size %d : %d\n",size,profit);
    return 0;
}
int max(int a , int b){
    if(a>b)return a;
    else return b;
}
int maxprofit(int *prices,int *maxprices,int size ){
    maxprices[0]=0;
    int profit;
   if(maxprices[size]>=0)return maxprices[size];
   if(size==0){
    profit=0;
   }
   else{
    profit=-10;
    for(int i=1;i<=size;i++){
        profit=max(profit,prices[i]+maxprofit(prices,maxprices,size-i));
    }
   }
   maxprices[size]=profit;
   return profit;
}
