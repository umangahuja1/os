#include<stdio.h>
int main()
{FILE *fp;
  int digit=0,a=0;
  char ch;
  fp=fopen("helo","r");
while((ch=fgetc(fp))!=EOF)
{if(0<=(ch-'0')&&(ch-'0')<=9)
  digit++;
if((0<=(ch-'a')&&(ch-'a')<=26)||(0<=(ch-'A')&&(ch-'A')<=26))
a++;

}
fclose(fp);
printf(" Digits %d\n",digit);
printf(" Alphabets %d",a);

return 0;
}