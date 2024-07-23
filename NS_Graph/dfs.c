#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *next;
    int vertex;
}node;
 
node *G[20];   
//heads of linked list
int visited[20];
int n;

void main()
{
    int i;
    int start;
    read_graph();
   
	for(i=0;i<n;i++)
    {    visited[i]=0;}
 
    printf("Enter the starting vertex : ");
    scanf("%d",&start);


    DFS(start);
    printf("\n");
}

void DFS(int i)
{
    node *p;
   
	printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
	   if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
void read_graph()
{
    int i,src,dest,ne;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
 
   
	for(i=0;i<n;i++)
    {
        G[i]=NULL;
        //read edges and insert them in G[]
       
		printf("Enter number of edges:");
       	scanf("%d",&ne);
 
       	for(i=0;i<ne;i++)
        {
        	printf("Enter an edge(u,v):");
			scanf("%d%d",&src,&dest);
			insert(src,dest);
        }
    }
}


void insert(int src,int dest)
{
    node *p,*q;
    
	//acquire memory for the new node
	q=(node*)malloc(sizeof(node));
    q->vertex=dest;
    q->next=NULL;
 
    if(G[src]==NULL)
        G[src]=q;
    else
    {
        p=G[src];
       
		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}

 

 

 

 
