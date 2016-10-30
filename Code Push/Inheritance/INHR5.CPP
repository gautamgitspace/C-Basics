#include<stdio.h>
#include<iostream.h>
#include<conio.h>


class first
{
private:
int bookno;
char bname[30];
public:

void getdata() //get function
{
cout<<"Enter book number : "<<endl;
cin>>bookno;
//cin.ignore(100,'\n');
cout<<"enter book name  : "<<endl;
cin.getline(bname,30,'\n');
}


void printdata() // print function
{
cout<<"Book number : "<<bookno<<endl;
cout<<"Book name : "<<bname<<endl;
}
};


class second
{
private:
char auname[30];
char pub[50];
public:

void getdata() // get function
{
cout<<"enter the author name : ";
cin.getline(auname,30,'\n');
cout<<"Enter the publisher name : ";
cin.getline(pub,30,'\n');
}

void printdata()//print function
{
cout<<"author name : "<<auname<<endl;
cout<<"publisher name : "<<pub<<endl;
}

};

class third:public first , public second
{
public:

void getdata()//get function in 3rd class
{
first::getdata();//call to get function of 1st class
second::getdata();//call to get function of 2nd class
}
void printdata()//print function of 3rd class
{
first::printdata();//call
second::printdata();//call
}

};

void main()
{
third obj1;//obj creation
clrscr();
cout<<"enter the infornmation : "<<endl;
obj1.getdata();//call to get of 3rd class
cout<<endl<<"The entered data is : "<<endl;
obj1.printdata();
getch();
}


