#include<stdio.h>
#include<stdlib.h>

//TDD exercise
//Magio  2020.6.23



char InputString[50];
int NumberJudge[14]={0,50,51,52,53,54,55,56,57,84,74,81,75,65}; //ASCLL判断牌点数  
int ColorJudge[5]={0,68,83,72,67};  							//ASCLL判断花色
int CardSave[3][5][14]; 										//卡片信息储存
int i,j,p,q;   													//循环变量

void GetCard()													//读取卡牌
{
	gets(InputString); 
	i=5;														//i 字符串位
	int num=0;  												//已读入卡牌数量
	while(1)    												//存黑牌
	{
		for(j=1;j<=13;j++)
			if(InputString[i]==NumberJudge[j])   				//j  数字位
			{
				for(p=1;p<=4;p++)								//p  颜色位
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
	while(1)													//存白牌
	{
		for(j=1;j<=13;j++)
			if(InputString[i]==NumberJudge[j])   				//j  数字位
			{
				for(p=1;p<=4;p++)								//p  颜色位
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



int JudgeCard()													//判断卡牌类型

{

	return 0;
	
}



int Compare()													//比较大小
{
	
	return 0;
}


int main()
{
	GetCard();

	gets(InputString);
	
	return 0;
	
}
