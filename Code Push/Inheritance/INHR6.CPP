//20 apr 2009
//session 3 : constructors & destructors in inheritence:

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class B
{
 public:
B()
{
cout<<"constructor in base class"<<endl;
}

};

class D:public B
{
public:
D()
{
cout<<"constructor in derived class"<<endl;
}
};

void main()
{
clrscr();
D obj;
getch();
}




