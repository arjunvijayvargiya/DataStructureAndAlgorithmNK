#include<stdio.h>
#include<malloc.h>
struct node{
	char a;
	node *next;
};
node *head,*curr,*fp,*sp;
void insert(char chr)
{node *ptr=(node *)malloc(sizeof(node));
 ptr->next=NULL;
 ptr->a=chr;
	if(head==NULL)
	{
	   head=ptr;
	   curr=ptr;
	}else
     {
        curr->next=ptr;
		curr=ptr;	
     }
}
node *reverse(node *temp)
{
	node *current=temp;
	node *prev=NULL;
	node *nextn;
	while(current!=NULL)
	{
		nextn=current->next;
		current->next=prev;
		prev=current;
		current=nextn;
	}
	return prev;
}
int main()
{
  head=(node *)malloc(sizeof(node));
  head=NULL;
  curr=(node *)malloc(sizeof(node));
  curr=NULL;
  char chr;
  while(1)
  { 
  	scanf("%c",&chr);
  	getchar();
	if(chr=='q')
  	  break;
  	else
	  insert(chr);
  }
  sp=head;
  fp=head;
  node *prevsp=head;
  //get middle of node
  while(fp!=NULL && fp->next!=NULL)
  { fp=fp->next->next;
    prevsp=sp;
    sp=sp->next;	
  }
  printf("sp->a=%c\n",sp->a);
  sp=reverse(sp);   
  node *w=head;
  node *y=sp;
  while(w!=NULL && y!=NULL)
  {printf("comparing %c and %c \n",w->a,y->a);
  	if(w->a!=y->a)
  	{
  		printf("not a palindrome\n");
  	    goto last;
	}
  	w=w->next;
  	y=y->next;
  }
  printf("its a palindrome\n");
  last:
  return 0;
}
