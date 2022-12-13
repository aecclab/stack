#include<stdio.h>
int a[100],size,top;
void push(int item)
{
 if(top==size-1)
	printf("\nstack is full");
else
	top++;
	a[top]=item;
}
void pop()
{
 if(top==-1)
	printf("\nstack is empty");
else
	printf("\npopped elements is %d",a[top]);
	top--;
}
void display()
{
 int i;
 if(top==-1)
	printf("\nstack is empty");
else
	printf("\n elements in stack are\n");
	for(i=0;i<=top;i++)
		printf("\n%d",a[i]);
}
void status()
{
  float free;
  if(top==-1)
	printf("stack is empty");
  else
  {
     printf("stack top element is %d",a[top]);
     if(top==size-1)
	printf("stack is full");
     else
      {
	 free=(float)(size-top-1)*100/size;
	 printf("\nfree space=%f",free);
      }
   }
}




void main()
{
	int choice,n;
	top=-1;
	printf("enter the size of the stack");
	scanf("%d",&size);
	do
	{
		printf("\n1.PUSH\t2.POP\t3.DISPALY\t4.STATUS\t5.EXIT");
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
			case 4:status();
				break;
			case 5:break;
                        default: printf("\nplz enter a valid choice(1,2,3,4,5)");
		}
	}while(choice!=5);
}
