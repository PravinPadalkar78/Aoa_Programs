#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void simplemerge(int a[],int low,int mid,int high)
{
    int temp[50000];
	int k,i,j,p;
	k=0;
	i=low;
	j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j])
		{
		 temp[k++]=a[i++];
	    }
		else
		 temp[k++]=a[j++];
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=high)
	{
		temp[k++]=a[j++];
	}
	k=0;
	for(i=low;i<=high;i++)
	a[i]=temp[k++];
	
}
void mergesort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		simplemerge(a,low,mid,high);
	}	
}


int main()
{
	int *inp,i,j;
	FILE *input,*output;
	float total;
	clock_t start,end;
	printf("Merge Sort\n");
	input = fopen("input.txt","w");
	output = fopen("output.txt","w");
	for(i=50000;i<=250000;i=i+50000)
	{
		inp = (int*)(malloc(i*sizeof(int)));
		printf("\nFor n = %d\n",i);
		for(j=0;j<i;j++)
		{
			fprintf(input,"%d ",rand()%i);
		}
		fclose(input);
		input = fopen("input.txt","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%d",&inp[j]);
		}
		
		 start=clock();
	mergesort(inp,0,i-1);
		end=clock();
		
		total=(float)(end-start)/CLOCKS_PER_SEC;
		
		 for(j=0;j<i;j++)
		{
			fprintf(output,"%d ",inp[j]);
		}
		printf("Total Time : %f\n\n",total);
	}
	fclose(input);
	fclose(output);
	return 0;
}
