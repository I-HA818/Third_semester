#include<stdio.h>
#include<math.h>
#define F(x)(x*x+1)
int main(){
    double n,a,b,h;
    double Sum_X,Sum_I,I;
    a=0.0;
    b=2.0;
    n=10.0;
    double x[]={0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
    double y[]={1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};
    h=(b-a)/n;
    //printf("%f",h);
    
        Sum_X=x[0]+x[10];
        Sum_I=0;
        
    for(int i=1;i<n;i++){
        x[i]=x[i]+h;
        Sum_I=Sum_I+y[i];
    }
    
    

    I=h*(Sum_X+2*Sum_I)/2;

    printf("%.1lf",I);

    return 0;
}