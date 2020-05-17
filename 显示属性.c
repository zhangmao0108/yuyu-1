#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 

//显示属性

void Query()
{
    int k,m,i,j=-1;//j是flag 
    char n[20];
    system("cls");
    printf("\n\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*      1.元件编号         2.元件名称        *\n");
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
       printf("元件编号  元件名称  原始库存  入库数目  出库数目  最终库存  警戒值 元件单价\n");//输出属性 
printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d%-10d\n",s[j].num,s[j].name, s[j].stock,s[j].in,s[j].out,s[j].amount,s[j].warning_value,s[j].price);
       SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
       Printf_back();
     }    
    else
    {
         HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
         SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 
FOREGROUND_RED| FOREGROUND_GREEN | 
FOREGROUND_BLUE); 
         printf("元件编号  元件名称  原始库存  入库数目  出库数目  最终库存  警戒值 元件单价\n");
         printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d%-10d\n",s[j].num,s[j].name, s[j].stock, s[j].in, s[j].out,s[j].amount,s[j].warning_value,s[j].price);
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


