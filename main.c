#include<stdio.h>
#include<stdlib.h>

//TDD exercise
//Magio  2020.6.23



char InputString[50];
int NumberJudge[14]={0,50,51,52,53,54,55,56,57,84,74,81,75,65}; //ASCLL�ж��Ƶ���  
int ColorJudge[5]={0,68,83,72,67};  							//ASCLL�жϻ�ɫ
int CardSave[3][5][14]; 										//��Ƭ��Ϣ����
int Kind[3];														//����������
int i,j,p,q;   													//ѭ������
int num;

void GetCard()													//��ȡ����
{
	gets(InputString); 
	i=5;														//i �ַ���λ
	num=0;  												//�Ѷ��뿨������
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
int FindNumber(int Num,int Group) 								//��������Ƿ��п�
{
	int ColorNumber;
	for(ColorNumber=1;ColorNumber<=4;ColorNumber++)
	{
		if(CardSave[Group][ColorNumber][Num]) return 1;
	}
	return 0;
}
void JudgeCard()													//�жϿ�������
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
			if(FindNumber(j,i)&&FindNumber(j+1,i)&&FindNumber(j+2,i)&&FindNumber(j+3,i)&&FindNumber(j+4,i)) 
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
	
	return 0;
}


int main()
{
	GetCard();
	JudgeCard();

	gets(InputString);
	
	return 0;
	
}
