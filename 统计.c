#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 



//ͳ�Ʋ��� 

void Query()
{
    int k,m,i,j=-1;//j��flag 
    char n[20];
    system("cls");
    printf("\n\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*      1.Ԫ�����         2.Ԫ��
	����        *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\n\n��������:");
    scanf("%d",&k);
    if(k==1)
    {
      printf("������Ԫ�����:");
      scanf("%d",&m);
      for(i=0;i<P;i++)
      {
        if(m==i)
          j=m-1;
      }
    }
  else if(k==2)
  {
      printf("������Ԫ������:");
      scanf("%s",&n);
      for(i=0;i<P;i++)
      {
        if(strcmp(n,s[i].name)==0)
           j=i;
       }
   }
  Estimate();
  if(j==-1)
  {
      printf("\nû���ҵ�!\n");
      Printf_back();
  }
  else
  {
     if(s[j].state==1)
     {
       HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
       SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
       printf("��Ԫ�������ܼ�ֵ\n"); 
       printf("%-10d\n",s[j].amount*s[j].price);//�������
       SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
       Printf_back();
     }    
    else
    {
         HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
         printf("��Ԫ�������ܼ�ֵ\n");
         printf("%-10d\n",s[j].amount*s[j].price);
         Printf_back();
    }
  }
}



//�ж��Ƿ�Ҫ�����Ĳ��� 

void Estimate()
{
    int i;
    for(i=0;i<P;i++)
    {
        if(s[i].amount>=s[i].warning_value)
            s[i].state=0;
        else if(s[i].amount<s[i].warning_value)
            s[i].state=1;
    }
}


