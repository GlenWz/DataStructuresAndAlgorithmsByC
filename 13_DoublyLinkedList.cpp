#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct d{
	int data;
	struct d *next;
	struct d *pre;
	int Freq;
}LinkList;

//创建链表
LinkList *createLinklist()
{
	LinkList *head=(LinkList *)malloc(sizeof(LinkList));
	head->data=NULL;
	LinkList *ret=head;
	for(int i=1;i<MAXSIZE;i++)
	{
		LinkList *s=(LinkList *)malloc(sizeof(LinkList));
		s->data=i;
		s->Freq=0;
		head->next=s;
		s->pre=head;
		head=s;
	}
	head->next=ret;
	ret->pre=head;
	return ret;
}

//顺序打印链表
void PrintN(LinkList *head)
{
	LinkList *h;
	for(h=head->next;h->data!=NULL;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

//逆序打印链表
void PrintP(LinkList *head)
{
	LinkList *h;
	for(h=head->pre;h->data!=NULL;h=h->pre)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

//交换链表指针
LinkList *Change(LinkList *head)
{
	LinkList *lp,*rp,*lh,*rh,*ret;
	ret=head;
	rh=head->next;
	lh=head->pre;
	lp=head;
	rp=head;
	int i;
	for(i=1;i<MAXSIZE;i++)
	{
		if(i%2==1)
		{
			rp=rh;
			rh=rh->next;
		}else
		{
			rp->next=rh->next;
			rh->next->pre=rp;
			rh->next=lp;
			rh->pre=lh;
			lp->pre=rh;
			lh->next=rh;
			rh=rp->next;
			lp=lp->pre;
			lh=lp->pre;
		}
	}

	return ret;
}

//定位元素n
LinkList *Locate(LinkList *head,int n,int &pos)
{
	LinkList *h,*hp,*ret,*q;
	ret=head;
	h=head->next;
	hp=head->next;
	pos=0;
	for(;h!=NULL&&h->data!=n;)
	{
		h=h->next;
		pos++;
	}
	h->Freq++;
	if(h==NULL)
	{
		printf("NOT FIND!\n");
		return NULL;
	}
	q=h->pre;
	while(q->Freq<=h->Freq&&q->data!=NULL)
	{
		q=q->pre;
	}
	if(q!=h->pre)
	{
		h->pre->next=h->next;
		h->next->pre=h->pre;
		q->next->pre=h;
		h->next=q->next;
		q->next=h;
		h->pre=q;
	}


	return ret;
}

int main()
{
	LinkList *h=createLinklist();
	PrintN(h);
	PrintP(h);
	LinkList *h1=Change(h);
	PrintN(h1);
	int pos=-1;
	LinkList *F1=Locate(h,8,pos);
	printf("the pos is %d\n",pos+1);
	PrintN(F1);
	LinkList *F2=Locate(h,6,pos);
	PrintN(F2);
	LinkList *F3=Locate(h,6,pos);
	PrintN(F3);
	LinkList *F4=Locate(h,6,pos);
	PrintN(F4);
	LinkList *F5=Locate(h,8,pos);
	PrintN(F5);
	return 0;
}
