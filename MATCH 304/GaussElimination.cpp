#include <iostream>

using namespace std;
#define SIZE 100
double Mat[SIZE][SIZE];

void gauss(int n){
    int i,j,k;
    double pivot,div;
    for(i=0;i<n;i++){
        for(i=0;i<n;i++){
            pivot=Mat[i][i];
            if(pivot==0){
                for(j=i+1;j<n;j++){
                    if(Mat[j][i]!=0){
                        double swap=Mat[j][i];
                        Mat[j][i]=Mat[i][i];
                        Mat[i][i]=Mat[j][i];
                    }
                }
            }
            else {
                for(j=i+1;j<n;j++){
                        if(Mat[j][i]!=0){
                             div=Mat[j][i]/pivot;
                            for(k=0;k<=n;k++)
                            Mat[j][k]+=(-div)*Mat[i][k];
                        }
                }
            }
        }
    }


        for(i=n-1;i>0;i--){
            pivot=Mat[i][i];
            if(pivot==0){
                for(j=i-1;j>=0;j--){
                    if(Mat[j][i]!=0){
                        double swap=Mat[j][i];
                        Mat[j][i]=Mat[i][i];
                        Mat[i][i]=Mat[j][i];
                    }
                }
            }
            else {
                for(j=i-1;j>=0;j--){
                        if(Mat[j][i]!=0){
                             div=Mat[i][j]/pivot;
                            for(k=0;k<=n;k++)
                            Mat[j][k]-=div*Mat[i][k];

                        }
                }
            }
        }

    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            cout << Mat[i][j] << " ";
        }
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
            cout << "For collum "<< i+1 << endl;
        for(j=0;j<=n;j++){
            cout << "Co-eff " << j+1 <<endl;
            cin >> Mat[i][j] ;
        }
    }

    gauss(n);

    return 0;
}
