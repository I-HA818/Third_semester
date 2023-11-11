#include <iostream>
#define max 100
using namespace std;
double x[max],fx[max];
int row,collum,COLLUM,ROW;
float matA[max][max],matB[max][max],TmatA[max][max],mat1[max][max],
mat2[max][max],mat3[max][max];

void readInput(){
	
    freopen("lss.txt","r",stdin);
	
    cin>>row;

    for(int i=0;i<row;i++)
        cin>>x[i];
     for(int i=0;i<row;i++)
        cin>>fx[i];

        cout<<"Enter the number of collums: ";
        cin >> collum;
}

void multiply1(){
    for(int i=0;i<collum;i++)
        for(int j=0;j<collum;j++)
        for(int k=0;k<row;k++)
            mat1[i][j]+=(TmatA[i][k]*matA[k][j]);
}

void multiply2(){
    for(int i=0;i<collum;i++)
        for(int j=0;j<row;j++)
        for(int k=0;k<row;k++)
        mat2[i][j]+=(TmatA[i][k]*matB[k][j]);
}

void solve(){
    ROW=collum;
    COLLUM=collum+1;

    for(int i=0;i<ROW;i++)
    for(int j=0;j<COLLUM;j++){
        if(j<collum) mat3[i][j]=mat1[i][j];
        else mat3[i][j]=mat2[i][j-collum];
    }

    for(int i=0;i<ROW;i++)
	    for(int j=0;j<COLLUM;j++){
	    	if(j<collum)
	    		mat3[i][j]=mat1[i][j];
	    	else
	    		mat3[i][j]=mat2[i][j-collum];

	    }

	for(int i=0;i<ROW;i++){
		double pivot=mat3[i][i];
		if(pivot ==0){
		    for(int j=i+1;j<ROW;j++)
			   if( mat3[j][i]!=0){
			   	double swap=mat3[j][i];
			   	 mat3[j][i]=mat3[i][i];
			   	 mat3[i][i]=swap;
			   	break;
			   }

		}
		pivot= mat3[i][i];
		for(int j=i+1;j<ROW;j++){
			if(mat3[j][i]!=0){
				double div=mat3[j][i]/pivot;

				for(int k=0;k<COLLUM;k++)
					mat3[j][k]+=(-div)*mat3[i][k];
			}
		}
	}

	for(int i=0;i<ROW;i++){
		double d=mat3[i][i];
		if(d!=1)
		   for(int j=0;j<COLLUM;j++)
			 mat3[i][j]/=d;


	}

	for(int i=ROW-1;i>=0;i--){
		double pivot=mat3[i][i];
		if(pivot ==0){
		    for(int j=i-1;j>=0;j--)
			   if(mat3[j][i]!=0){
			   	double swap=mat3[j][i];
			   	mat3[j][i]=mat3[i][i];
			   	mat3[i][i]=swap;
			   	break;
			   }

		}
		pivot=mat3[i][i];
		for(int j=i-1;j>=0;j--){
			if(mat3[j][i]!=0){
				double div=mat3[j][i]/pivot;
				for(int k=COLLUM-1;k>=0;k--)
					mat3[j][k]+=(-div)*mat3[i][k];
			}
		}
	}
	for(int i=0;i<collum;i++)
	 		cout << mat3[i][ROW]<<endl;

}
void lss(){
    for(int i=0;i<row;i++)
        matA[i][0]=1;
    for(int i=0;i<row;i++)
    for(int j=1;j<collum;j++){
        if(j==1) matA[i][j]=x[i];
        if(j==2) matA[i][j]=x[i]*x[i];
    }
    for(int i=0;i<row;i++)
        matB[i][0]=fx[i];

    for(int i=0;i<row;i++)
        for(int j=0;j<collum;j++)
        TmatA[j][i]=matA[i][j];

        multiply1();
        multiply2();
        solve();

}
int main()
{
    readInput();
    lss();
    return 0;
}
