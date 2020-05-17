#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 



//统计部分 

void Query()
{
    int k,m,i,j=-1;//j是flag 
    char n[20];
    system("cls");
    printf("\n\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*      1.元件编号         2.元件
	名称        *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("\n\n请输入编号:");
    scanf("%d",&k);
    if(k==1)
    {
      printf("请输入元件编号:");
      scanf("%d",&m);
      for(i=0;i<P;i++)
      {
        if(m==i)
          j=m-1;
      }
    }
  else if(k==2)
  {
      printf("请输入元件名称:");
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
      printf("\n没有找到!\n");
      Printf_back();
  }
  else
  {
     if(s[j].state==1)
     {
       HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
       SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
       printf("该元件库内总价值\n"); 
       printf("%-10d\n",s[j].amount*s[j].price);//输出属性
       SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
       Printf_back();
     }    
    else
    {
         HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
         printf("该元件库内总价值\n");
         printf("%-10d\n",s[j].amount*s[j].price);
         Printf_back();
    }
  }
}



//判断是否要报警的部分 

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


