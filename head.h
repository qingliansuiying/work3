#ifndef CIRCLE_H
#define CIRCLE_H


//��������
int scan1();            //��ʼ���棬�˲��ֽ���������������л� 
int readFile(char *fp,char *fp2);     //��ȡ�û�Ҫ�����Ŀ����
int scan2(char *fp,int correct);        //���ڶ����û�����Ĵ𰸣��������ж�
void randomNumber();          //���������
void randomOperation();    //�����������
float jisuan(float num1,char sign1,float num2,char sign2,float num3);    //�ó��������ֵļ�����
void generateExpression(char *fp,int type);    //������ʽ��
int calculateResult(int type);      //�������ɵ����ʽ�ӵĽ��
void print(char *fp,int rig,int wro);               //���ͳ�ƽ��

//��������
int flag=0;        //flag���ڼ������ʽ���Ƿ����Ҫ��
float num[5]; 
char sig[4]; 

#endif

