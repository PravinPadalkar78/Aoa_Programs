#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int x[], int n)
{
	int *inp, i, j, key; // temp for swapping

	int arr[n]; // blank array
	

	// till now, input things has been done, now is the main logic
	for(i= 0; i< n-1; i++)
	{
		key = arr[i]; // any number within arr[i] is now stored in key
		j = i -1; // compares: first element is greater than the second element
		while(j >= 0 && arr[j] > key ) //this is for the comparison of arr[i](as key contains arr[i]) and [j].. if true, the greater number i.e arr[j] is shifted forward
		{
			arr[j+1] = arr[j];
			j = j-1;  // remember this thing
		 } 
		 arr[j+1] = i;
	}
	

}

int main()
{
	
	
	
	int *inp, i, j;// inp pointer is for array
	FILE *input, *output;// these are called file pointers; those random numbers are stored in input and output files
	float total;
	clock_t start, end;// clock_t is a structure : within time.h file; have to calculate start and end time
		
		printf("Insertioin sort\n");
		
		input = fopen("input.txt", "w");// fopen is a function to open; w stands for write directory, it first creates and then writes within the file
		output = fopen ("output.txt", "w");
		
		for(i =10000; i<=50000; i= i + 10000) // interval is of 10000 thus i = i+10000
		{
			inp = (int*)(malloc(i*sizeof(int))); // array inp is created of size i; its initial size is 10000
			printf("\nFor n = %d\n", i); // for i =10000, it writes as For 10000
			
			// write i numbers of random values from 0 to i input file
			
			for(j=0; j<i; j++) // this also runs 10000
			{
				fprintf(input, "%d ", rand()%i); // j creates random numbers and prints it in input file; fprintf prints in the file
				
			}
			fclose(input); // input.txt is closed
			input = fopen("input.txt", "r"); // again it is opened but in the read directory ; why this is done is, we have already wrote within the input file, bt now we'll have to read it
			
			// read the i numbers of random values and store them in array of int 
			
			for(j=0; j < i; j++)
			{
				fscanf(input, "%d", &inp[j]);// fscanf takes the values from the input file, which were written using fprintf function
				
			}
			
			start = clock(); // kind of timer and bubblesort function is called; stores starting time
				 
				 insertionSort(inp, i); //  
			
			end =  clock(); // stores ending time
			
			total = (float)(end - start) / CLOCKS_PER_SEC; // divide by clock_per_sec gives total time in seconds
		
			// now array is sorted as well as time is calculated
		
			for(j = 0; j<i; j++)
			{
				fprintf(output, "%d", inp[j]); //array is sorted as well as time is calculated, and printed in output.txt
				
			}
			printf("Total Time : %f\n\n", total);
			
			// time complexity increases as the number of 'n' increases
					
		
		}
		
		fclose(input);
		fclose(output);
		return 0; 
	
}
