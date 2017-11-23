#include<stdio.h>
int g[20][20],d[20],edge[20][20];
void bellman(int n,int e, int s)
{
	int f=1,u,v,i,j;
	for(i=1;i<=n;i++)
	d[i]=999;
	d[s]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=e;j++)
		{
			u=edge[j][1];
			v=edge[j][2];
			if(d[u]+g[u][v]<d[v])
				d[v]=d[u]+g[u][v];
		}
	}
	for(i=1;i<=e;i++)
	{
		u=edge[i][1];
		v=edge[i][2];
		if(d[u]+g[u][v]<d[v])
		f=0;
	}
	if(f)
	{
		for(i=1;i<=n;i++)
			printf("%d \t",d[i]);
	}
}

main()
{
	int u,v,p,w,i,j,n,e;
	printf("enter no of edges andvertices");
	scanf("%d%d",&e,&n);
for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			g[i][j]=0;
		}
	}
	for(i=1;i<=e;i++)
	{
		printf("Enter start and end vertex with weight");
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=w;
		edge[i][1]=u;
		edge[i][2]=v;
	}
	bellman(n,e,1);
}

	