#include<stdio.h>
#include<math.h>
#define F(x)(x*x+1)
int main(){
    float a,b,n,h,i;
    float x,xn,y,yn,Sum_X,Sum_I,I;
    scanf("%f %f %f",&a,&b,&n);
    h=(b-a)/n;
    //printf("%f",h);
    
        Sum_X=F(a)+F(b);
        Sum_I=0;
        x=a;
    for(i=1;i<n;i++){
        x=x+h;
        y=F(x);
        Sum_I=Sum_I+y;;
    }
    
    

    I=h*(Sum_X+2*Sum_I)/2;

    printf("%f",I);

    return 0;
}