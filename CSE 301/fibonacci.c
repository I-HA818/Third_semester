#include<stdio.h>

long int fibNo[100];

long int fib(int n)
{
    if(n<=1) return n;
    long int a;
    if(fibNo[n] > 0)
    return fibNo[n];

    else
    {
        a= fib(n-1) + fib(n-2);
        fibNo[n]= a;
    }

    return a;
}

int main()
{
    int a;
    double b;
    printf("Enter n: ");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
    printf(" %lld ", fib(i));
    }
    return 0;
}
