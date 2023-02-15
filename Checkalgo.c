int main()
{
	int n ,a[100],i;
	printf("Enter number of Elements\n");
	scanf("%d",&n);
	printf("Enter Elemnets\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	quicksort(a,0,n-1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}
