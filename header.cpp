#include<stdio.h>
#include<malloc.h>
struct node{
int val;
node *next;
};
int k;
node *head,*curr,*head2,*curr2;
void insert(int x)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->val=x;
	ptr->next=NULL;
	if(head==NULL)
	{
		head=ptr;
		curr=ptr;
	}
	else
	{
		curr->next=ptr;
		curr=ptr;
	}
}
void insert(int x)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->val=x;
	ptr->next=NULL;
	if(head==NULL)
	{
		head=ptr;
		curr=ptr;
	}
	else
	{
		curr->next=ptr;
		curr=ptr;
	}
}
void insert2(int x)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->val=x;
	ptr->next=NULL;
	if(head2==NULL)
	{
		head2=ptr;
		curr2=ptr;
	}
	else
	{
		curr2->next=ptr;
		curr2=ptr;
	}
}
void print()
{node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr=ptr->next;
	}
}
void print2()
{node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr=ptr->next;
	}
}
void print2()
{node *ptr=head2;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr=ptr->next;
	}
}
int main()
{
	head=(node *)malloc(sizeof(node));
	head=NULL;
	curr=(node *)malloc(sizeof(node));
	curr=NULL;
	int i;
	printf("enter the value of k\n");
	scanf("%d",&k);
	int cnt=0;
	printf("enter the values of list\n");
	while(1)
	{ int value;
	  scanf("%d",&value);
		if(value==-1)
		  break;
		else
		{
		  insert(value);
	      cnt++;
		}
	}

	print();
	return 0;
}
