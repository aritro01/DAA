#include<stdio.h>
int a[20];
int partition(int l,int u)
{
	int x,c,d,i,j;
	x=a[u];
	i=l-1;
	for(j=l;j<=u-1;j++)
	{
		if(a[j]<=x)
		{
			i++;
			c=a[i];
			a[i]=a[j];
			a[j]=c;
		}
	}
	d=a[i+1];
	a[i+1]=a[u];
	a[u]=d;
	return (i+1);
}
 void quick(int l, int u)
 {
	int q;
	if(l<u)
	{
		q=partition(l,u);
		quick(l,q-1);
		quick(q+1,u);
	}
 }
 main()
 {
	int n,i;
	printf("Enter length of array");
	scanf("%d",&n);
	printf("Enter elements of array");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	quick(0,n-1);
	printf("sorted array");
	for(i=0;i<n;i++)
	printf("%d \t",a[i]);
}
