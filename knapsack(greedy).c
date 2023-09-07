#include <stdio.h>
#include <stdlib.h>

struct item{
    int item,weight,price;
    float pricePweight;
}items[7],temp;

void readInput(){
    for(int i=0;i<7;i++){
    scanf("%d %d %d %f",&items[i].item,&items[i].weight,&items[i].price,&items[i].pricePweight);
    }

    for(int i=0;i<7;i++){
    printf("%d %d %d %f\n",items[i].item,items[i].weight,items[i].price,items[i].pricePweight);
    }

}
int main()
{
    int i,j,totalWeight,needed,arr[7];
    float totalPrice;
    freopen("input.txt","r",stdin);
    readInput();

    for( i=0;i<7;i++){
        for( j=0;j<7;j++){
            if(items[j].pricePweight<items[j+1].pricePweight){
                temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }
    printf("\nAfter sorting based on high price per weight to low price per weight:\n");
    printf("\n");
    for(int i=0;i<7;i++){
    printf("%d %d %d %f\n",items[i].item,items[i].weight,items[i].price,items[i].pricePweight);
    }

    totalWeight=0;
    totalPrice=0.00;



        for(i=0;i<7;i++){

                    needed=15-totalWeight;
           arr[i]=items[i].item;
           if(needed<=items[i].weight){
            totalWeight=totalWeight+needed;
            totalPrice=totalPrice+items[i].pricePweight*needed;
           }
           else{
            totalWeight=totalWeight+items[i].weight;
            totalPrice=totalPrice+items[i].price;
           }
             if(totalWeight>15) break;
        }

    printf("The items that are selected are: ");
    for(i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTotal weight is: %d",totalWeight);
    printf("\nTotal price is: %f",totalPrice);
    return 0;
}
