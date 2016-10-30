//MULTIPLE INHERITENCE
//2 base classes and 1 derived


#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class  M
{
protected :
  int m;

public:
void get_m(int);
};

class N
{
protected:
int n;
public:
void get_n(int);
};

//derived class

class P:public M, public N //derived class public to both bases
{
public:
void disp();
};

//method implementations

void M ::get_m(int x)
  {
  m=x;
  }
void N::get_n(int x)
  {
  n=x;
  }

void P :: disp()
{
cout<<"m="<<m<<endl;
cout<<"n="<<n<<endl;
cout<<"pdt"<<m*n<<endl;
cout<<"sum"<<m+n<<endl;

}


void main()
{
clrscr();

P p; //object creation

p.get_m(8);
p.get_n(10);
p.disp();
getch();
}

