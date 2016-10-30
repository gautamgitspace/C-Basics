/* syntax to call parameterized const of base */

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class B
{
public:

B()
{
cout<<"default constructor in base class"<<endl;
}

B(int a)
{
cout<<"one argument constructor in base class"<<endl;
cout<<endl<<a<<endl;
}

};

class D:public B
{
public:
D() //default
{
cout<<endl<<"default in derived"<<endl;
}

D(int a) : B (a)// syntax for parametrized const of base
{

cout<<endl<<"one argument constructor in the derived class"<<endl;;
cout<<endl<<a<<endl;
}
};

void main()
{
clrscr();
D obj(1);

/* sequence of execution:
default constructor of base & then
paramaterized constructor of the derived*/

getch();

}

/*
if we call the parameterized constructor of the derived class it will
not call the parameterized constructor of the base  instead it will call its
default no arg constructor & then the parametrerized constructor of the
 derived */



