//destructors in inheritence

#include<stdio.h>
#include<conio.h>
#include<iostream.h>


class B1
{
 public:
 B1()
 {
  cout<<endl<< " no arg const in base class B1"<<endl;
 }

 ~B1()
 {
 cout<<endl<<"destructor in base class B1";

// getch();//getch placed here as this is executed in last step
 }

};

class B2
{
 public:
 B2()
 {
 cout<<endl<<"no arg const in base class B2"<<endl;
 }
 ~B2()
 {
 cout<<endl<<"destructor in base class B2"<<endl;
 }

};

class D:public B1, public B2
{
 public:
 D()
 {
 cout<<endl<< " no arg const of derived  class D"<<endl;
 }

 ~D()
 {
 cout<<endl<<" destructor in  derived  class D"<<endl;
 }

};

void main()
{

 clrscr();
 D obj;
//if getch placed in main,then only constructor o/p will ne seen. destructor
//o/p will not be there . hence place it in  the base class B1 which
//is executed in the last step
getch();
}

/*sequence of execution:
const of base1
const of base2
const of derived
dest of derived
dest of base 2
dest of base 1
implies execution of destructors is in opposite direction
*/