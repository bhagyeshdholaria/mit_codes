#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
//#define n 20000
int n;

/* This function takes first element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot *///
int partition(double arr[], int low, int high){
	int i, j, temp, key;
	key = arr[low];
	i= low + 1;
	j= high;
	while(1){
		while(i < high && key >= arr[i])
    			i++;
		while(key < arr[j])
    			j--;
		if(i < j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else{
			temp= arr[low];
			arr[low] = arr[j];
			arr[j]= temp;
			return(j);
		}
	}
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quicksort(double arr[], int low, int high)
{
	int j;

	if(low < high){
		j = partition(arr, low, high);

		quicksort(arr, low, j - 1);
		quicksort(arr, j + 1, high);

	}
}


int main()
{
	
	printf("Enter number of elements:");
	scanf("%d",&n);
	double arr1[n],arr2[n];
	for(int i=0;i<n;i++){
		
		arr2[i]= arr1[i]= n-i;
	}
	int j;
	double start_s,stop_s;

//serial

	start_s= omp_get_wtime();//start time
	quicksort(arr1,0,n-1);
	stop_s= omp_get_wtime();//end Time
	printf("Time taken by serial: %.4fs\n\n", (double)(stop_s - start_s));


//parallel
	// start_s= omp_get_wtime();//start time
	// parallel_quicksort(arr2,0,n-1);
	// stop_s= omp_get_wtime();//end Time
	// printf("\nTime taken by parallel: %.4fs\n", (double)(stop_s - start_s));

	


	start_s= omp_get_wtime();//start time
	j = partition(arr1,0,n-1);// returns the pivot element
		#pragma omp parallel sections
		{
			#pragma omp section
			{
        			quicksort(arr1,0, j - 1);//Thread 1
    			}
			#pragma omp section
			{
        			quicksort(arr1, j + 1, n-1);//Thread 2
   			}
		}
	stop_s= omp_get_wtime();//end Time
	printf("Time taken by parallel: %.4fs\n", (double)(stop_s - start_s));

/*
	start_s= omp_get_wtime();//start time
	j = partition(arr2,0,n-1);// returns the pivot element
	quicksort(arr2,0, j - 1);//Thread 1
	quicksort(arr2, j + 1, n-1);//Thread 2
	stop_s= omp_get_wtime();//end Time
	printf("Time taken by serial: %.4fs\n", (double)(stop_s - start_s));

*/
}