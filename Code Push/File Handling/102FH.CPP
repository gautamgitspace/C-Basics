#include<stdio.h>
#include<conio.h>
struct student
{
char name [10];
int roll,marks;
};
void main()
{
clrscr();
struct student st1;
FILE *fp;
fp=fopen("dd","a+");
char ch;
do
{
printf("enter name,roll,marks");
scanf("%s%d%d",st1.name,&st1.roll,&st1.marks);
fwrite(&st1,sizeof(st1),1,fp);
printf("continue y/n?");
fflush(stdin);
scanf("%c",&ch);
}while(ch=='y');
rewind(fp);
while(fread(&st1,sizeof(st1),1,fp)!=0)
{
printf("\n%s%d%d",st1.name,st1.roll,st1.marks);
}
fclose(fp);
getch();
}