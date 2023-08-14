#include <stdio.h>
#include <time.h>

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
int Part(int a[],int left,int right)
{
	int center=(left+right)/2;
	if(a[left]>a[center])
	{
		swap(&a[left],&a[center]);
	}
	if(a[left]>a[right])
	{
		swap(&a[left],&a[right]);
	}
	if(a[center]>a[right])
	{
		swap(&a[center],&a[right]);
	}
	swap(&a[left],&a[center]);
	return a[left];
}

void QuickSort(int a[],int left,int right,int &count)
{

	if(left>right)
	{
		return;
	}
	int i=left;
	int j=right;
	int pivot=Part(a,left,right);
	//int pivot=left;
	while(i<j)
	{
		for(;j>i;--j)
		{
			if(a[j]<pivot)
			{
				break;
			}
		}
		for(;i<j;++i)
		{
			if(a[i]>pivot)
			{
				break;
			}
		}
		if(i<j)
		{
			swap(&a[i],&a[j]);
			count++;
		}
	}
	swap(&a[left],&a[i]);
	QuickSort(a,left,i-1,count);
	QuickSort(a,i+1,right,count);

}

void QuickS(int a[],int len)
{
	int count=0;
	QuickSort(a,0,len,count);
	printf("\n%d\n",count);
}
void PrintQ(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}

int main()
{

	int a[]={5,78,432,456,4,1,789,132,5,78,3,4,12,4,12,4,1,789,123,456,79,12,0,12,456,78,12,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,5,78,432,456,1223,4,12,4,1,789,123,456,79,12,0,12,456,78,12,4,3,9,};
	int len=sizeof(a)/sizeof(a[0]);
	QuickS(a,len-1);
	PrintQ(a,len);

}
