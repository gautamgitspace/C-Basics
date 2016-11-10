//WAP to demonstrate multileval inheritence

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class student
{
protected:
     int roll_no;
public:
    void get_num(int);
    void put_num();
};

void student:: get_num(int a)//defined outside class using scope
{
roll_no=a;
}

void student::put_num()
{
cout<<"roll no"<<roll_no<<endl;
}

class test //: public student     //1st level inheritence
{

protected:
     float sub1;
     float sub2;
public:
     void get_marks(float,float);
     void put_marks();

};

void test::get_marks(float x, float y)
{
sub1=x;
sub2=y;
}

void test:: put_marks()
{
cout<<"marks in sub 1="<<sub1<<endl;
cout<<"marks in sub 2="<<sub2<<endl;
}

class result:public test,public student   //2nd level inheritence
{
   float total;
public:
   void disp();
};

void result::disp()
{
total=sub1 + sub2;
student::put_num();   //call to display roll no
test::put_marks(); //call to display individual marks
cout<<"total is:"<<total<<endl;//to display total
}


void main()
{
clrscr();

result st1;
st1.get_num(111);
st1.get_marks(75.0,89.5);
st1.disp();
getch();
}


