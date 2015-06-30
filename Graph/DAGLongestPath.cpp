#include<stdio.h>
#include<stdlib.h>
struct graph{
  int v;
  int **adj;
  int **wt;
};
struct node{
	int data;
	node *next;
};
node *head=(node *)malloc(sizeof(node));
node *top=(node *)malloc(sizeof(node));
int isEmptystk()
{
	if(top==NULL)
	  return 1;
	else
	  return 0;
}
void push(int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	if(top==NULL)
	{   temp->next=NULL;
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}
int pop()
{
	int x=top->data;
	top=top->next;
	return x;
}
void TS(graph *g,int i,int visited[])
{
	visited[i]=1;
	for(int j=0;j<g->v;j++)
	{
		if(!visited[j] && g->adj[i][j]==1)
		   TS(g,j,visited);
	}
	push(i);
}
void DAG(graph *g,int s)
{
   //initialization of stack
   top=NULL;
   int visited[g->v];
	for(int i=0;i<g->v;i++)
	  visited[i]=0;
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i])
		  TS(g,i,visited);
	}
	int dist[g->v];
	for(int q=0;q<g->v;q++)
	   dist[q]=-60;
	dist[s]=0;
	   //minus infinity	
	while(top!=NULL)
	{   
	    int z=pop();
		//printf("%d->",z);
	    if(dist[z]!=-60)
		{
			for(int i=0;i<g->v;i++)
			{
				if(g->adj[z][i]==1 && dist[i]<dist[z]+g->wt[z][i])
				   dist[i]=dist[z]+g->wt[z][i];
			}
			
		}	
	}
	for(int i=0;i<g->v;i++)
	   printf("%d ",dist[i]);
}
int isEmptyq()
{
	if(head==NULL)
	  return 1;
	else
	  return 0;
}
void enqueue(int x)
{node *temp=(node *)malloc(sizeof(node));
 temp->data=x;
 temp->next=NULL;
 //printf("enqueued\n");
	if(head==NULL)
	{//printf("head added\n");
		head=temp;
	}
	else
	{//printf("another node\n");
		node *rear=head;
		while(rear->next!=NULL)
		  rear=rear->next;
		rear->next=temp;
	}
}
int dequeue()
{
	int x=head->data;
	head=head->next;
	return x;
}
void print()
{
	printf("\n Printing \n");
	node *temp=head;
	while(temp!=NULL)
	{   printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
graph *createGraph(int v)
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->v=v;
	//<------------------dynamic initialization of 2 D array------------>
	g->adj=(int **)malloc(sizeof(int *)*v);
	for(int i=0;i<v;i++)
	  g->adj[i]=(int *)malloc(sizeof(int)*v);
	for(int i=0;i<v;i++)
	  for(int j=0;j<v;j++)
	    g->adj[i][j]=0;
	g->wt=(int **)malloc(sizeof(int *)*v);
	for(int i=0;i<v;i++)
	  g->wt[i]=(int *)malloc(sizeof(int)*v);
	for(int i=0;i<v;i++)
	  for(int j=0;j<v;j++)
	    g->wt[i][j]=0;
	return g;	
}
void addEdge(graph *g,int src,int dest,int wt)
{
	g->adj[src][dest]=1;
	g->wt[src][dest]=wt;
	return;
}
void DFS(graph *g,int v,int visited[])
{
	visited[v]=1;
	printf("%d->",v+1);
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i] && g->adj[v][i]==1)
		   DFS(g,i,visited);		
	}
}
void BFS(graph *g,int v,int visited[])
{   visited[v]=1;
	enqueue(v);
	while(!isEmptyq())
	{   
		int k=dequeue();
		printf("%d->",k+1); 
        for(int i=0;i<g->v;i++)
        {
           if(!visited[i] && g->adj[k][i]==1)
		   {   visited[i]=1;
		   	   enqueue(i);
		   }	
        }
	}
}
void DFSTraversal(graph *g)
{int visited[g->v];
	for(int i=0;i<g->v;i++)
	  visited[i]=0;
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i])
		  DFS(g,i,visited);
	}
	//DFS(g,2,visited);
}
void BFSTraversal(graph *g)
{
	int visited[g->v];
	for(int i=0;i<g->v;i++)
	  visited[i]=0;
	for(int i=0;i<g->v;i++)
	{
		if(!visited[i])
		  BFS(g,i,visited);
	} 
}
int main()
{
	/*graph *g=createGraph(8);
	addEdge(g,1,2);
	addEdge(g,2,3);
	addEdge(g,8,2);
	addEdge(g,3,4);
	addEdge(g,3,5);
	addEdge(g,5,6);
	addEdge(g,5,7);
	addEdge(g,5,8);*/
	graph *g=createGraph(6);
	addEdge(g,0, 1, 5);
    addEdge(g,0, 2, 3);
    addEdge(g,1, 3, 6);
    addEdge(g,1, 2, 2);
    addEdge(g,2, 4, 4);
    addEdge(g,2, 5, 2);
    addEdge(g,2, 3, 7);
    addEdge(g,3, 5, 1);
    addEdge(g,3, 4, -1);
    addEdge(g,4, 5, -2);
	DAG(g,1);
	//DAGLongestPath(g);
	return 0;
}
