#include<stdio.h>
#define initial 0
#define waiting 1
#define visited 2
#define MAX 15

int g[20][20],q[20],s[20];
int f=-1,r=-1,n;
void bfs(int);
int empty();
int del();
void insert(int);
main()
{
	int e,u,v,i,j;
	printf("Enter no of vertex and edges\n");
	scanf("%d%d",&n,&e);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			g[i][j]=0;
		}
	}
	for(i=1;i<=e;i++)
	{
		printf("Enter 1st and end vertex\n");
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	for(i=1;i<=n;i++)
		s[i]=initial;
		bfs(1);
}

void bfs(int v)
{
	int x,i;
	insert(v);
	s[v]=waiting;
	while(!empty())
	{
		x=del();
		printf("%d",x);
		s[x]=visited;
		for(i=1;i<=n;i++)
		{
			if(g[x][i]!=0 && s[i]==initial)
			{
				insert(i);
				s[i]=waiting;
			}
		}
	}
}

int empty()
{
	if(f==-1 || f>r)
		return 1;
	else
		return 0;
}

void insert(int v)
{
	if(r==MAX-1)
		printf("full");
	else
	{
		if(f==-1)
			f++;
			r++;
			q[r]=v;
	}
}

int del()
{
	int x;
	if(f==-1 || f>r)
	    return 1;
	else
	{
		x=q[f];
		f++;
		return x;
	}
}