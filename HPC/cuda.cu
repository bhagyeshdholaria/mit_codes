#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<bits/stdc++.h>
#include <numeric>
#include<math.h>
//#define 10 10

using namespace std;

__global__ void cuda_add(int *da,int *db,int *dc)
{
	int i = threadIdx.x + blockIdx.x * blockDim.x;	

	//dc[i] = da[i]=db[i]=0;
	dc[i] = da[i]+db[i];
	//printf("IN GLOBAL %d > %d %d %d \n",i,da[i],db[i],dc[i]);
}

int main()
{
	int a[10],b[10],c[10];
	cout<<"INITIALIZE ARRAY A";	
	
	for(int i=0;i<10;i++)
		{
		cin>>a[i];	
		}
		
	cout<<"INITIALIZE ARRAY B";	
	for(int i=0;i<10;i++)
		{
		cin>>b[i];	
		}
		
	int *da, *db, *dc;
	
	cudaMalloc(&da,10*sizeof(int));
	cudaMalloc(&db,10*sizeof(int));
	cudaMalloc(&dc,10*sizeof(int));
	
	cudaMemcpy(da,a,10*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(db,b,10*sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(dc,c,10*sizeof(int),cudaMemcpyHostToDevice);

	cuda_add<<<2,(10/2)>>>(da,db,dc);

	cudaMemcpy(c,dc,10*sizeof(int),cudaMemcpyDeviceToHost);

	for(int i=0;i<10;i++)
		{
		cout<<c[i]<<"\t";	
		}
		
	cudaFree(da);
	cudaFree(db);
	cudaFree(dc);
	return 0;
}




