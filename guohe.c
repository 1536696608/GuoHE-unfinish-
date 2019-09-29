/*
	过河问题
	autor：巨
	time：2019年9月29日09:04:09 
*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 25
typedef struct Point				//设置坐标 
{
	int x;
	int y;
}Dermination;

typedef struct map 
{
	Dermination SafePlace[MAX_LENGTH]; //安全地点 
	int len;
}Plan;



typedef struct Stack//设置栈 
{
	Dermination *top;
	Dermination *base;
}Stack;

Dermination safe1 = {0,0};	Dermination safe2 = {0,1};	Dermination safe3 = {0,2};	Dermination safe4 = {0,3};
Dermination safe5 = {3,0};	Dermination safe6 = {3,1};	Dermination safe7 = {3,2};	Dermination safe9 = {3,3};
Dermination safe10 = {1,1};	Dermination safe8 = {1,2};

int IsSafe(Dermination s,Plan* Safe)//判断目标区域是否安全 
{
	int i;
	for(i = 0;i < Safe->len;i++)
	{
		if(s.x==Safe->SafePlace[i].x&&s.y==Safe->SafePlace[i].y)
		{
			return 1;
		 } 
	}
	return 0; 
}

void *PushStack(Stack* s,Dermination p)//入栈 
{
	//暂不考虑超出
	*(s->top) = p;
	s->top++; 
}

Dermination PopStack(Stack* s)//出栈 
{
	Dermination p;
	if(s->top == NULL)
	{
		printf("stack is empty");
	}
	p = *(s->top);
	if(s->top == s->base)
	{	
		s->top = NULL;
	}
	else
	{
		s->top--;
	}
	return p;
}
int main()
{
	int i;
	int count = 1;//渡河次数，奇数为去对岸，偶数为回岸 
	Stack Set;
	Set.base = (Dermination *)malloc(sizeof(Dermination));//初始化
	Set.top = Set.base; 
	Dermination start = {3,3};//起点 
	Dermination s[10] = {safe1,safe2,safe3,safe4,safe5,safe6,safe7,safe8,safe9,safe10};
	Plan* Safe = (Plan*)malloc(sizeof(Plan));
	Safe->len = 10;
	for(i = 0;i < Safe->len;i++)
	{
		Safe->SafePlace[i] = s[i];//安全地点 
	}  
	return 0;
}
