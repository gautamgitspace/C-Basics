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
ifstream fin("c:\\stu.txt",ios::in)//for reading
ofstream fout("c:\\temp.txt",ios::out)//for writing


int rno;
char found='n',confirm='n';//set default as record not found
cout<<"enter roll no to be deleted:";
cin>>rno;

while(!fin.eof())
{
//read one record
//and put it in s
fin.read((char *) &s,sizeof(s));
//match the rollnumber entered by the user
//with the roll no in thr current student object
if(s.getno()==rno)
{
s.display();
found='y';
//ask the user if he wants to delete the record
cout<<"want to delete the data(y/n)?"<<endl;
cin>>confirm;
//if confirm is yes
//dont copy this record in  temp file
//if it is no, then copy this record
//along with others in the temp file


if(confirm=='n')
 {
  fout.write((char *) &s,sizeof(s));
 }

}
//if record is not found
//copy the record in new file
//the loop will copy all the records
else
{
fout.write((char *) &s,sizeof(s));
}//end else
}//end while

if ( found=='n')

cout<<"record not found"<<endl;
fout.close();
fin.close();

remove("c:\\stu.txt");
rename("c:\\temp.txt","c:\\stu.txt");

//now read the copied file
fin.open("c:\\stu",ios::in);

cout<<"now the file contains"<<endl;
while(!fin.eof())

{
fin.read((char*) &s,sizeof(s));
if(fin.eof())
break;
s.display();
}//end while

fin.close();
}
