#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int a[],int n)
{
	int i,j,temp,min,p;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		p=i;
		for(j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				p=j;
			}
		}
		temp=a[i];
		a[i]=a[p];
		a[p]=temp;
	}
}

int main()
{
	int *inp,i,j;
	FILE *input,*output;
	float total;
	clock_t start,end;
	printf("Selection Sort\n");
	input = fopen("input.txt","w");
	output = fopen("output.txt","w");
	for(i=5000;i<=25000;i=i+5000)
	{
	inp = (int*)(malloc(i*sizeof(int)));
	printf("\nFor n = %d\n",i);
	//write i numbers of randam values from 0 to i in input file
	for(j=0;j<i;j++)
	{
	fprintf(input,"%d ",rand()%i);
	}
	fclose(input);
	input = fopen("input.txt","r");
	//read the i numbers of random values and store them in array of int
	for(j=0;j<i;j++)
	{
	fscanf(input,"%d",&inp[j]);
	}
	
	 start=clock();
	selectionsort(inp,i);
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
