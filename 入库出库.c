#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 


//��ⲿ��
 
void Stock_in()        //��������ļ�
{
  FILE*fp;
  int i,j;
  N=0;
  fp=fopen("stockin.txt","r");
  while(fscanf(fp,"%d%d",&r[N].num,&r[N].in)!=EOF)
    N++;
  fclose(fp);
  for(i=0;i<P;i++)
  {
    for(j=0;j<N;j++)
    {
      if(r[i].num==s[j].num)
        s[j].in=r[j].in;
    }
  }
  for(i=0;i<P;i++)
    s[i].amount=s[i].stock+s[i].in;//��������� 
}




//���ⲿ��

 void Stock_out()    //��������ļ�
{
  FILE*fp;
  int i,j;
  N=0;
  fp=fopen("stockout.txt","r");
  while(fscanf(fp,"%d%d",&t[N].num,&t[N].out)!=EOF)
    N++;
  fclose(fp);
  for(i=0;i<P;i++)
  {
    for(j=0;j<N;j++)
    {
      if(t[i].num==s[j].num)
        s[j].out=t[j].out;
    }
  }
  for(i=0;i<P;i++)
    s[i].amount=s[i].stock+s[i].in-s[i].out;//��������� 
}
