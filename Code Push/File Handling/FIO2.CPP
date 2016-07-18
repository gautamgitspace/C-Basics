//reading from a file

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>

void main()
{
clrscr();
char name[30];
int marks;
ifstream fin("C:\\student.dat");
fin>>name;
fin>>marks;

cout<<endl<<" name"<<name<<endl;
cout<<endl<<"marks:"<<marks<<endl;
fin.close();

getch();

}
