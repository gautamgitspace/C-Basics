/* sequence of execution of constructors
in multiple inheritence*/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class B1
{
  public:
  B1() //no arg
  {
  cout<<" no arg const in b1"<<endl;
  }

  B1(int a)// 1 arg
  {
  cout<<endl<<"one arg const in B1"<<endl;
  cout<<a<<endl;
  }

  };

class B2
{
public:
B2()// no arg
{
cout<<endl<<"no arg const in b2"<<endl;
}

B2(int a) // 1 arg
{
cout<<"one arg const in B2"<<endl;
cout<<endl<<a<<endl;
}

};

class D:public B1,public B2
{
public:
D()
{
cout<<endl<<"no arg const in D"<<endl;
}

class D(int a) : B1(a),B2(a)
{
cout<<"one arg const in derived"<<endl;
cout<<a<<endl;
}
};

void main()
{
clrscr();

D obj(4);
getch();

}