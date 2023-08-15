#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 9

typedef struct d{
	int data[MAXSIZE];
	int parentpos[MAXSIZE];
}Set;


//创建set
Set *createSet()
{
	Set *s=(Set *)malloc(sizeof(Set));
	for(int i=0;i<MAXSIZE;i++)
	{
		s->data[i]=i+5;
		if(i==8||i==9)
		{
			s->parentpos[i]=-1;
		}else if(i<5)
		{
			s->parentpos[i]=8;
		}else
		{
			s->parentpos[i]=9;
		}
	}
	return s;
}
/*
void print(Set *s)
{
	for(int i=0;i<)
}*/

//查找x
int findx(Set *s,int x)
{
	int i;
	for(i=0;i<MAXSIZE&&s->data[i]!=x;i++)
	{
	}
	if(i>=MAXSIZE)
	{
		return -1;
	}
	for(s->parentpos[s->parentpos[i]]>=0;s->data[])
	{
		return s->parentpos[i];
	}

}


void Union(Set *s,int x,int y)
{
	int root1=findx(s,x);
	int root2=findx(s,y);
	if(root1==root2)
	{
		printf("the root is same");
	}else
	{
		for(int i=0;i<MAXSIZE;i++)
		{
			if(s->data[i]==root1)
			{
				s->parentpos[i]=root2;
			}
		}
	}
}

//检查set
void checkSet(Set *s)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("child=%d\t parent=%d\n",s->data[i],s->parentpos[i]);

	}
}

//
int main()
{
	Set *set=createSet();
	int x=6; int y=13;
	int j=findx(set,x);
	printf("%d\n",j);
	Union(set,x,y);              //liang ge ji he de bing cao zuo
	checkSet(set);
	return 0;
}
