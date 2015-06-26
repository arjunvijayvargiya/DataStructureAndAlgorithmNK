#include<stdio.h>
#include<malloc.h>
struct node{
int val;
node *next;
};
int k;
node *head,*curr;
int arr[10];
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
	print();
	node *start=head;
	int j,l;
	int z=cnt/k;
	printf("z=%d\n",z);
	for(i=0;i<z;i++)
	{node *ptr=start;
	   for(j=0;j<k;j++)
	   { printf("arr[%d]=%d\n",j,ptr->val);
	     arr[j]=ptr->val;
	     ptr=ptr->next;	
	   }
	   for(j=0,l=k-1;j<=k/2;j++,l--)
	   { 
	     int temp=arr[j];
	     arr[j]=arr[l];
	     arr[l]=temp;
	   }
	   printf("\nreversed array\n");
	   for(j=0;j<k;j++)
	   { 
	     printf("%d ",arr[j]);
	   }
	   printf("\n");
	   ptr=start;
	   for(j=0;j<k;j++)
	   {
	   	  ptr->val=arr[j];
	   	  ptr=ptr->next;
	   }
	   start=ptr;
	}
	print();
	return 0;
}
