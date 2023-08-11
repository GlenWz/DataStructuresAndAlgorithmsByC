#include <stdio.h>
#define MAXSIZE 5

//交換算法
void swap(int *px,int *py)
{
	int temp=*px;
	*px=*py;
	*py=temp;
}

//交換排序
void bubble_sort(int a[],int n)
{
	int i,j;
	n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<n-1;i++)
	{
		for(j=4;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(&a[j],&a[j-1]);
			}	
		}
	}
}
int main()
{
	int i;
	int point[MAXSIZE];
	printf("请输入%d分数\n",MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
	{
		printf("%2d号:",i+1);
		scanf("%d",&point[i]);
	}
	bubble_sort(point,MAXSIZE);
	puts("按升序排列：");
	for(i=0;i<MAXSIZE;i++)
	{
		printf("%2d号：%d\n",i+1,point[i]);
	}
	return 0;
}
