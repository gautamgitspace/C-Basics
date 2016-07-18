//deleting white spaces, new line from a text file

#include<fstream.h>
#include<conio.h>
#include<iostream.h>
#include<stdio.h>

void main()
{
clrscr();
ofstream outfile;// obj creation
ifstream infile;

infile.open("c:\\ test2.txt");
if(infile.fail())
{
//if it cannot open file it will return true
cout<<"can't open file"<<endl;
getch();
return;     //exit
}

outfile.open("C:\\test3.txt");
if(outfile.fail() )
{
cout<<"can't open text3.txt"<<endl;
getch();
return;
}

char ch;
ch=(char)infile.get(); //read from file
while (!infile.eof() )
{
if(ch== ' ' || ch=='\t'||ch=='\n')
{
outfile.put(ch);
ch=(char)infile.get();
}
}
infile.close();
outfile.close();
}
