#include<stdio.h>
#define initial 0
#define waiting 1
#define visited 2
#define MAX 15

int g[20][20],stack[20],s[20];
int top=-1,n;
void dfs(int);
int empty();
int pop();
void push(int);
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
		dfs(1);
}

void dfs(int v)
{
	int x,i;
	push(v);
	s[v]=waiting;
	while(!empty())
	{
		x=pop();
		printf("%d",x);
		s[x]=visited;
		for(i=1;i<=n;i++)
		{
			if(g[x][i]!=0 && s[i]==initial)
			{
				push(i);
				s[i]=waiting;
			}
		}
	}
}

int empty()
{
	if(top==-1)
		return -1;
	else
		return 0;
}

void push(int v)
{
	if(top==MAX-1)
		printf("full");
	else
	{
		top++;
		stack[top]=v;
	}
}

int pop()
{
	int x;
	if(top==-1)
	    return -1;
	else
	{
		x=stack[top];
		top--;
		return x;
	}
}