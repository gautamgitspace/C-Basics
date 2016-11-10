//writing o/p in upper case

#include<ctype.h>
#include<fstream.h>
#include<iostream.h>
#include<conio.h>

//for using toupper() function

void main()
{
ofstream outfile;
ifstream infile;
infile.open("c:\\test.txt");
if ( infile.fail() )
{
cout<<"file cannot be opened"<<endl;
getch();
return;
}

outfile.open("c:\\test2.txt");
if(outfile.fail() )
{
cout<<"cant open test.txt"<<endl;
getch();
return;
}

char ch;
ch=(char)infile.get();
while(!infile.eof() )
{
ch=toupper(ch);//writes in upper case
outfile.put(ch);
ch=(char)infile.get();
}

infile.close();
outfile.close();
}