#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	tree *right;
	tree *left;
};
struct node{
	tree *tr;
	node *next;
};
node *head,*curr;
tree *root;
void createq()
{
	head=(node *)malloc(sizeof(node));
	head=NULL;
	curr=(node *)malloc(sizeof(node));
	curr=NULL;
}
void enq(tree *temp)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->tr=temp;
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
tree *deq()
{    
     tree *temp=head->tr;
     head=head->next;
	 return temp;	
}
int isEmpty()
{
     if(head==NULL)
	   return 1;
	 else
	   return 0;	
}
void createtree()
{
	root=(tree *)malloc(sizeof(tree));
    root=NULL;
}
void lot()
{
	createq();
	tree *temp;
	enq(root);
	while(!isEmpty())
	{
		 temp=deq();
		 printf("%d",temp->data);
		 if(temp->left)
		   enq(temp->left);
		 if(temp->right)
		   enq(temp->right);		
	}
}
void printOrderTraversal(tree *temp)
{
	if(temp!=NULL)
	{
		printf("%d",temp->data);
        printOrderTraversal(temp->left);
		printOrderTraversal(temp->right);	
	}
}
void insert(int x)
{   tree *ptr=(tree *)malloc(sizeof(tree));
    ptr->data=x;
    ptr->right=NULL;
    ptr->left=NULL;
	if(root==NULL)
	{   printf("added successfully\n");
	    root=ptr;	
	}
	else
	{
		createq();
	    tree *temp;
	    enq(root);
	    while(!isEmpty())
	   {
		 temp=deq();
		 //printf("%d",temp->data);
		 if(temp->left)
		   enq(temp->left);
		 else
		 {
		   temp->left=ptr;
		   printf("added successfully\n");
		   return;
		 }
		 if(temp->right)
		   enq(temp->right);
		 else
	     {   printf("added successfully\n");
	     	temp->right=ptr;
	     	return;
	     }	   		
	   }
	}
}
void mirror(tree *root)
{
	if(root)
	{
	   tree *temp=root->left;
	   root->left=root->right;
	   root->right=temp;	
	   mirror(root->left);
	   mirror(root->right);	
	   
	}
}
int treehite()
{
	int level=0;
	createq();
	tree *temp;
	enq(root);
	enq(NULL);
	while(!isEmpty())
	{   temp=deq();
		//printf("%d",temp->data);
	   if(temp==NULL)
       {
          level++;
		  if(!isEmpty())
		    enq(NULL);      	  
       }
	   else
	   {
		 if(temp->left)
		   enq(temp->left);
		 if(temp->right)
		   enq(temp->right);		
       }
	}
	return level;
}
int main()
{
	createtree();
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	//lot();
	mirror(root);
	lot();
	//printOrderTraversal(root);
	//printf("%d",root->left->right->data);
	//int z=treehite();
	//printf("\n Height=%d \n",z);
	return 0;
}
