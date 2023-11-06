#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define F(x)(x*x*x+4*x*x-10)

int main(){
    int n,i;
    n=100;
   // printf("%lf",EPS);
    double first=1.25,last=1.5,c;
    if(F(first)*F(last)>0) exit(0);
    printf(" Iter     a             b                c              F(a)          F(b)        F(c)\n");
    printf("--------------------------------------------\n");

    for(i=1;i<n;i++){
        c=(first*F(last)-last*F(first))/(F(last)-F(first));
        printf("%d    %lf        %lf        %lf     %lf     %lf    %lf\n",i,first,last,c,F(first),F(last),F(c));
        if(fabs(F(c))<EPS){
            printf("Root=%lf\n",c);
            exit(0);
        }
        if(F(first)*F(c)>0) first=c;
        else last=c;
    }
 return 0;
}