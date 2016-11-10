/*FILE  I/O:

There are three basic file i/o classes in cpp:
ifstream(derived from istream), ofstream(derived from ostream)
and fstream (derived from iostream).*/

//writing contents to a file:


#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>

void main()
{

char name[30];
int marks;
ofstream fout("c:\\student.dat");

cout<<"enter name";
cin>>name;

cout<<"enter marks";
cin>>marks;

getch();

}

