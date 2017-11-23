#include<stdio.h>
struct job{
	int p,w;
	float r,x;
	} j[10],t;
	int main()
	{
		int i,k,m,n;
		float c=0;
		
		printf("enter no of jobs and weight of knapsack\n");
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			printf("enter profit and weight vector");
			scanf("%d%d",&j[i].p,&j[i].w);
			j[i].r=(float)j[i].p/j[i].w;
			j[i].x=0;
		}
		for(i=1;i<n;i++)
		{
			for(k=i+1;k<=n;k++)
			{
				if(j[i].r<j[k].r)
				{
					t=j[i];
					j[i]=j[k];
					j[k]=t;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(j[i].w>m)
				break;
				j[i].x=1;
				m=m-j[i].w;
				c=j[i].p*j[i].x+c;
		}
		if(i<=n)
		{
			j[i].x=(float)m/j[i].w;
			c=c+j[i].p*j[i].w;
		}
		printf("cost=%f \n",c);
		for(i=1;i<=n;i++)
		printf("%f \t",j[i].x);
	return 0;
	}