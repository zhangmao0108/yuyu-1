#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 


//报警部分

 void Display()        //显示库存情况
{
  int i,j;
  system("cls");
  Estimate();
  printf("元件编号  元件名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
  for(i=0,j=1;i<P;i++,j++)
  {
    if(s[i].state==1)        //库存值小于警戒值红字显示
    {
      HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
      printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n", s[i].num, s[i].name, s[i].stock, s[i].in, s[i].out, s[i].amount, s[i].warning_value);
      if(j%10==0&&j!=P)        //控制每次显示十行
      {
        printf("按任意键继续");
        getch();
        puts("\n");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
         printf("元件编号  元件名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
      }
    }
    else if(s[i].state==0)    //库存值不小于警戒值白字显示
    {
      HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
      printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n", s[i].num, s[i].name, s[i].stock, s[i].in, s[i].out, s[i].amount, s[i].warning_value);
      if(j%10==0&&j<P)
      {
          HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
          printf("按任意键继续");
          getch();
          puts("\n");
          printf("元件编号  元件名称  原始库存  入库数目  出库数目  最终库存  警戒值\n");
      }
    }
  }
}




//判断是否要报警的部分,会反复调用 

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


