#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<alloc.h>
void main()
{
clrscr();
textcolor(RED);
textbackground(WHITE);
clrscr();
int n;
printf("    Enter the no. of elements in array\n");
printf("   ");
scanf("%d",&n);
int *p=(int*) malloc(n*sizeof(int));
//taking input from the array
printf("    Enter the value of elements of array\n");
for(int i=0;i<n;i++)   {printf("    ");
scanf("%d",(p+i));                   }
clrscr();
// printing the elements of array
 printf("   Elements of array are\n");
 for (i=0;i<n;i++)
 printf("    %d\n",*(p+i));
 //finding the first and second larget element of array
 int sl,max=*p;
 for(i=0;i<n;i++)
 {
   if(*(p+i)>max)
   max=*(p+i);
}
sl=*p;
printf("   First largest element in array is %d",max);
for(i=0;i<n;i++)
 {
   if(sl<*(p+i)&&*(p+i)!=max)
   sl=*(p+i);

}
printf("\n   Second largest element in array is %d",sl);
int tl=*p;
for(i=0;i<n;i++)
 {
   if(tl<*(p+i)&&*(p+i)!=max&&*(p+i)!=sl)
   tl=*(p+i);

}


getch();
free(p);
}