//writing and reading through functions

#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>

void student_write(int count)
{

char name[20];
int i,marks;

ofstream fout;
fout.open("c:\\student.dat") ;
if(!fout)
{
cout<<"error file cant be created";
return;
}


for(i=0; i < count; i++)
{
cout<<"enter name"<<endl;
cin>>name;
cout<<"enter marks"<<endl;
cin>>marks;


fout<<name<<endl;
fout<<marks<<endl;
}

fout.close();
}

void student_read()
{
char name[20];
int i,marks;
ifstream fin;
fin.open("c:\\student.dat");
if(!fin)
{
cout<<"error file cant be opened"<<endl;
return;
}

}

while (1)
{
fin>>name;
fin>>marks;
if(fin.eof())
{
break;
cout<< " name: "<<name<<endl;
cout<<"marks secured"<<marks<<endl;
}

fin.close();
}

void main()
{
clrscr();
int count;

cout<<"how many students?";
cin>>count;
cout<<endl<<" enter student details to be stored"<<endl;
student_write(count);
cout<<"student details prcessed from the file..."<<endl;
student_read();
getch();
}
