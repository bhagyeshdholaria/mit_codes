#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void generate(int s){
    FILE* file1 = fopen("input1.txt","w+");
    FILE* file2 = fopen("input2.txt","w+");
    for(int i=0;i<s;i++){
        fprintf(file1,"%d ", rand()%5000);
        fprintf(file2,"%d ", rand()%5000);
    }
    fclose(file1);
    fclose(file2);
}

int main(){ 

int s;
printf("Enter size of vector:");
scanf("%d",&s);

generate(s);

FILE* in1 = fopen("input1.txt","r");
FILE* in2 = fopen("input2.txt","r");
FILE* out = fopen("output.txt","w");

int a[s],b[s],sum[s];
double tm1,tm2;


for(int i=0;i<s;i++)
{
    fscanf(in1,"%d",&a[i]);
    fscanf(in2,"%d",&b[i]);
}


tm1 = omp_get_wtime();//SERIAL START
for(int i=0;i<s;i++){
    sum[i] = a[i]+b[i];
    fprintf(out,"%d ",sum[i]);
}
tm2 = omp_get_wtime();
printf("time for serial: %f",tm2-tm1);//SERIAL END


#pragma omp parallel for
for(int i=0;i<s;i++)
{
    fscanf(in1,"%d",&a[i]);
    fscanf(in2,"%d",&b[i]);
}


tm1 = omp_get_wtime();//PARALLEL START
#pragma omp parallel for
for(int i=0;i<s;i++){
    sum[i] = a[i]+b[i];
    fprintf(out,"%d ",sum[i]);
}
tm2 = omp_get_wtime();
printf("\n\nparallel time: %f",tm2-tm1);//PARALLEL ENDS


fclose(in1);
fclose(in2);
fclose(out);
}