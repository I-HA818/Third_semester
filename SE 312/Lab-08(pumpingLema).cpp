#include<iostream>
#include<cstring>
#include<random>
#include<algorithm>
using namespace std;
int n;
string language,input;

bool pump(string x, string y,string z){
	string string=x+y+z;
	int len=string.length();
	int count1=0,count0=0;
	for(int i=0;i<len;i++){
		if(string[i]==0) count0++;
	else if(string[i]==1) count1++;
	}
	if (count0==n && count1==n) return true; 
	
return false;
}
void divide(){
	string x,y,z;
	bool ans;
	int len=input.length();
	x=input[0];
	y=input[1];
	for(int i=2;i<len-2;i++)
		y+=input[i];
	z=input[len-1];
	ans=pump(x,y,z);
	if (ans==false){
	cout << "Not regular " << endl;	
	return;
	} 
	for(int k=1;k<5;k++){
	y+=y;
	ans=pump(x,y,z);
	if (ans==false)
	{

	cout << "Not regular " << endl;	
	break;
	}
	}
	
}
int main(){
	
	cout << "Enter your language: " <<endl;
	cin >> language;
	while(1){
	cout << "Enter value of n " << endl;;
	cin >> n;
	string zeros=string(n,'0');
	string ones=string(n,'1');
	input=zeros+ones;
	random_device rd;
	mt19937 gen(rd());
	//shuffle(input.begin(),input.end(),gen);
	cout << input << endl;
	
	divide();
}
	}
