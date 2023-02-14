#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubblesort(int x[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	 {
		for(j=0;j<n-1;j++)
		 {
			if(x[j]>x[j+1])
			{
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		 }
   	 }
}

int main()
{
	int *inp,i,j;
	FILE *input,*output;
	float total;
	clock_t start,end;
	printf("Bubble sort\n");
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
		bubblesort(inp,i);
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
