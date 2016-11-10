//copying contents from one file to another:

#include<fstream.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>

void main()
{
clrscr();
ofstream outfile;
ifstream infile;
infile.open("c:\\ test.dat");
if(infile.fail())
{
//if it cannoy open file it will return true
cout<<"can't open file"<<endl;
getch();
return;//exit
}

outfile.open("C:\\student.dat");

while (!infile.eof() )
{
char ch;
ch=(char)infile.get();//read a character
outfile.put(ch);//write a character
}

infile.close();
outfile.close();
}