#ifndef CIRCLE_H
#define CIRCLE_H


//函数部分
int scan1();            //初始界面，此部分将来打算添加语言切换 
int readFile(char *fp,char *fp2);     //读取用户要求的题目数量
int scan2(char *fp,int correct);        //用于读入用户输入的答案，并进行判断
void randomNumber();          //生成随机数
void randomOperation();    //生成随机符号
float jisuan(float num1,char sign1,float num2,char sign2,float num3);    //得出三个数字的计算结果
void generateExpression(char *fp,int type);    //输出随机式子
int calculateResult(int type);      //计算生成的随机式子的结果
void print(char *fp,int rig,int wro);               //输出统计结果

//变量部分
int flag=0;        //flag用于检测生成式子是否符合要求
float num[5]; 
char sig[4]; 

#endif

