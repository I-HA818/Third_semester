#include <iostream>
using namespace std;
#define SIZE 100
double A[SIZE][SIZE];
double L[SIZE][SIZE];
double U[SIZE][SIZE];
double result[SIZE][SIZE];

void multi(int n){
	
for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
	 for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += L[i][k] * U[k][j];
            }
        }
    }

}
void LUelimination(int n){
    int i,j,k;
    double pivot,div,determinent;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
	if(i==j) L[i][j]=1;
	else L[i][j]=0;
        }
    }

	 for(i=0;i<n;i++){
        for(j=0;j<n;j++){
	U[i][j]=A[i][j];
        }
    }

    
	for( i=0;i<n;i++){
		 pivot=U[i][i];
		if(pivot ==0){
		    for( j=i+1;j<n;j++)
			   if(U[j][i]!=0){
			   	double swap=U[j][i];
			   	U[j][i]=U[i][i];
			   	U[i][i]=swap;
			   }

		}
		else{
        	  for( j=i+1;j<n;j++){
			if(U[j][i]!=0){
				 div=U[j][i]/pivot;

				for(k=0;k<n;k++){
				  U[j][k]+=(-div)*U[i][k];
				 
				}
			L[j][i]=div;
			
		  }
		}

	}

	}
    cout << " upper triangle matrix of U :"<< endl;
     for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout <<U[i][j] << " ";
            cout << endl;
        }
	
	cout << "lower triangle matrix of L :"<< endl;
     for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout <<L[i][j] << " ";
            cout << endl;
        }

    determinent=1;
    for(i=0;i<n;i++)
            determinent*=A[i][i];

     cout << "Determinent is " << determinent << endl;
	
	multi(n);

	cout<< "L * U :" << endl;
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<< result[i][j] << " " ;
}
	cout <<endl;
	}
	cout<< "A :" << endl;
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<< A[i][j] << " " ;
		}
	cout <<endl;
	}
	}


int main()
{
    int i,j,n;
    cout << "Enter the size of yourArix: "<< endl;
    cin >> n ;

    cout << "enter the elements one by one " << endl;
    for(i=0;i<n;i++){
            cout << "For row "<< i+1 << endl;
        for(j=0;j<n;j++){
            cout << "Collum " << j+1 <<endl;
            cin >>A[i][j] ;
        }
    }
	LUelimination(n);
	return 0;
}



