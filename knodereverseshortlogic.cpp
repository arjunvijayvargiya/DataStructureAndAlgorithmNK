#include<stdio.h>
#include<malloc.h>
struct node{
int val;
node *next;
};
int k;
node *head,*curr;
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
node *reverse(node *hd,int k)
{
	node *current=hd;
	node *prev=NULL;
	node *nxt=NULL;
	int count=0;
	while(current!=NULL && count<k)
	{
		//reverse logic
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
		count++;
	}
	//recursive logic
       if(nxt!=NULL)
	     hd->next=reverse(nxt,k);
	return prev;
}
void print()
{node *ptr=head;
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
	head=reverse(head,k);
	print();
	return 0;
}
