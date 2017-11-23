#include<stdio.h>
int max=0,min=0,a[20];
mm(int l, int u)
{
	int max1,min1,m;
	if(l==u)
		max=min=a[l];
	else
	{
		m=(l+u)/2;
		mm(l,m);
		max1=max;
		min1=min;
		mm(m+1,u);
		if(max1>max)
			max=max1;
		if(min1<min)
			min=min1;
	}
}
main()
{
	int n,i;
	printf("enter length of array");
	scanf("%d",&n);
	printf("enter elements of array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mm(0,n-1);
	printf("Max=%d  Min=%d ",max,min);
}

		