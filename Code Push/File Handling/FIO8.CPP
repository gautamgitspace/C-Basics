//searching dtat in a file


#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<iostream.h>

class student
{
int rollno;
char name[40];
char grade;
float marks;

public:
void display();
int getno();

};

void student::display()
{
cout<<"roll no:"<<rollno<<endl;
cout<<"name:"<<name<<endl;
cout<<"marks:"<<marks<<endl;
cout<<"grade:"<<grade<<endl;
}

int student::getno()
{
return rollno;
}

void main()
{
clrscr();
student s;
int rln;
char found='n';//set default as record not found
ifstream fin("c\\stu.txt",ios::in);//only for reading
cout<<"enter roll no to be searched";
cin>>rln;
while(!fin.eof())
{
//read one record
//and put it in s
fin.read((char *) &s,sizeof(s));
//match the rollnumber entered by the user
//with the roll no in thr current student object
if(s.getno()==rln)
{
s.display();
found='y';
break;//no need to continue searching if record found
}//end if
}
//end while

if(found=='n')
cout<<"roll no not found:"<<endl;
fin.close();
getch();
}