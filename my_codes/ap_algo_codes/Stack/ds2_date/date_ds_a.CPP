#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int max_day(int);
class date_ds;
int count_to_last(date_ds d);
int fun1();
void fun2();
void fun3();
int check_leap(int);
class date_ds
{
public:
	int dd,mm,yy;
	void get_date(int dd,int mm,int yy )
	{
	this->dd=dd;
	this->mm=mm;
	this->yy=yy;
	}
	void get_date()
	{
		cout<<"enter your date "<<endl;
	    scanf("%d/%d/%d",&dd,&mm,&yy);
	}
	void show_date(){
		cout<<"you have entered\n";
		cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
	}

}d1,d2;
void main()
{
int choice,i;
tryagain:
clrscr();
printf("Enter your choice\n1-Days between two Dates\n2-Day corresponding to given Date\n3-Date after certain no. of Days\n");
scanf("%d",&choice);
clrscr();
switch(choice)
{
case 1:
d1.get_date();
d2.get_date();
int td=fun1();
printf("\nthe total no. of days=%d",td);
break;
case 2:
fun2();
break;
case 3:
fun3();
break;
default:
printf("You have entered a wrong input\nPlease try again\n");
goto tryagain;
}
getch();
}
int max_day(int month)
{
	   int days;
    switch(month)
   {
    case 1:case 3:case 5: case 7: case 8: case 10: case 12:
    days=31;
    break;
    case 4:case 6: case 9: case 11:
    days=31;
    break;
    case 2:
    if(check_leap(month))
    days=29;
    else
    days=28;
    break;
    }
    return days;
}
int fun1()
{
int lcount=0,ycount=0;
for(int i=d1.yy;i<d2.yy;i++)
{
if(check_leap(i))
lcount++;
else
ycount++;

}
int total_days=0;
if(lcount==0&&ycount==0)
{
int x=count_to_last(d1);
int y=count_to_last(d2);
total_days=y-x;
}
else
{
int y=count_to_last(d2);
int x=count_to_last(d1);
 total_days=lcount*366+ycount*365+abs(y-x);
}
total_days=abs(total_days);

return total_days;
}
int  check_leap(int y)
{
if(y%400==0||(y%4==0&&y%100==0))
return 1;
else
return 0;
}

int count_to_last(date_ds d)
{
	int count_days=0;
	int max=max_day(d.mm);
	count_days+=max-d.dd;
  for(int i=d.mm+1;i<=12;i++)
   {
       switch(i)
   {
    case 1:case 3:case 5: case 7: case 8: case 10: case 12:
    count_days+=31;
    break;
    case 4:case 6: case 9: case 11:
    count_days+=30;
    break;
    case 2:
    if(check_leap(d.yy))
    count_days+=29;
    else
    count_days+=28;
    break;
    }
    }
   return count_days;
}
void fun2(){
d1.get_date(1,1,1984);
d2.get_date();
int total_days=fun1();
cout<<"total days="<<total_days<<endl;
int day=total_days%7;
switch(day){
 case 0:
 cout<<"SUNDAY";
 break;
 case 1:
 cout<<"MONDAY";
 break;
 case 2:
 cout<<"TUESDAY";
 break;
 case 3:
 cout<<"WEDNESDAY";
 break;
 case 4:
 cout<<"THURSDAY";
break;
 case 5:
 cout<<"FRIDAY";
 break;
 case 6:
 cout<<"SATURDAY";
 break;
}
}
void fun3(){
cout<<"Given Date\n";
d1.get_date();
d2=d1;
cout<<"enter no. of days\n";
int days;
cin>>days;
int temp_day=days;
for(int i=d1.yy;i<=2050;i++)
{
   for(int j=d1.mm;j<=12;j++)
   {
     for(int k=d1.dd;k<=max_day(j);k++)
     {
       days--;
       if(days==0)
	 {
	  d2.dd=k;
	  d2.mm=j;
	  d2.yy=i;
	  break;
	 }
     }

   }
}             clrscr();
d1.show_date();
cout<<"\n The Date corresponding to this date after "<<temp_day<<"is\n";
printf("%d/%d/%d",d2.dd,d2.mm,d2.yy);
}