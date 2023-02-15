#include<stdio.h>
#include<stdlib.h>
 int n,a[100],f[2],g[2],h[2];
 
 int min(int a,int b)
 {
 	if(a<b)
 	return a;
 	else 
 	return b;
 }
 int max(int a,int b)
 {
 	if(a>b)
 	return a;
 	else 
 	return b;
 }
 void MinMax(int a[],int i,int j,int f[])
 {
 	int mid,g[2],h[2];
 	if(i==j)
 	{
 		f[0]=f[1]=a[i];
 	}
 	else if(i==j-1)
 	{
 		f[0]=min(a[i],a[j]);
 		f[1]=max(a[i],a[j]);
	}
	else
	{
		mid= (i+j)/2;
		MinMax(a,i,mid,g);
		MinMax(a,mid+1,j,h);
		
		f[0]=min(g[0],h[0]);
		f[1]=max(g[1],h[1]);
	}
 }
 
int main()
{
	printf("Enter number of Elements\n");
	scanf("%d",&n);
	printf("Enter Elemnets\n");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	MinMax(a,0,n-1,f);
	printf("Min number is %d\n",f[0]);
	printf("Max number is %d\n",f[1]);
	return 0;
}
