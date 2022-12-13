#include<stdio.h>
#include<stdlib.h>


struct node
{
 int data;
 struct node *link;
};


struct node *top;

void display()
{
  struct node *ptr;
 if(top==NULL)
   printf("\n stack is empty....");
 else
{
 
  ptr=top;
  printf("stack elements are");
 while(ptr!=NULL)
 {
      printf("%d\t",ptr->data);
      ptr= ptr->link;
 }
}
}



void push(int item)
{
 struct node *new;
 new=(struct node *)malloc(sizeof(struct node));
 new->data=item;
new->link=top;
top=new;
display();
}


void pop()
{
struct node *temp;
if(top==NULL)
  printf("\nstack is empty");
else
 temp=top;
printf("\npopped item is %d",top->data);
top=top->link;
free(temp);
display();
}

void main()
{
	int choice,n;
	top=NULL;
	do
	{
		printf("\n1.PUSH\t2.POP\t3.DISPALY\t4.EXIT");
		printf("\nEnter choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter a value to be pushed");
				scanf("%d",&n);
				push(n);
				break;
			case 2: pop();
				break;
			case 3:display();
				break;
			case 4:break;
            default: printf("\nplz enter a valid choice(1,2,3,4)");
		}
	}while(choice!=4);
}