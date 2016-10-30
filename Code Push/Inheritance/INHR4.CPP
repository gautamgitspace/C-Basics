// WAP to solve ambuguity in multiple inheritence


#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class  M
{
protected :
int m;
public:
void get_m(int);
void display();//display func in M

};

class N
{
protected:
int n;
public:
void get_n(int);
void display();//display func in N

};

/*derived class P basically used to display the data members of M & N*/

class P:public M, public N //derived class public to both bases
{
public:
void disp();// disp of P
};

//method implementations

void M ::get_m(int x)//get of M defined outside using scope
  {
  m=x;
  }

void N::get_n(int x)//get of N  defined outside using scope
  {
  n=x;
  }

void M::display() //disp of M
{
cout<<"hello"<<endl;
}

void N::display() //disp of N
{
cout<<"bye"<<endl;
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

p.M::display();//use of scope to avoid ambuguity due to same func name display
p.N::display();
p.disp();

getch();

}

