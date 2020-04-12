#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define size 80
void multiply(int fac[],int i);
void show(int fac[]);
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int fac[size]={0};
    fac[size-1]=1;
    int i;
    for (i=2;i<=n ;i++ )
    {
        multiply(fac,i);
    }
     show(fac);

}
void show(int fac[])
{
    int i;
    for (i=0;i<size;i++)
    {
        printf("%d",fac[i]);
    }
}
void multiply(int fac[],int n)
{
    int i,j;
    int carry=0;
    int rem,temp;
    for (i=size-1;i>=0;i--)
    {
        temp=fac[i]*n+carry;
        carry=0;
        if(temp>9)
            {
            rem=temp%10;
            fac[i]=rem;
            carry=temp/10;
            }
        else
            fac[i]=temp;

    }
}
