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
int max(int a,int b)
{
	if(a>b)
	  return a;
	else
	  return b;
}
void createq()
{
	head=(node *)malloc(sizeof(node));
	head=NULL;
	curr=(node *)malloc(sizeof(node));
	curr=NULL;
}
void deleteq()
{
	free(head);
	free(curr);
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
int getLevel(tree *root,int key,int level)
{
	if(root==NULL)
	  return 0;
	else if(root->data==key)
	  return level;
	else
	{
		return max(getLevel(root->left,key,level+1),getLevel(root->right,key,level+1));
	}
}
tree *parent=(tree *)malloc(sizeof(tree));
void getParent(tree *root,int key)
{
	
	   if(root->left || root->right)
	   {
	   	   if(root->left->data==key || root->right->data==key)
	   	   {
	   	   	  parent=root;
	   	   }
	   	   getParent(root->left,key);
	   	   getParent(root->right,key);
	   }	
}
int anc(tree *root,int key)
{
	if(root==NULL)
	  return 0;
    else if(root->data==key)
      return 1;
    else if(anc(root->left,key) || anc(root->right,key))
      {
      	printf("ancestor of %d:%d\n",key,root->data);
      	return 1;
      }
    return 0;
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
tree *getDeepest(tree *root)
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
		 if(temp->right)
		   enq(temp->right);		
	}
	return temp;
}
int isLeaf(tree *node)
{   if(node==NULL)
      return 0;
	else if(node->left==NULL && node->right==NULL)
	 return 1;
	else
	 return 0;
}
int leftLeafSum(tree *root)
{
	createq();
	tree *temp;
	enq(root);
	int sum=0;
	while(!isEmpty())
	{
		 temp=deq();
		 //printf("%d",temp->data);
		 if(isLeaf(temp->left))
           	sum+=temp->left->data;	   
		 if(temp->left)
		   enq(temp->left);
		 if(temp->right)
		   enq(temp->right);		
	}
	return sum;
}
void treeDel(tree *root,int key)
{
	
	
	
	
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
	//deleteNode(root,7);
	//lot();
	printf("sum=%d\n",leftLeafSum(root));
    getParent(root,7);
    printf("parent of 7 is:%d",parent->data);
    lot();
    tree *s=search(root,7);
    printf("\nsearch of 7:%d\n",s->data);
    lot();
	//printOrderTraversal(root);
	//printf("%d",root->left->right->data);
	//int z=treehite();
	//printf("\n Height=%d \n",z);
	//int w=getLevel(root,9,0);
	//printf("level of 5:%d\n",w);
	//getParent(root,7);
	//printf("\nParent :%d\n",par);
	//int y=anc(root,9);
	return 0;
}
