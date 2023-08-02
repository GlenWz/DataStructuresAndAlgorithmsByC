#include <stdio.h>
#include <stdlib.h>

#define length 10


typedef struct n{
	int data;
	struct n *next;
}LinkList;

//创建链表
LinkList *createLink()
{
	LinkList *head=(LinkList *)malloc(sizeof(LinkList));
	head->data=NULL;
	LinkList *retLink=head;
	for(int i=0;i<length;i++)
	{
		LinkList *s=(LinkList *)malloc(sizeof(LinkList));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return retLink;
}

//反转链表
LinkList *reverseLinkList(LinkList *head)
{
	LinkList *h,*pNode,*qNode,*retLink;
	pNode=head;
	h=head->next;
	retLink=head;
	for(;h!=NULL;)
	{
		qNode=h->next;
		h->next=pNode;
		pNode=h;
		h=qNode;
	}
	retLink->next->next=NULL;
	retLink->next=pNode;
	return retLink;
}

//合并链表
LinkList *mergeLink(LinkList *a,LinkList *b)
{
	LinkList *pa=a;
	a=a->next;
	LinkList *retLink;
	if(a->data!=NULL){
        retLink=(LinkList *)malloc(sizeof(LinkList));
        retLink->next=a;
        retLink->data=NULL;
	}else{
	    retLink=a;
	}
	//printf("hello:%d\n",retLink->data);
	LinkList *pb=b;
	b=b->next;
	while(a&&b)
	{
		if(a->data<=b->data)
		{
			pa->next=b;
			pb->next=b->next;
			b->next=a;
			b=pb->next;
			pa=pa->next;
		}else
		{
			pa=a;
			a=a->next;
		}
	}
	if(a!=NULL)
	{
		pa->next=a;
	}
	if(b!=NULL)
	{
		pa->next=b;
	}
	return retLink;
}

//排序链表
LinkList *sortLink(LinkList *Link)
{
	LinkList *pa,*h,*qa;
	LinkList *retLink=Link;
	for(int i=0;i<length*2;i++)
	{
		for(pa=Link,h=Link->next,qa=h->next;qa!=NULL;)
		{
			if(h->data>qa->data)
			{
				h->next=qa->next;
				qa->next=h;
				pa->next=qa;
				pa=pa->next;
				qa=h->next;
			}else
			{
				pa=pa->next;
				h=h->next;
				qa=qa->next;
			}
		}
	}
	return retLink;
}

//打印链表
void Print(LinkList *Link)
{
	LinkList *h=Link;
	for(h=h->next;h;h=h->next)
	{
		printf("%d->",h->data);
	}
	printf("\n");
}

int main()
{
	LinkList *linkA=createLink();
	printf("the linkA:\n");
	Print(linkA);
	LinkList *reverseLinkA=reverseLinkList(linkA);
    printf("reverseLinkA:\n");
	Print(reverseLinkA);
    printf("-----------\n");
    printf("the Linkb:\n");
	LinkList *linkB=createLink();
    Print(linkB);
    printf("-----------\n");
	LinkList *mergeLinkAB=mergeLink(reverseLinkA,linkB);
    printf("the merge Link:\n");
	Print(mergeLinkAB);
    printf("the sort Link:\n");
	LinkList *LinkSortAB=sortLink(mergeLinkAB);
	Print(LinkSortAB);
	return 0;
}
