#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct t{
	int data;
	struct t *left,*right;
}bitTree;

//创建二叉树
bitTree *createTree(int a[],int &n)
{
	int numValue=a[n++];
	if(numValue==0)
	{
		return NULL;
	}else
	{
		bitTree *s=(bitTree *)malloc(sizeof(bitTree));
		s->data=numValue;
		s->left=createTree(a,n);
		s->right=createTree(a,n);
		return s;
	}
}

//递归前序遍历二叉树
int preOrder(bitTree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	printf("%d->",t->data);
	preOrder(t->left);
	preOrder(t->right);
}

//递归中序遍历二叉树
int midOrder(bitTree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	midOrder(t->left);
	printf("%d->",t->data);
	midOrder(t->right);
}

//递归后序遍历二叉树
int postOrder(bitTree *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	postOrder(t->left);
	postOrder(t->right);
	printf("%d->",t->data);
}

//层序遍历二叉树
int layerOrder(bitTree *t)
{
	bitTree *s;
	bitTree *queue[MAXSIZE];
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[rear++]=t;
	}
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
}

//求树对深度
int deepOfTree(bitTree *t)
{
	int deepL=0,deepR=0;
	if(t->left!=NULL)
	{
		deepL=deepOfTree(t->left);
	}
	if(t->right!=NULL)
	{
		deepR=deepOfTree(t->right);
	}
	return (deepL>deepR?deepL:deepR)+1;
}

//求树的宽度
int widthOfTree(bitTree *t)
{
	bitTree *queue[MAXSIZE];
	bitTree *s;
	int max=0;
	int front=0,rear=0;
	if(t!=NULL)
	{
		queue[++rear]=t;
		while(front!=rear)
		{
			int len=rear-front;
			if(len>max)
			{
				max=len;
			}
			for(int i=0;i<len;i++)
			{
				s=queue[++front];
				if(s->left!=NULL)
				{
					queue[++rear]=s->left;
				}
				if(s->right!=NULL)
				{
					queue[++rear]=s->right;
				}
			}
		}
		return max;
	}else
	{
		return NULL;
	}

}


int main()
{
	int a[]={1,2,4,0,0,5,6,0,0,7,0,0,3,0,0,};
	int n=0;
	bitTree *t=createTree(a,n);
	printf("the preOrdr:\n");
	preOrder(t);
	printf("\nthe midOrder:\n");
	midOrder(t);
	printf("\nthe postOrder:\n");
	postOrder(t);
	printf("\nthe layerOrder:\n");
	layerOrder(t);
	int deep=deepOfTree(t);
	printf("\nthe deep of tree is %d\n ",deep);
	int wid=widthOfTree(t);
	printf("\nthe width of tree is :%d\n",wid);
	return 0;

}
