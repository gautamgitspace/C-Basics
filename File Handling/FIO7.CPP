//Appending the contents to a file:

#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<iostream.h>

class student
{
private:
char name[40];
int rollno;
char grade;

float marks;
public:
void get_data();
void disp_data();

};

void student::get_data()
{
cout<<"enter roll no"<<endl;
cin>>rollno;
cout<<"enter name"<<endl;
cin.getline(name,40,'\n');
char ch;
cin.get(ch);
cout<<"enter marks"<<endl;
cin>>marks;


if(marks>75)
grade='A';
else
if (marks>=60)
grade='B';
else
if(marks>=50)
grade='C';
else
grade='F';
}

void student::disp_data()
{

cout<<"roll no:"<<rollno<<endl;
cout<<"name:"<<name<<endl;
cout<<"grade:"<<grade<<endl;
cout<<"marks:"<<marks<<endl;
}


void main()
{
clrscr();
student s;
fstream f("c:\\stu.txt",ios::app|ios::in);//input & append mode
char ans='y';
while(ans=='y')
{
s.get_data();//take input from the user
//write an object to a file
f.write((char *) &s,sizeof(s));

cout<<"record added"<<endl;
cout<<"add more records(y/n)?"<<endl;
cin>>ans;
}
//go to begining of file to read records
//and display on console
f.seekg(0);

while(!f.eof() )
{
f.read((char *)&s,sizeof(s));
s.disp_data();
}
getch();
f.close();
}