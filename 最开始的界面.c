#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 
void main()
{
  int sele=1;
  Re_file();    //读取元件信息 

  while(sele)
  {
    system("cls");
    printf("\n\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*       1.入库              2.出库          *\n");
    printf("*                                           *\n");
    printf("*       3.查询              4.统计          *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("请选择功能序号:");
    scanf("%d",&sele);
    switch(sele)
    {    
      case 1:Stock_in();Display();break;
      case 2:Stock_out();Display();break;
      case 3:Query();break;
      case 4:Statistics();break;

    }
    printf("\n\n按任意键继续...\n");
    getch();
  }
  Wr_file();
}




//数据读入部分 

typedef struct
{
    int num;   //元件编号
    char name[20];     //元件名称
    int stock;     //原始库存
    int in;           //入库数目
    int out;      //出库数目
    int amount;                   //最终库存
    int warning_value;           //设定的警戒值
    int state;                //库存状态(是否低于警戒值，是否报警)
    int price;             //元件单价 
}goods;
goods s[M];                //元件属性 
goods r[M];                //入库元件属性 
goods t[M];                //出库元件属性 

 
void Re_file()        //读入原始库存文件
{
  FILE*fp;
  int N=0;
  fp=fopen("goods.txt","r");
  while(fscanf(fp,"%d%s%d%d%d%d%d%d%d",&s[N].num,&s[N].name,&s[N].stock,&s[N].in,&s[N].out,&s[N].amount,&s[N].warning_value,&s[N].price)!=EOF)
    N++;
  fclose(fp);
  P=N;
}

