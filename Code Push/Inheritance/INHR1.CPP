//inheritence sample problem

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class Cpolygon
{
protected:
int l,w;
public:

void set_values(int a, int b)
{
l=a;
w=b;
}
};

class Crect:public Cpolygon
{

public:
int area()
{
return(l*w);
}

};

class Ctrgl:public Cpolygon
{

public:

int area()
{
return (l*w)/2;
}
};

void main()
{
clrscr();
Crect r1;
Ctrgl t1;

r1.set_values(4,5);
t1.set_values(4,6);

cout<<"area 1 is:"<<r1.area()<<endl;
cout<<"area 2 is :"<<t1.area()<<endl;
getch();
}
