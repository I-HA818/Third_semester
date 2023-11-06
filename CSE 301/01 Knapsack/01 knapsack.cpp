#include<bits/stdc++.h>
using namespace std;
#define obj 4
#define W 5
void printknapSack(int arr[][W+1], int value[],int *weight,int maxval);
void printrec(int arr[][W+1], int value[],int *weight,int maxval,int i,int w);
void knapsack(int *weight,int *value,int arr[][W+1]);
int main(){
	int weight[obj+1],value[obj+1];
	freopen("knapinput.txt","r",stdin);
	for(int i=0;i<=obj;i++)cin>>weight[i];
	for(int i=0;i<=obj;i++)cin>>value[i];
	int arr[obj+1][W+1];
	knapsack(weight,value,arr);
	cout<<"Maxmimum profit is = "<<arr[obj][W]<<endl;
	cout<<"Selected Items are :"<<endl;
	printrec(arr,value,weight,arr[obj][W],obj,W);
	cout<<"\n------\n";

}
void knapsack(int *weight,int *value,int arr[][W+1]){
		int i,w;
		for(i=0;i<=obj;i++)arr[i][0]=0;
		for(i=0;i<=W;i++)arr[0][i]=0;
		for(i=1;i<=obj;i++){
			for(w=1;w<=W;w++){
				if(weight[i]>w)arr[i][w]=arr[i-1][w];
				else
				{
				if(value[i]+arr[i-1][w-weight[i]]>arr[i-1][w])arr[i][w]=value[i]+arr[i-1][w-weight[i]];
				else arr[i][w]=arr[i-1][w];
				}

			}
		}
}
void printknapSack(int arr[][W+1], int value[],int *weight,int maxval)
{
    int i,w,result;
    result=maxval;
    w=W;
    for (i=obj;i>0&&result>0;--i)
    {
        if(result==arr[i-1][w])continue;
        else
        {
            cout<<i<<" ";
            result=result-value[i];
            w=w-weight[i];
        }
    }
}
void printrec(int arr[][W+1], int value[],int *weight,int maxval,int i,int w){
	if(i==0 || w ==0)return;
	if(maxval==arr[i-1][w])printrec(arr,value,weight,maxval,i-1,w);
	else{
		printrec(arr,value,weight,maxval-value[i],i-1,w-weight[i]);
			cout<<i<<" ";
	}

}
