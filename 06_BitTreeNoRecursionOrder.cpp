#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct t{
	int data;
	struct t *left,*right;
}BitTree;

BitTree *createTree(int a[],int &n)
{
	int num=a[n++];
	if(num==0)
	{
		return NULL;
	}
	BitTree *s=(BitTree *)malloc(sizeof(BitTree));
	s->data=num;
	s->left=createTree(a,n);
	s->right=createTree(a,n);
	return s;
}
int preOrder(BitTree *t)
{
	BitTree *queue[MAXSIZE];
	BitTree *s;
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[rear++]=t;
		while(front!=rear)
		{
			s=queue[front++];
			printf("%d->",s->data);
			if(s->left!=NULL)
			{
				queue[rear++]=s->left;
			}
			if(s->right!=NULL)
			{
				queue[rear++]=s->right;
			}
		}
	}else 
	{
		return NULL;
	}
}
int midOrder(BitTree *t)
{
	BitTree *stack[MAXSIZE];
	BitTree *s=t;
	int top=0;
	if(t!=NULL)
	{
		while(top!=0||s!=NULL)
		{
			while(s!=NULL)
			{
				stack[top++]=s;
				s=s->left;
			}
			if(top!=0)
			{
				s=stack[--top];
				printf("%d->",s->data);
				s=s->right;
			}
		}
	}else 
	{
		return NULL;
	}
}

int postOrder(BitTree *t)
{
	BitTree *stack1[MAXSIZE];
	BitTree *stack2[MAXSIZE];
	BitTree *s=t;
	int top1=0;
	int top2=0;
	if(t!=NULL)
	{
		while(s!=NULL||top1!=0)
		{
			while(s!=NULL)
			{
				stack1[top1++]=s;
				stack2[top2++]=s;
				s=s->right;
			}
			if(top1!=0)
			{
				s=stack1[--top1];
				s=s->left;
			}
		}
		while(top2!=0)
		{
			printf("%d->",stack2[--top2]->data);
		}		
	}
}




int main()
{
	int a[]={1,2,0,5,0,0,3,6,0,0,0,};
	int n=0;
	BitTree *t=createTree(a,n);
	printf("\n非递归前序遍历:\n");
	preOrder(t);
	printf("\n非递归中序遍历:\n");
	midOrder(t);
	printf("\n非递归后序遍历:\n");
	postOrder(t);
	
}











