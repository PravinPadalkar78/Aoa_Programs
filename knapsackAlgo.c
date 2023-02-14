#include<stdio.h>
int n,i,m,max=0;
int o[10],p[10],w[10];

void sort()
{
	int temp;
	for(i=0;i<n;i++)
	{
		if((p[i]/w[i]) < (p[i+1]/w[i+1]))
		{
			temp=p[i];
			p[i]=p[i+1];
			p[i+1]=temp;
			
			temp=w[i];
			w[i]=w[i+1];
			w[i+1]=temp;
			
			temp=o[i];
	    	o[i]=o[i+1];
			o[i+1]=temp;
			
		}
	}
	printf("hello\n");
}

void knapsack()
{
	int c;
	c=m;
	for(i=0;i<n;i++)
	{
		if(c-w[i]>=0)
		{
			c=c-w[i];
			max=max+p[i];	
			printf("Object added with weight=%d & profit=%d\n",w[i],p[i]);
		}
		else 
		{
				break;
		}
		
	}
	if(i<n)
		{
			max=max+(p[i]/p[i]*c);
			printf("Object added with weight=%d & profit=%d\n",c,p[i]/p[i]*c);
		}		
	printf("Total profit= %d",max);
	printf("hello");
}
int main()
{
	printf("Enter the number of objects\n");
	scanf("%d",&n);
	printf("Enter capacity\n");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		printf("Enter object,profit,weight=\n");
		scanf("%d%d%d",&o[i],&p[i],&w[i]);
	}
//	sort();	
	knapsack();
	return 0;
}






