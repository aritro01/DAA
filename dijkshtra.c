#include<stdio.h>
int g[20][20],d[20],vi[20],n,u,v;
void dijkshtra(int n, int v)
{
	int i,c=1,u,min;
	for(i=1;i<=n;i++)
		vi[i]=0;
	for(i=1;i<=n;i++)
		d[i]=g[v][i];
	d[v]=0;
	vi[v]=1;
	while(c<=n-2)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			if(d[i]<min && vi[i]==0)
			{
				min=d[i];
				u=i;
			}
		}
		vi[u]=1;
		for(i=1;i<=n;i++)
		{
			if(vi[i]==0)
			{
				if(d[u]+g[u][i]<d[i])
					d[i]=d[u]+g[u][i];
			}
		}
		c++;
	}
	for(i=1;i<=n;i++)
		printf("%d\t",d[i]);
}

main()
{
	int w,e,i,j,v,p;
	printf("enter no of vertices and edges\n");
	scanf("%d%d",&v,&e);
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
			g[i][j]=999;
	}
	for(i=1;i<=e;i++)
	{
		printf("enter start and end vertex and weight");
		scanf("%d%d%d",&u,&p,&w);
		g[u][p]=w;
	}
	dijkshtra(v,1);
}

		
		
	