#include<stdio.h>
int p[20],r[20];
void kruskal(int,int);
struct mst{
	int u,v,w;
	}e[20],t;
	main()
	{
		int i,E,V,c=0,j;
		printf("enter no of edges and vertices");
		scanf("%d%d",&E,&V);
		for(i=0;i<E;i++){
		printf("Enter start and end vertex with weight");
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		for(i=0;i<(E-1);i++)
		{
			for(j=i+1;j<E;j++)
			{
				if(e[i].w>e[j].w)
				{
				t=e[i];
				e[i]=e[j];
				e[j]=t;
				}
			}
		}
		kruskal(V,E);
	}
	void lin(int u,int v)
	{
	if(r[u]>r[v])
		p[v]=u;
	else
		p[u]=v;
	if(r[u]==r[v])
	r[v]=r[v]+1;
	}
	void makeset(int v)
	{
		p[v]=v;
		r[v]=0;
	}
	void uni(int u,int v)
	{
		lin(find(u),find(v));
	}
	int find(int x)
	{
		if(x!=p[x])
			find(p[x]);
		else
		return p[x];
	}
	void kruskal(int V,int E)
	{
		int i,c=0;
		for(i=1;i<=V;i++)
		makeset(i);
		for(i=0;i<E;i++)
		{
			if(find(e[i].u)!=find(e[i].v))
			{
				printf("%2d -> %2d",e[i].u, e[i].v);
				c=c+e[i].w;
				uni(e[i].u,e[i].v);
			}
		}
		printf("%d",c);
	}
	
		