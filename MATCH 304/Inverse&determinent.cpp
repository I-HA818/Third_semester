#include <iostream>

using namespace std;
#define SIZE 100
double Mat[SIZE][SIZE];
double Mat2[SIZE][SIZE];
void determinent(int n){
    int i,j,k;
    double pivot,div,determinent;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            Mat2[i][j]=0;
        }
    }

    for( i=0;i<n;i++)
	   Mat2[i][i]=1;
	for( i=0;i<n;i++){
		 pivot=Mat[i][i];
		if(pivot ==0){
		    for( j=i+1;j<n;j++)
			   if(Mat[j][i]!=0){
			   	double swap=Mat[j][i];
			   	Mat[j][i]=Mat[i][i];
			   	Mat[i][i]=swap;
			   }

		}
		else{
          for( j=i+1;j<n;j++){
			if(Mat[j][i]!=0){
				 div=Mat[j][i]/pivot;

				for(k=0;k<n;k++){
				   Mat[j][k]+=(-div)*Mat[i][k];
				   Mat2[j][k]+=(-div)*Mat2[i][k];
				}
			}
		  }
		}


	}
    for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++)
	     cout << Mat[i][j]<<" ";
	   cout << endl;
	}
    determinent=1;
    for(i=0;i<n;i++)
            determinent*=Mat[i][i];


     cout << "Deterinent is " << determinent << endl;
}

void inverse(int n){
    for(int i=0;i<n;i++){
        double pivot=Mat[i][i];
        if(pivot!=1)
        for(int j=0;j<n;j++){
            Mat[i][j]/pivot;
            Mat2[i][j]/pivot;
        }
    }

    for(int i=n-1;i>=0;i--){
        double pivot=Mat[i][i];
        if(pivot==0){
                for(int j=i-1;j>=0;j--){
                 if(Mat[j][i]!=0){
                double swap=Mat[j][i];
                Mat[j][i]=Mat[i][i];
                Mat[i][i]=swap;
            }
        }
        }

        else{
            for(int j=i-1;j>=0;j--){
                if(Mat[j][i]!=0){
                    double div=Mat[j][i]/pivot;
                    for(int k=0;k<n;k++){
                        Mat[j][k]+=(-div)*Mat[i][k];
                        Mat2[j][k]+=(-div)*Mat2[i][k];
                    }
                }
            }
        }
    }
        cout <<"inverse matrix " <<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << Mat2[i][j] << " ";
            cout << endl;
        }
}
int main()
{
    int i,j,n;
    cout << "Enter the size of your matrix: "<< endl;
    cin >> n ;

    cout << "enter the elements one by one " << endl;
    for(i=0;i<n;i++){
            cout << "For row "<< i+1 << endl;
        for(j=0;j<n;j++){
            cout << "Collum " << j+1 <<endl;
            cin >> Mat[i][j] ;
        }
    }

    determinent(n);
    inverse(n);

    return 0;
}

