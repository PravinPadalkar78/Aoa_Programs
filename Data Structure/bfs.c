#include<stdio.h>
int adj[10][10]={0};
int visited[10]={0};

void bfs(int node,int n)
 {
 	int i;
	visited[node]=1; 
	printf("%d\t",node);
	for(i=0;i<=n;i++)
	{
		if(adj[node][i]==1&&visited[i]==0)
		dfs(i,n);
	}	
	
 }
int main()
{
	int e,v,v1,v2,node;
	int i;
	printf("Enter the number of vertex\n");
	scanf("%d",&v);
	printf("Enter the Number of Edges\n");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
		{
			printf("Enter the vertex index for edge\n");
			scanf("%d%d",&v1,&v2);
			adj[v1][v2]=adj[v2][v1]=1;	
		}
	printf("Enter the First node\n");
	scanf("%d",&node);
	
	bfs(node,v);	
		
}
