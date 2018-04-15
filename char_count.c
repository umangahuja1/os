#include<stdio.h>
int main()
{FILE *fp;
  int word=0,count=0,line=0;
  char ch;
  fp=fopen("hello.txt","r");
while((ch=fgetc(fp))!=EOF)
{

if(ch==' '||ch=='\n')
{word++;
}
if(ch=='\n')
{line++;}
count++;}
fclose(fp);
printf("Chars %d",count-1);
printf("\nWords %d",word+1);
printf("\nLines %d",line);
return 0;
}                         