#include<stdio.h>
void maxprofit(int *prices,int *maxprices,int *cut,int size);
int max(int a , int b);
int main(){
    int length,size;
    printf("Enter the length of the Rod: ");
    scanf("%d",&length);
    int prices[length+1],maxprice[length+1],cut[length+1];
    prices[0]=0;
    cut[0]=0;
    printf("Enter the price of each size cut:\n ");
    for(int i=1;i<=length;i++)
    {
        printf("Price for cut %d :",i);
        scanf("%d",&prices[i]);
    }
    printf("\n\nEnter the desired size: ");
    scanf("%d",&size);
    int profit;
    maxprofit(prices,maxprice,cut,size);
    printf("Maximum Profit for  size %d : %d and cut size is :%d\n",size,maxprice[size],cut[size]);
	printf("Cut :\n");
	int n;
	n=size;
	while(n>0){
	printf("%d ",cut[n]);
	n=n-cut[n];	
	}
    return 0;
}
int max(int a , int b){
    if(a>b)return a;
    else return b;
}
void maxprofit(int *prices,int *maxprices,int *cut,int size ){
    maxprices[0]=0;
    int i,j,profit;
    for(j=1;j<=size;j++){
        profit=-10;
        for(i=1;i<=j;i++){
            if(profit<prices[i]+maxprices[j-i]){
                profit=prices[i]+maxprices[j-i];
                cut[j]=i;
            }
        }
        maxprices[j]=profit;
    }
    return;
}
