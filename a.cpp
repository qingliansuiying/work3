#include<iostream>
#include<ctime>
#include <fstream>
#include<string>
#include<stdlib.h>
#include "head.h"
using namespace std;

int scan1()            //��ʼ���棬�˲��ֽ���������������л� 
{
	cout<<"Welcome!"<<endl;
	cout<<"����������Ҫ����Ŀ������"<<endl;
}


int readFile(char *fp,char *fp2)      //��ȡ�û�Ҫ�����Ŀ����
{
	ofstream ocout;
	ocout.open(fp2, ios::app);
	int sum;
	ifstream icin;
	icin.open(fp);
	icin>>sum;    //���ļ��е����ݶ���sum��
	ocout<<"�û�������������� "<<sum<<endl;
	ocout.close();
	return sum;
}

int scan2(char *fp,int correct)        //���ڶ����û�����Ĵ𰸣��������ж� 
{
	ofstream ocout;
	ocout.open(fp, ios::app);
	int answer;
	cin>>answer;
	ocout << answer <<endl;                   //���û�����Ĵ𰸺��жϽ�������ĵ�
	if(answer==correct)
	{
		cout<<"����ȷ��"<<endl;
		ocout << "����ȷ��" << endl;
		ocout.close();
		return 1;
	}
	else
	{
		cout<<"�𰸴�����ȷ���ǣ�"<<correct<<endl;
		ocout << "�𰸴�����ȷ���ǣ�" << correct << endl;
		ocout.close();
		return 0;
	}
	
} 

void randomNumber()          //���������
{
	int j;
	srand(time(0));
	for(j=1;j<=4;j++)
	{
		num[j]=rand()%10;
	}

}

void randomOperation()    //�����������
{
	srand(time(0));
	int choose,j;
	for(j=1;j<=3;j++)
	{
		choose=rand()%4;
    	switch(choose)
		{
          	case 0:sig[j]='+';break;
        	case 1:sig[j]='-';break;
			case 2:sig[j]='*';break;
			default:sig[j]='/';
		}
	}
}

float jisuan(float num1,char sign1,float num2,char sign2,float num3)    //�ó��������ֵļ�����
{
	float result;
	if(sign1=='+')
	{
		result=num1+num2;
	}
	if(sign1=='-')
	{
		result=num1-num2;
	}
	if(sign1=='*')
	{
		result=num1*num2;
	}
	if(sign1=='/')
	{
		if(num2!=0)
		{
			result=num1/num2;
		}
		else
		{
			flag=1;
		}
	}
	if(sign2=='+')
	{
		result=result+num3;
	}
	if(sign2=='-')
	{
		result=result-num3;
	}
	if(sign2=='*')
	{
		if(sign1=='+')
			result=num1+(num2*num3);
		else if(sign1=='-')
			result=num1-(num2*num3);
		else
			result=result*num3;
	}
	if(sign2=='/')
	{
		if(num2!=0)
		{
			if(sign1=='+')
				result=num1+(num2/num3);
			else if(sign1=='-')
				result=num1-(num2/num3);
			else
				result=result/num3;
		}
		else
		{
			flag=1;
		}
	}
	return result;
}

