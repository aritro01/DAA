#include<stdio.h>
int x[20];
int place(int , int);
void display(int);
//void nqueen(int,int);
 nqueen(int r, int n) //n=total no of queens  //r=the queen to be placed //r=row no //c=column no
{
	int c;
	for(c=1;c<=n;c++)
	{
		if(place(r,c))
		{
			x[r]=c;
			if(r==n)
				display(n);
			else
				nqueen(r+1,n);
		}
	}
}
int place(int r, int c)
{
	int i;
	for(i=1;i<=r-1;i++)
	{
		if(x[i]==c)
			return 0;
		else if (abs(i-r)==abs(x[i]-c))
			return 0;
	}
		return 1;
		
}
 void display(int n)
 {
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf(" Q ");
			else
				printf(" _ ");
		}
		printf("\n");
	}
}

main()
{
	int n;
	printf("enter no of queens");
	scanf("%d",&n);
	nqueen(1,n);
}