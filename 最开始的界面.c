#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50 
void main()
{
  int sele=1;
  Re_file();    //��ȡԪ����Ϣ 

  while(sele)
  {
    system("cls");
    printf("\n\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*       1.���              2.����          *\n");
    printf("*                                           *\n");
    printf("*       3.��ѯ              4.ͳ��          *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("��ѡ�������:");
    scanf("%d",&sele);
    switch(sele)
    {    
      case 1:Stock_in();Display();break;
      case 2:Stock_out();Display();break;
      case 3:Query();break;
      case 4:Statistics();break;

    }
    printf("\n\n�����������...\n");
    getch();
  }
  Wr_file();
}




//���ݶ��벿�� 

typedef struct
{
    int num;   //Ԫ�����
    char name[20];     //Ԫ������
    int stock;     //ԭʼ���
    int in;           //�����Ŀ
    int out;      //������Ŀ
    int amount;                   //���տ��
    int warning_value;           //�趨�ľ���ֵ
    int state;                //���״̬(�Ƿ���ھ���ֵ���Ƿ񱨾�)
    int price;             //Ԫ������ 
}goods;
goods s[M];                //Ԫ������ 
goods r[M];                //���Ԫ������ 
goods t[M];                //����Ԫ������ 

 
void Re_file()        //����ԭʼ����ļ�
{
  FILE*fp;
  int N=0;
  fp=fopen("goods.txt","r");
  while(fscanf(fp,"%d%s%d%d%d%d%d%d%d",&s[N].num,&s[N].name,&s[N].stock,&s[N].in,&s[N].out,&s[N].amount,&s[N].warning_value,&s[N].price)!=EOF)
    N++;
  fclose(fp);
  P=N;
}

