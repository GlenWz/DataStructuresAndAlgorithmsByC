#include <stdio.h>

void ShellSort(int a[],int len)
{
	int n,j,i,d,tmp;
	n=5;		//shell²ÎÊý 
	for(d=n/2;d>0;d/=2)
	{
		for(i=d;i<len;i+=d)
		{
			tmp=a[i];
			for(j=i;a[j-d]>tmp&&j>=d;j-=d)
			{
				a[j]=a[j-d];
			}
			a[j]=tmp;
		}
	}
}
void Print(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
}


int main()
{

	int a[]={5,78,432,456,1223,4,12,4,1456,78,5,78,432,456,1223,4,12,};
	int len=sizeof(a)/sizeof(a[0]);
	ShellSort(a,len);
	Print(a,len);
	return 0; 
 } 
