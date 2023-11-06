#include<stdio.h>
void maxprofit(int *prices,int *maxprices,int size);
int maxfromarray(int *arr,int n);
int max(int a , int b);
int main(){
    int length,num;
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
    printf("\n\nHow many Rod cutting: ");
    scanf("%d",&num);
    int profit=0,size[num],max;
    printf("Enter sizes:\n");
    for(int i=0;i<num;i++){
        scanf("%d",&size[i]);
    }
    max=maxfromarray(size,num);
    printf("max length = %d\n",max);
    maxprofit(prices,maxprice,max);
    for(int i=0;i<num;i++){
        profit+=maxprice[size[i]];
    }
    printf("Maximum Profit = %d \n",profit);
    return 0;
}
int max(int a , int b){
    if(a>b)return a;
    else return b;
}
void maxprofit(int *prices,int *maxprices,int size ){
    maxprices[0]=0;
    int i,j,profit;
    for(j=1;j<=size;j++){
        profit=-10;
    for(i=1;i<=j;i++){
       if(profit<prices[i]+maxprices[j-i]){
                profit=prices[i]+maxprices[j-i];
            }
        maxprices[j]=profit;
        }
    }
}
int maxfromarray(int *arr,int n){
    int i,max;
    max=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max)max=arr[i];
    }
    return max;
}