void generateExpression(char *fp,int type)     //������ʽ��
{
	ofstream ocout;
	ocout.open(fp, ios::app);
    switch(type)                     //��һ�����������������ʽ�ӣ���calculateResult() ����ʹ��
	{
		case 0:
		{
			cout<<num[1]<<sig[1]<<num[2]<<sig[2]<<num[3]<<sig[3]<<num[4]<<'=';
			ocout<<num[1]<<sig[1]<<num[2]<<sig[2]<<num[3]<<sig[3]<<num[4]<<'='<<endl;
			break;					//1+2+3+4=
		}
		case 1:
		{
			cout<<'('<<num[1]<<sig[1]<<num[2]<<')'<<sig[2]<<num[3]<<sig[3]<<num[4]<<'=';
			ocout<<'('<<num[1]<<sig[1]<<num[2]<<')'<<sig[2]<<num[3]<<sig[3]<<num[4]<<'='<<endl;
			break;		//(1+2)+3+4=
		}
		case 2:{
			cout<<num[1]<<sig[1]<<num[2]<<sig[2]<<'('<<num[3]<<sig[3]<<num[4]<<')'<<'=';
			ocout<<num[1]<<sig[1]<<num[2]<<sig[2]<<'('<<num[3]<<sig[3]<<num[4]<<')'<<'='<<endl;
			break;		//1+2+(3+4)=
		}
		case 3:
		{
			cout<<num[1]<<sig[1]<<'('<<num[2]<<sig[2]<<num[3]<<')'<<sig[3]<<num[4]<<'=';
			ocout<<num[1]<<sig[1]<<'('<<num[2]<<sig[2]<<num[3]<<')'<<sig[3]<<num[4]<<'='<<endl;
			break;		//1+(2+3)+4=
		}
		case 4:
		{
			cout<<'('<<num[1]<<sig[1]<<num[2]<<sig[2]<<num[3]<<')'<<sig[3]<<num[4]<<'=';
			ocout<<'('<<num[1]<<sig[1]<<num[2]<<sig[2]<<num[3]<<')'<<sig[3]<<num[4]<<'='<<endl;
			break;		//(1+2+3)+4=
		}
		case 5:
		{
			cout<<num[1]<<sig[1]<<'('<<num[2]<<sig[2]<<num[3]<<sig[3]<<num[4]<<')'<<'=';
		    ocout<<num[1]<<sig[1]<<'('<<num[2]<<sig[2]<<num[3]<<sig[3]<<num[4]<<')'<<'='<<endl;
			break;		//1+(2+3+4)=
		}
	}
	ocout.close();
}
int calculateResult(int type)      //�������ɵ����ʽ�ӵĽ��
{
	float te,result;
	float t[5];
	int test,sign[5],correct;
	int k;
	if(type==0)									//1+2+3+4=
	{
		sig[0]='*';
		t[1]=num[1];
		for(k=0;k<=3;k++)
		{
			if(sig[k]=='+')
				sign[k]=1;
			if(sig[k]=='-')
				sign[k]=2;
			if(sig[k]=='*')
				sign[k]=3;
			if(sig[k]=='/')
				sign[k]=4;
		}
		if(sign[3]+sign[4]==7&&sign[1]==1)
			flag=1;
		else if(sign[3]+sign[4]==7&&sign[1]==2)
			flag=1;
		else
		{
			for(k=1;k<=3;k++)
			{
		 	 	if(sig[k]=='+')
				{
			    	 t[k+1]=t[k]+num[k+1];
				}
			   	if(sig[k]=='-')
				{
			 		t[k+1]=t[k]-num[k+1];
				}
			  	if(sig[k]=='*')
				{
			    	if(sig[k-1]=='+')
			    		t[k+1]=t[k-1]+num[k]*num[k+1];
					else if(sig[k-1]=='-')
			    		t[k+1]=t[k-1]-num[k]*num[k+1];
			    	else
				    	t[k+1]=t[k-1]*num[k+1];
				}
			 	if(sig[k]=='/')
				{
			 		if(num[k+1]==0)
					{
						flag=1;break;
					}
	    			if(sig[k-1]=='+')
	    				t[k+1]=t[k-1]+num[k]/num[k+1];
	    			else if(sig[k-1]=='-')
	    				t[k+1]=t[k-1]-num[k]/num[k+1];
				 	else
						t[k+1]=t[k-1]/num[k+1];
				}
			}
		}
		test=t[4];
		if(flag==0&&test==t[4]&&test>=0)
			correct=test;
		else
			flag=1;
	}
	if(type==1)						//(1+2)+3+4=
	{
		if(sig[1]=='+')
		{
			te=num[1]+num[2];
		}
		if(sig[1]=='-')
		{
			te=num[1]-num[2];
		}
		if(sig[1]=='*')
		{
			te=num[1]*num[2];
		}
		if(sig[1]=='/')
		{
			if(num[2]!=0)
			{
				te=num[1]/num[2];
			}
			else
				flag=1;
		}
		if(flag==0)
		{
			result=jisuan(te,sig[2],num[3],sig[3],num[4]);
			test=result;
			if(test==result&&test>=0)
			{
				correct=test;
			}
			else
			{
				flag=1;
			}
		}
	}
	if(type==2)						//1+2+(3+4)=
	{
		if(sig[3]=='+')
		{
			te=num[3]+num[4];
		}
		if(sig[3]=='-')
		{
			te=num[3]-num[4];
		}
		if(sig[3]=='*')
		{
			te=num[3]*num[4];
		}
		if(sig[3]=='/')
		{
			if(num[4]!=0)
			{
				te=num[3]/num[4];
			}
			else
				flag=1;
		}
		if(flag==0)
		{
			result=jisuan(num[1],sig[1],num[2],sig[2],te);
			test=result;
			if(test==result&&test>=0)
			{
				correct=test;
			}
			else
			{
				flag=1;
			}
		}
	}
	if(type==3)						//1+(2+3)+4=
	{
		if(sig[2]=='+')
		{
			te=num[2]+num[3];
		}
		if(sig[2]=='-')
		{
			te=num[2]-num[3];
		}
		if(sig[2]=='*')
		{
			te=num[2]*num[3];
		}
		if(sig[2]=='/')
		{
			if(num[3]!=0)
			{
				te=num[2]/num[3];
			}
			else
				flag=1;
		}
		if(flag==0)
		{
			result=jisuan(num[1],sig[1],te,sig[3],num[4]);
			test=result;
			if(test==result&&test>=0)
			{
				correct=test;
			}
			else
			{
				flag=1;
			}
		}
	}
	if(type==4)						//(1+2+3)+4=
	{
		te=jisuan(num[1],sig[1],num[2],sig[2],num[3]);
		if(sig[3]=='+')
		{
			result=te+num[4];
		}
		if(sig[3]=='-')
		{
			result=te-num[4];
		}
		if(sig[3]=='*')
		{
			result=te*num[4];
		}
		if(sig[3]=='/')
		{
			if(num[4]!=0)
			{
				result=te/num[4];
			}
			else
				flag=1;
		}
		if(flag==0)
		{
	
			test=result;
			if(test==result&&test>=0)
			{
				correct=test;
			}
			else
			{
				flag=1;
			}
		}
	}
	if(type==5)						//1+(2+3+4)=
	{
		te=jisuan(num[2],sig[2],num[3],sig[3],num[4]);
		if(sig[1]=='+')
		{
			result=num[1]+te;
		}
		if(sig[1]=='-')
		{
			result=num[1]-te;
		}
		if(sig[1]=='*')
		{
			result=num[1]*te;
		}
		if(sig[1]=='/')
		{
			if(t!=0)
			{
				result=num[1]/te;
			}
			else
				flag=1;
		}
		if(flag==0)
		{
	
			test=result;
			if(test==result&&test>=0)
			{
				correct=test;
			}
			else
			{
				flag=1;
			}
		}
	}
	return correct;
}


void print(char *fp,int rig,int wro)                //���ͳ�ƽ��
{ 
	ofstream ocout;
	ocout.open(fp, ios::app);
	ocout<<"��ȷ������"<<rig<<endl;
	cout << "��ȷ������" << rig << endl;
	cout<<"����������"<<wro<<endl;
	ocout<<"����������"<<wro<<endl;
	ocout.close();
}

int main(int argc, char *argv[])          //������
{	
	srand(time(0));
	int i,type,sum=0,correct=0,rig=0,wro=0;  //type���ڿ���ʽ��������ͣ�correct�洢ʽ����ȷ�𰸣�rig��wroͳ���������� 
	scan1();
	sum = readFile(argv[1],argv[2]);   
	for(i=1;i<=sum;)
	{
		randomNumber();
		randomOperation();
		type=rand()%6;
		correct=calculateResult(type);
		if(flag==0)
		{
		
			generateExpression(argv[2],type);
			if(scan2(argv[2],correct)==1)
			{
				rig++;
			}
			else
			{
				wro++;
			}
		}
		else
		{
			flag=0;
			continue;
		}
		i++;
	}
	print(argv[2],rig,wro);
	return 0;
}


