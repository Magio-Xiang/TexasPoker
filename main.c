#include<stdio.h>
#include<stdlib.h>

//TDD exercise
//Magio  2020.6.23



char InputString[50];
int NumberJudge[14]={0,50,51,52,53,54,55,56,57,84,74,81,75,65}; //ASCLL判断牌点数  
int ColorJudge[5]={0,68,83,72,67};  							//ASCLL判断花色
int CardSave[3][5][14]; 										//卡片信息储存
int Kind[3];														//两组牌类型
int i,j,p,q;   													//循环变量
int num;

void GetCard()													//读取卡牌
{
	gets(InputString); 
	i=5;														//i 字符串位
	num=0;  												//已读入卡牌数量
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
int FindNumber(int Num,int Group) 								//查此数字是否有卡
{
	int ColorNumber;
	for(ColorNumber=1;ColorNumber<=4;ColorNumber++)
	{
		if(CardSave[Group][ColorNumber][Num]) return 1;
	}
	return 0;
}
void JudgeCard()													//判断卡牌类型
{
	for(i=1;i<=2;i++)											//两组牌
	{
		for(j=1;j<=13;j++)										//j 数字  找对和条
		{
			num=0;												//同数字牌数量
			for(p=1;p<=4;p++)									//p 花色
			{
				if(CardSave[i][p][j]) num++;
			}
			if (num==2) Kind[i]++;
			if (num==3) 
			{
				Kind[i]=3;break;
			}
		}
		j=1;													//j 数字
		while(1)												//找顺子
		{
			if(j>9) break;
			if(FindNumber(j,i)&&FindNumber(j+1,i)&&FindNumber(j+2,i)&&FindNumber(j+3,i)&&FindNumber(j+4,i)) 
			{
				Kind[i]=4;
				break;
			}
			j++;
		}
		for(j=1;j<=4;j++)										//找同花  j 花色
		{
			num=0;												//花色数字量
			for(p=1;p<=13;p++)									//p 数字
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
int Compare()													//比较大小
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
