#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int que[MAX];
int front=-1 , rear=-1;

void insert(int que[])
{
	int val;
	printf("eklemek isteginiz sayiyi giriniz:");
	scanf("%d",&val);
	if(front==0 && rear==MAX-1  || front-rear==1)
	{
		printf("dairesel kuyruk dolu oldugu icin ekleme yapamazsin");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		que[rear]=val;
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		que[rear]=val;
	}
	else
	{
		rear++;
		que[rear]=val;
	}
}
void del(int que[])
{
	if(front==-1 && rear==-1)
	{
		printf("dairesel kuyruk bos oldugu icin silme islemi yapamazsin");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}
}
void peek(int que[])
{
	if(front==-1 && rear==-1)
	{
		printf("gosterilecek bir eleman yok");
	}
	else
	{
		printf("%d \n",que[rear]);
	}
}
void display()
{
	int i;
	if(front==-1 && rear ==-1)
	{
		printf("kuyruk bos oldugu icin yazdirilacak eleman yok");
	}
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
				printf("%d ",que[i]);
			
			printf("\n");	
		}
		else
		{
			for(i=front;i<MAX;i++)
				printf("%d ",que[i]);
			for(i=0;i<=rear;i++)
				printf("%d ",que[i]);
			printf("\n");
		}
	}
}
int main()
{
	insert(que);
	insert(que);
	insert(que);
	display();
	del(que);
	display();
	del(que);
	display();
	peek(que);
}
