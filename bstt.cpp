#include<stdio.h>
#include<stdlib.h>
struct bst{
	int data;
	bst *right;
	bst *left;
};
bst *root;
bst *pre=NULL;
bst *suc=NULL;
void createbst()
{
	root=(bst *)malloc(sizeof(bst));
	root=NULL;
}
bst *findmax(bst *root)
{
	if(root==NULL)
	  return NULL;
	else if(root->right==NULL)
	  return root;
	else
	  return findmax(root->right);
}
bst *findmin(bst *root)
{
	if(root==NULL)
	  return NULL;
	else if(root->left==NULL)
	  return root;
	else
	  return findmin(root->left);
}
void presuc(bst *root,int key,bst *pre,bst *suc)
{
	if(root==NULL)
	  return;
	if(root->data==key)
	{printf("inside key found\n");
	  if(root->left!=NULL)
		pre=findmax(root->left);
	 if(root->right!=NULL)	
	    suc=findmin(root->right);
	    printf("%d %d",pre->data,suc->data);
	 return;
	}
	if(root->data>key)
	{
		suc=root;
		presuc(root->left,key,pre,suc);
	}
	else
	{
		pre=root;
		presuc(root->right,key,pre,suc);
	}
}
void insert(int x)
{
	 bst *ptr=(bst *)malloc(sizeof(bst));
     ptr->data=x;
     ptr->left=NULL;
	 ptr->right=NULL;
	 if(root==NULL)
	 {
	 	root=ptr;
	 }
	 else
	 {
	 bst *temp=root;
	 bst *parent=NULL;
	   while(temp)
	  {
	 	if(temp->data>x)
	 	{  parent=temp;
	 	   temp=temp->left;
	    }
		else
		{  parent=temp;
	 	   temp=temp->right;
	    }
	  }
	   if(parent->data>x)
	     parent->left=ptr;
	   else
	     parent->right=ptr;
     }
}
bst *deleter(bst *root,int data)
{
	if(root==NULL)
	 {
	   printf("element not found\n");
	  //return NULL;
     }
	else if(data<root->data)
	  root->left=deleter(root->left,data);
	else if(data>root->data)
	  root->right=deleter(root->right,data); 
	else
	{
	   if(root->left && root->right)
	   {
	   	  bst *temp=findmax(root->left);
	   	  root->data=temp->data;
	   	  root->left=deleter(root->left,root->data);
	   }	
	   else
	   {  bst *f=root;
	   	  if(root->left==NULL)
	   	    root=root->right;
	   	  if(root->right==NULL)
	   	    root=root->left;
	   	  free(f);
	   }
	}
	return root;
}
void print(bst *root)
{
	if(root)
	{
	   print(root->left);
	   printf("%d ",root->data);
	   print(root->right);	
	}
}
int isBST(bst *root)
{
	bst *prev=NULL;
	if(root)
	{
	    if(!isBST(root->left))
	      return 0;
		if(prev && prev->data<root->data)
		   return 1;
		prev=root;
		return isBST(root->right);
	}
	return 1;
}
int main()
{   createbst();
    insert(2);
    insert(1);
    insert(3);
    insert(4);
    //bst *t=deleter(root,210);
    print(root);
    presuc(root,2,pre,suc);
    
	return 0;
}
