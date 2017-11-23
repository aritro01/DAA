#include<stdio.h>
int a[20];
merge(int l, int m, int u)
{
	int i,j=m+1,k,t,b[20];
	i=k=l;
	while(i<=m && j<=u)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		b[k++]=a[j++];
	}
	if(j>u)
	{
		for(t=i;t<=m;t++)
			b[k++]=a[t];
	}
	else
	{
		for(t=j;t<=u;t++)
			b[k++]=a[t];
	}
	for(t=l;t<=u;t++)
		a[t]=b[t];
}

ms(int l,int u)
{
	int m;
	if(l<u)
	{
		m=(l+u)/2;
		ms(l,m);
		ms(m+1,u);
		merge(l,m,u);
	}
}
main()
{
	int n,i;
	printf("enter length of array");
	scanf("%d",&n);
	printf("enter elements array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ms(0,n-1);
	printf("sorted array");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
	
	
	
