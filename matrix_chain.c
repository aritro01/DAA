#include<stdio.h>
int s[20][20],m[20][20];
matrix_chain(int n,int p[10])
{
	int i,l,j,k,q;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=1;l<n;l++)
	{
		for(i=1;i<n;i++)
		{
			j=i+l;
			m[i][j]=999;
			for(k=1;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
optimal_paren(int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		optimal_paren(i,s[i][j]);
		optimal_paren(s[i][j]+1,j);
		printf(")");
	}
}

main()
{
	int n,i,j,p[10];
	printf("Enter length of p arrray\n");
	scanf("%d",&n);
	printf("Enter elements of p arrray\n");
	for(i=0;i<=n;i++)
		scanf("%d",&p[i]);
	matrix_chain(n,p);
	printf("%d",m[1][n]);
	optimal_paren(1,n);
}