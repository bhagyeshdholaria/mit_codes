/*
Name:Devanshu Mistry
Roll No:PE32
WAP for parallel algorithm to add/subtract/multiply two large vectors
*/

#include<iostream>
#include<fstream>
#include<omp.h>

using namespace std;
int main()
{
long int n,i,j;
	
long int arr[100000],arr2[100000],add[100000],sub[100000],mul[100000];
	//for(i=0;i<n;i++)
	//	scanf("%lf",&arr[i]);
	//for(i=0;i<n;i++)
	//	scanf("%lf",&arr2[i]);
ifstream fin; 
  
    fin.open("vector_1.txt");  
    i=0;
    while (fin) { 
         
  	fin>>arr[i];
     	i++;
        
    } 
    n=i-1;	
    fin.close();
    /*
    for(j=0;j<(i-1);j++)
    {
    	printf("%ld ",arr[j]);
    } 
    */
    ifstream fiin; 
    fiin.open("vector_2.txt"); 
    i=0;
    while (fiin) { 
         
  	fiin>>arr2[i];
     	i++;
        
    } 
    fiin.close();
    /*
    for(j=0;j<n;j++)
    {
    	printf("%ld ",arr2[j]);
    } 
    */
    double start=omp_get_wtime();
    for(i=0;i<n;i++)
        add[i]=arr[i]+arr2[i];
    for(i=0;i<n;i++)
    	sub[i]=arr[i]-arr2[i];
    for(i=0;i<n;i++)
    	mul[i]=arr[i]*arr2[i];
    
    double end=omp_get_wtime();
    cout<<"Serial Time:"<<(end-start)<<endl;
    
    double start1=omp_get_wtime(); 
    #pragma omp parallel for
    for(i=0;i<n;i++)
    	add[i]=arr[i]+arr2[i];   		
    #pragma omp parallel for
    for(i=0;i<n;i++)
    	sub[i]=arr[i]-arr2[i];
    #pragma omp parallel for
    for(i=0;i<n;i++)
    	mul[i]=arr[i]*arr2[i];
    
    double end1=omp_get_wtime();
    cout<<"Parallel Time:"<<(end1-start1)<<endl;
return 0;
}
