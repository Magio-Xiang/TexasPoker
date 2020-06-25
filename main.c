#include<stdio.h>
#include<stdlib.h>

//TDD exercise
//Magio  2020.6.23



char InputString[50];
int NumberJudge[14]={0,50,51,52,53,54,55,56,57,84,74,81,75,65}; //ASCLL�ж��Ƶ���  
int ColorJudge[5]={0,68,83,72,67};  							//ASCLL�жϻ�ɫ
int CardSave[3][5][14]; 										//��Ƭ��Ϣ����
int Kind[3];													//����������
int i,j,p,q;   													//ѭ������
int num;

void GetCard()													//��ȡ����
{
	gets(InputString); 
	i=5;														//i �ַ���λ
	num=0;  													//�Ѷ��뿨������
	while(1)    												//�����
	{
		for(j=1;j<=13;j++)
			if(InputString[i]==NumberJudge[j])   				//j  ����λ
			{
				for(p=1;p<=4;p++)								//p  ��ɫλ
					if(InputString[i+1]==ColorJudge[p])
					{
						CardSave[1][p][j]++;
						num++;
					}
				break;
			}
		i++;
		if(num==5) break;
	}
	num=0;
	while(1)													//�����
	{
		for(j=1;j<=13;j++)
			if(InputString[i]==NumberJudge[j])   				//j  ����λ
			{
				for(p=1;p<=4;p++)								//p  ��ɫλ
					if(InputString[i+1]==ColorJudge[p])
					{
						CardSave[2][p][j]++;
						num++;
					}
				break;
			}
		i++;
		if(num==5) break;
	}	
	return;
}
int FindNumber(int Num,int Group) 								//������ֿ�����
{
	int ColorNumber;
	int NUM=0;													//��Ƭ����										
	for(ColorNumber=1;ColorNumber<=4;ColorNumber++)
	{
		if(CardSave[Group][ColorNumber][Num]) NUM++;
	}
	return NUM;
}
void JudgeCard()												//�жϿ�������
{
	for(i=1;i<=2;i++)											//������
	{
		for(j=1;j<=13;j++)										//j ����  �ҶԺ���
		{
			num=0;												//ͬ����������
			for(p=1;p<=4;p++)									//p ��ɫ
			{
				if(CardSave[i][p][j]) num++;
			}
			if (num==2) Kind[i]++;
			if (num==3) 
			{
				Kind[i]=3;break;
			}
		}
		j=1;													//j ����
		while(1)												//��˳��
		{
			if(j>9) break;
			if(FindNumber(j,i)>0&&FindNumber(j+1,i)>0&&FindNumber(j+2,i)>0&&FindNumber(j+3,i)>0&&FindNumber(j+4,i)>0) 
			{
				Kind[i]=4;
				break;
			}
			j++;
		}
		for(j=1;j<=4;j++)										//��ͬ��  j ��ɫ
		{
			num=0;												//��ɫ������
			for(p=1;p<=13;p++)									//p ����
			{
				if(CardSave[i][j][p]) num++;
			}
			if(num==5)
			{
				if(Kind[i]==4) Kind[i]=6;
				else Kind[i]=5;
			}
		}
	}
	return ;
	
}
int Compare()													//�Ƚϴ�С
{
	if(Kind[1]>Kind[2]) return 1;
	if(Kind[1]<Kind[2]) return 0;
	
	if(Kind[1]==0||Kind[1]==5)									//ɢ�� ͬ��
	{
		for(i=13;i>0;i--)
		{
			if(FindNumber(i,1)>FindNumber(i,2)) return 1;
			if(FindNumber(i,1)<FindNumber(i,2)) return 0;
		}
		return 2;
	}
	if(Kind[1]==1)												//����
	{
		int DoubleNum[3]={0,0,0};								//��������
		for(i=1;i<=2;i++)
		{
			for(j=1;j<=13;j++)
				if(FindNumber(j,i)==2) DoubleNum[i]=j;
		}
		if(DoubleNum[1]>DoubleNum[2]) return 1;
		if(DoubleNum[1]<DoubleNum[2]) return 0;
		for(i=13;i>0;i--)
		{
			if(FindNumber(i,1)>FindNumber(i,2)) return 1;
			if(FindNumber(i,1)<FindNumber(i,2)) return 0;
		}
		return 2;
	}
	if(Kind[1]==2)												//����
	{
		int Double2Num[2][3]={{0,0,0},{0,0,0}};					//��������
		for(i=1;i<=2;i++)
		{
			int DoubleList=0 ;									//����˳��
			for(j=13;j>0;j--)
				if(FindNumber(j,i)==2) 
				{
					Double2Num[DoubleList][i]=j;
					DoubleList++;
				}
		}
		if(Double2Num[1][1]>Double2Num[1][2]) return 1;
		if(Double2Num[1][1]<Double2Num[1][2]) return 0;
		if(Double2Num[2][1]>Double2Num[2][2]) return 1;
		if(Double2Num[2][1]<Double2Num[2][2]) return 0;
		for(i=13;i>0;i--)
		{
			if(FindNumber(i,1)>FindNumber(i,2)) return 1;
			if(FindNumber(i,1)<FindNumber(i,2)) return 0;
		}
		return 2;
		
	}
	if(Kind[1]==3)												//����
	{
		int ThreeNum[3]={0,0,0};								//��������
		for(i=1;i<=2;i++)
		{
			for(j=1;j<=13;j++)
				if(FindNumber(j,i)==3) ThreeNum[i]=j;
		}
		if(ThreeNum[1]>ThreeNum[2]) return 1;
		if(ThreeNum[1]<ThreeNum[2]) return 0;
		for(i=13;i>0;i--)
		{
			if(FindNumber(i,1)>FindNumber(i,2)) return 1;
			if(FindNumber(i,1)<FindNumber(i,2)) return 0;
		}
		return 2;
	}
	if(Kind[1]==4||Kind[1]==6)									//˳�� ͬ��˳
	{
		int Max[3]={0,0,0};										//˳���������
		for(i=1;i<=2;i++)
		{
			for(j=13;j>0;j--)
				if(FindNumber(j,i)>0)
				{
					Max[i]=j;break;
				}
		}
		if(Max[1]>Max[2]) return 1;
		if(Max[1]<Max[2]) return 0;
		return 2;
		
	}
	
}


int main()
{
	GetCard();
	JudgeCard();
	int Result=Compare();
	if(Result==0) printf("White wins\n");
	if(Result==1) printf("Black wins\n");
	if(Result==2) printf("Tie\n");
	gets(InputString);
	
	return 0;
	
}
