#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 


//��������

 void Display()        //��ʾ������
{
  int i,j;
  system("cls");
  Estimate();
  printf("Ԫ�����  Ԫ������  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
  for(i=0,j=1;i<P;i++,j++)
  {
    if(s[i].state==1)        //���ֵС�ھ���ֵ������ʾ
    {
      HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
      printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n", s[i].num, s[i].name, s[i].stock, s[i].in, s[i].out, s[i].amount, s[i].warning_value);
      if(j%10==0&&j!=P)        //����ÿ����ʾʮ��
      {
        printf("�����������");
        getch();
        puts("\n");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
         printf("Ԫ�����  Ԫ������  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
      }
    }
    else if(s[i].state==0)    //���ֵ��С�ھ���ֵ������ʾ
    {
      HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
      printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n", s[i].num, s[i].name, s[i].stock, s[i].in, s[i].out, s[i].amount, s[i].warning_value);
      if(j%10==0&&j<P)
      {
          HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE); 
          printf("�����������");
          getch();
          puts("\n");
          printf("Ԫ�����  Ԫ������  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  ����ֵ\n");
      }
    }
  }
}




//�ж��Ƿ�Ҫ�����Ĳ���,�ᷴ������ 

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


