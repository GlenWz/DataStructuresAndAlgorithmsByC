#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct q {
	int data[10];
	int top;
} Stack;

Stack *createStack() {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	Stack *head = s;
    head->top=0;
	for (int i = 0; i < MAXSIZE; i++) {
		head->data[i] = i*i;
		head->top++;

	}
	return head;
}

//½øÕ»
int push(Stack *stack, int insertNumber) {
    int ret=0;
	if (MAXSIZE==stack->top){
        printf("the stack is full\n");
        ret=-1;
	}else{
        stack->data[stack->top++]=insertNumber;
        ret=1;
	}
    return ret;
}

//³öÕ»
int pop(Stack *stack){
    int retNumber=NULL;
    if(stack->top==0){
        printf("the stack is empty");
    }else{
        retNumber= stack->data[--stack->top];
        stack->data[stack->top]=NULL;
    }
    return retNumber;
}

void printStack(Stack *stack){
    for(int i=stack->top-1;i>=0;i--){
        printf("%d->",stack->data[i]);
    }
    printf("\n");
}



int main() {
	Stack *stack;
	stack = createStack();
	push(stack,888);
    printStack(stack);
	int ret= pop(stack);
	printf("%d\n",ret);
    push(stack,888);
    printStack(stack);
	return 0;
}

