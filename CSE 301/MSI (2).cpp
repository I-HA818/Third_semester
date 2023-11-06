#include<bits/stdc++.h>
using namespace std;
void msi(int *set,int*sum,int *prev,int n);
void print(int *prev,int *set,int i);
int main(){
	int set[]={0,9,-3,1,7,-15,2,3,-4,2,-7,6,-2,8,4,-9};
	int size = sizeof(set)/sizeof(set[0]);
	int sum[size],prev[size];
	cout<<"Maximum Sum interval : "<<endl;
	msi(set,sum,prev,size);
	print(prev,set,size-1);
}
void msi(int *set,int*sum,int *prev,int n){
	int i;
	sum[0]=0;
	prev[0]=0;
	for(i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+set[i];
		prev[i]=i-1;
		if(set[i]>sum[i])
		{
			sum[i]=set[i];
			prev[i]=0;
		}
	}
}
void print(int *prev,int *set,int i){
	if(prev[i]>0){
	print(prev,set,prev[i]);
	cout<<set[i]<<" ";
	}
}
