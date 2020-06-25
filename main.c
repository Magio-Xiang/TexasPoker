#include<stdio.h>
#include<stdlib.h>

//TDD exercise
//Magio  2020.6.23



char InputString[50];
int NumberJudge[14]={0,50,51,52,53,54,55,56,57,84,74,81,75,65}; //ASCLL判断牌点数  
int ColorJudge[5]={0,68,83,72,67};  							//ASCLL判断花色
int CardSave[3][5][14]; 										//卡片信息储存
int Kind[3];													//两组牌类型
int i,j,p,q;   													//循环变量
int num;

void GetCard()													//读取卡牌
{
	gets(InputString); 
	i=5;														//i 字符串位
	num=0;  													//已读入卡牌数量
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
int FindNumber(int Num,int Group) 								//查此数字卡数量
{
	int ColorNumber;
	int NUM=0;													//卡片数量										
	for(ColorNumber=1;ColorNumber<=4;ColorNumber++)
	{
		if(CardSave[Group][ColorNumber][Num]) NUM++;
	}
	return NUM;
}
void JudgeCard()												//判断卡牌类型
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
			if(FindNumber(j,i)>0&&FindNumber(j+1,i)>0&&FindNumber(j+2,i)>0&&FindNumber(j+3,i)>0&&FindNumber(j+4,i)>0) 
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
	if(Kind[1]>Kind[2]) return 1;
	if(Kind[1]<Kind[2]) return 0;
	
	if(Kind[1]==0||Kind[1]==5)									//散牌 同花
	{
		for(i=13;i>0;i--)
		{
			if(FindNumber(i,1)>FindNumber(i,2)) return 1;
			if(FindNumber(i,1)<FindNumber(i,2)) return 0;
		}
		return 2;
	}
	if(Kind[1]==1)												//对子
	{
		int DoubleNum[3]={0,0,0};								//对子数字
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
	if(Kind[1]==2)												//两对
	{
		int Double2Num[2][3]={{0,0,0},{0,0,0}};					//对子数字
		for(i=1;i<=2;i++)
		{
			int DoubleList=0 ;									//两对顺序
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
	if(Kind[1]==3)												//三条
	{
		int ThreeNum[3]={0,0,0};								//三条数字
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
	if(Kind[1]==4||Kind[1]==6)									//顺子 同花顺
	{
		int Max[3]={0,0,0};										//顺子最大数字
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
