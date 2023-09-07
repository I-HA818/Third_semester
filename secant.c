#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define F(x)(x*x*x+4*x*x-10)

int main(){
    int n,i;
    n=100;
   // printf("%lf",EPS);
    double x0=1.5,x1=2,c,x2;
    //if(F(first)*F(last)>0) exit(0);
    printf(" Iter     x0            x1                x2              F(x0)          F(x1)        F(x2)\n");
    printf("--------------------------------------------\n");

    for(i=1;i<n;i++){
        x2=x1-F(x1)*(x1-x0)/(F(x1)-F(x0));
        printf("%d    %lf        %lf        %lf     %lf     %lf    %lf\n",i,x0,x1,x2,F(x0),F(x1),F(x2));
        if(fabs(F(x2))<EPS){
            printf("Root=%lf\n",x2);
            exit(0);
        }
        //if(F(first)*F(c)>0) first=c;
        else {
            x0=x1;
            x1=x2;
        };
    }
 return 0;
}