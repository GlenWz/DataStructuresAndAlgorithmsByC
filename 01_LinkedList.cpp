#include <stdio.h>
#include <stdlib.h>

int length =10;

typedef struct node{
	int data;
	struct node *next;
}Link;

//创建单链表 
Link *createLink(){
	Link *head=(Link *)malloc(sizeof(Link));
	head->data=NULL;
	Link *retLink=head;
	for(int i=0;i<length;i++){
		Link *s=(Link *)malloc(sizeof(Link));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return retLink;
}

//查找node 
Link *find(Link *head,int pos){
	Link *ret=head;
	for(int i=0;i<pos&&ret->next!=NULL;i++,ret=ret->next){
	}
	return ret;
}

//插入node 
Link *insertNode(Link *head,int x,int pos){
	Link *retLink=head;
	if(pos<=0||pos>=(length+2)){
		printf("The postion is error\n");
	}else{
		Link *posNode=find(head,pos-1);
		if(posNode!=NULL){
			Link *s=(Link *)malloc(sizeof(Link));
			s->data=x;
			s->next=posNode->next;
			posNode->next=s;
			length++;
		}
	}
	return retLink;
}

//删除node 
Link *delNodeByPosition(Link *head,int pos){
	Link *retLink=head;
	Link *preNode,*curNode;
	if(pos>length||pos<1){
		printf("the postion is error!");
	}else{
		if(pos-1==0){
			preNode=head;
		}else{
			preNode=find(head,pos-1);
		}
		curNode=find(head,pos);
		if(preNode!=NULL&&curNode!=NULL){
			preNode->next=curNode->next;
			length--;
			free(curNode);
		}
	}
	return retLink;
}


void Print(Link *head){
	Link *h=head;
	for(h=h->next;h;h=h->next){
		printf("%d->",h->data);
	}
	printf("\n");
}

int main(){
	Link *link=createLink();
	int addNumber=888;
	int position=5;
	Print(link);
	Link *addRetLink=insertNode(link,addNumber,position);
	Print(addRetLink);
	Link *addRetLink2=insertNode(link,999,1);
	Print(addRetLink2);
	Link *addRetLink3=insertNode(link,9899,13);
	Print(addRetLink3);
	printf("length:%d\n",length);
	Link *retDelLink=delNodeByPosition(addRetLink3,13);
	Print(retDelLink);
	Link *retDelLink1=delNodeByPosition(addRetLink3,1);
	Print(retDelLink1);
	printf("length:%d\n",length);
	Link *retDelLink2=delNodeByPosition(addRetLink3,11);
	Print(retDelLink2);
	Link *retDelLink3=delNodeByPosition(addRetLink3,2);
	Print(retDelLink3);
} 
