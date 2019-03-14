#include<stdio.h>
int a[20][20],q[20],visit[20],n,i,j,f=0,r=-1;
void bfs(int v) 
{
	for(i=1;i<=n;i++)
		if(a[v][i] && !visit[i])
			q[++r] = i;
	if(f<=r) 
	{
		visit[q[f]] = 1;
		bfs(q[f++]);
	}
}
void main() 
{
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d", &n);
	for(i=1;i<=n;i++) 
	{
		q[i] = 0;
		visit[i] = 0;
	}
	
	printf("\n Enter graph data:\n");
	for(i=1;i<=n;i++) 
	{
		for(j=1;j<=n;j++) 
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n Enter the starting vertex:");
	scanf("%d", &v);
	bfs(v);
	for(i=1;i<=n;i++) 
	{
		if(visit[i])
			printf("%d\t", i);
		else 
		{
			printf("\n bfs is not possible");
			break;
		}
	}
}
