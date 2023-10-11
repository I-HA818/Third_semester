#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 100
string input;
string pattern;
int transition[SIZE][SIZE];
int num_alphabets,m;
char alphabets[SIZE];


int min(int a,int b){
	
	if(a<b) return a;
	else return b;
}
void CTF(){
	int k;	
	for(int q=0;q<=m;q++){
		for(int i=0;i<num_alphabets;i++){
			k=1+min(m,q+1);
			while(1){
			k=k-1;
			string prefx=pattern.substr(0,k);
			string suffx=pattern.substr(0,q);
			suffx+=alphabets[i];
			string check=suffx.substr(suffx.size()-k);
			if(prefx==check){
			break;
			}
			}
			transition[q][alphabets[i]-'a']=k;
		}
	}

}

void FAM(){

	int n=input.size();
	int q=0,i,m,s,count=0;
	m=pattern.size();
	for(i=0;i<n;i++){
		q=transition[q][input[i]-'a'];
	if(q==m){
		s=i-m+1;
	cout <<"Pattern occurs with shift " << endl;
	count++;
	}
	}
	cout << "Total matched substr: " <<count <<endl;
	}

int main(){

	cout <<"Input the pattern: " <<endl;
	cin  >> pattern;
	m=pattern.length();
	cout <<"Enter the number of alphabets: " <<endl;
	cin  >> num_alphabets;
	cout <<"Enter the alphabets: "<<endl;
	for(int i=0;i<num_alphabets;i++)
	cin  >> alphabets[i];
	
	cout << "Input the string to be tested: "<<endl;
	cin  >> input;
	
	CTF();
	for(int i=0;i<=m;i++){
		for(int j=0;j<num_alphabets;j++){
			cout << transition[i][j] <<" ";
			}
			cout << endl;

		FAM();
}
}

