#include<stdio.h>
#include<stdlib.h>

//TDD exercise
//Magio  2020.6.23



char InputString[50];
int NumberJudge[14]={0,50,51,52,53,54,55,56,57,84,74,81,75,65}; //ASCLL�ж��Ƶ���  
int ColorJudge[5]={0,68,83,72,67};  							//ASCLL�жϻ�ɫ
int CardSave[3][5][14]; 										//��Ƭ��Ϣ����
int i,j,p,q;   													//ѭ������

void GetCard()													//��ȡ����
{
	gets(InputString); 
	i=5;														//i �ַ���λ
	int num=0;  												//�Ѷ��뿨������
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



int JudgeCard()													//�жϿ�������

{

	return 0;
	
}



int Compare()													//�Ƚϴ�С
{
	
	return 0;
}


int main()
{
	GetCard();

	gets(InputString);
	
	return 0;
	
}
