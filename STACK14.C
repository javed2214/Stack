// Stack Implementation Through Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int data;
	struct stack *next;
}stack;

stack *push(stack *);
stack *pop(stack *);
void traverse(stack *);

int main(){
	int choice;
	stack *top=NULL;
	while(1){
		printf("\n1. Push Element");
		printf("\n2. Pop Element");
		printf("\n3. Traverse Stack");
		printf("\nExit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				top=push(top);
				break;
			case 2:
				top=pop(top);
				break;
			case 3:
				traverse(top);
				break;
		}
	}
	return 0;
}
stack *push(stack *top){
	stack *temp;
	printf("Enter Element to Push: ");
	temp=(stack *)malloc(sizeof(stack));
	scanf("%d",&temp->data);

	if(top==NULL){
		top=temp;
		temp->next=NULL;
	}
	else{
		temp->next=top;
		top=temp;
		printf("Element Pushed!");
	}
	return top;
}
stack pop(){
	if(top==NULL)
		printf("Stack is Empty!");
	else{
		top=top->next;
		printf("Element Popped!");
	}
	return top;
}
void traverse(stack *top){
	stack *p=top;
	if(top==NULL)
		printf("Stack is Empty!");
	else{
		while(p!=NULL){
			printf("|\t%d\t|\n",p->data);
			p=p->next;
		}
	}
}