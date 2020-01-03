#include<iostream>
#include<omp.h>
using namespace std;


void insertno(long int A[],long int t)
{
	int value=t;
	for(int g=0;g<t;g++)
	{
		A[g]=value;
		value-=1;
	}
	
	/*for(int h=0;h<t;h++)
	{
		cout<<" "<< A[h]<<" ";
	}*/

}

void serial_bubble(long int arr[],long int n)
{
	int q,w;
	double start = omp_get_wtime();
	for(q=0;q<n;q++)
	{
		for(w=0;w<n;w++)
		{
			if(arr[w]>arr[w+1])
			{
				int tmp = arr[w];
				arr[w] = arr[w+1];
				arr[w+1] = tmp;
			}
		}
	}
	//for(l=0;l<n;l++)
	//	cout << " "<< arr[l]<<" ";
	cout<< "\nTime of serial Execution:"<< omp_get_wtime()-start<<endl;
}

void parallel_bubble(long int arr[],long int n)
{
	int i,j,k;
	double start = omp_get_wtime();
	for(i=0;i<((n+1)/2);i++)
	{
		#pragma omp parallel for
		for(j=0;j<n;j+=2)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		#pragma omp parallel for
		for(k=1;k<n-1;k+=2)
		{
			if(arr[k]>arr[k+1])
			{
				int temp1 = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp1;
			}
		}
	}
	//for(m=0;m<n;m++)
	//	cout << " "<< arr[m]<<" ";
	cout<< "\nTime of parallel Execution:"<< omp_get_wtime()-start << endl;
}


int main()
{
	long int n=0;
	cout << "Enter no. of elements: ";
	cin >> n;
	long int arr[n];
	insertno(arr,n);
	serial_bubble(arr,n);
	insertno(arr,n);
	parallel_bubble(arr,n);
}

