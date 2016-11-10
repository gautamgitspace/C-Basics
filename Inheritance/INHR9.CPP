/* sequence of execution of constructors
in multiple inheritence*/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class B1
{
 public:
  B1()
  {
  cout<<" no arg const in b1"<<endl;
  }
  };

class B2
{
public:
B2()
{
cout<<endl<<"no arg const in b2"<<endl;
}
};

class D:public B1,public B2
{
public:
D()
{
cout<<endl<<"no arg const in D"<<endl;


}
};

void main()
{
clrscr();

D obj;
getch();

}