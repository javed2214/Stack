// Stack Implementation Using Static Arrays

#include<stdio.h>
#include<stdlib.h>

int top=-1;
int stack[10];
int item;

int main(){
	int choice;
	while(1){
		printf("\n1. Push Element");
		printf("\n2. Pop Element");
		printf("\n3. Traverse Stack");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(ch){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traverse();
				break;
		}
	}return 0;
}
void push(){
	if(top==-1)
		printf("Stack OverFlow");
	else{
		printf("\nEnter Element to Push: ");
		scanf("%d",&item);
		top++;
		stack[top]=item;
		printf("\nElement Pushed\n");
	}
}
void pop(){
	if(top==-1)
		printf("Stack UnderFlow");
	else{
		item=stack[top];
		top--;
		printf("Item Popped");
	}
}
void traverse(){
	if(top==-1)
		printf("Stack is Empty");
	else{
		for(i=top;i>=0;i--)
			printf("|\t%d\t|\n",stack[i]);
	}
}