#include<stdio.h>
int a[20];
int binary(int l, int u, int s)
{
	int m;
	if(l<=u)
	{
		m=(l+u)/2;
		if(a[m]==s)
			return m;
		else if(a[m]>s)
			binary(l,m-1,s);
		else if(a[m]<s)
			binary(m+1,u,s);
		else
			return -1;
	}
}
main()
{
	int i,s,n,p;
	printf("enter length of array");
	scanf("%d",&n);
	printf("enter elements of array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter search element");
	scanf("%d",&s);
	p=binary(0,n-1,s);
	if(p==-1)
		printf("not found");
	else
		printf("found at=%d th position",p+1);
}
	