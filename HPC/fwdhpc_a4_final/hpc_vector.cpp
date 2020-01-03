#include<iostream>
#include<fstream>
#include<omp.h>
#include<vector>
#include <string>
using namespace std;

void populateFile(int n){
	ofstream file1,file2;
	file1.open("numbers_1.txt");
	file2.open("numbers_2.txt");
	for(int i=0;i<n;i++){
		file1<<rand()%100<<"\n";
		file2<<rand()%100<<"\n";
	}
	file1.close();
	file2.close();
}

void insert(vector<int>numbers , string file){
	string number;
	ifstream myfile (file);
	if(myfile.is_open()){
		while(getline (myfile,number)){
			numbers.push_back(stoi(number));
			// stoi is used to convert string to an integer
		}
	}

}

// --SERIAL EXECUTION
void serial_add(vector<int>num1 , vector<int>num2 , int size){
	int temp[size];
	int i;	
	for(i =0;i<size;i++){
		temp[i] = num1[i]+num2[i];
	}
}


void serial_sub(vector<int>num1 , vector<int>num2 , int size){
	int temp[size];
	int i;
	for(i =0;i<size;i++){
		temp[i] = num1[i]-num2[i];
	}
}

void serial_mul(vector<int>num1 , vector<int>num2 , int size){
	int temp[size];
	int i;
	for(i =0;i<size;i++){
		temp[i]=num1[i]*num2[i];
	}
}

// --PARALLEL EXECUTION
/*
clause private is used so that each thread gets a local memory of the variable.
If not done , the variable will have a single instance shared among multiple threads , which would disrupt computation on line 56 and similar. 
*/
void parallel_add(vector<int>num1 , vector<int>num2 , int size){
	int temp[size];
	int j;
	#pragma omp parallel for private(j)	
	for(j=0; j<size; j++){
		temp[j]=num1[j]+num2[j];
		cout<<"yes";
	}
}

void parallel_sub(vector<int>num1 , vector<int>num2 , int size){
	int temp[size];
	int j;
	#pragma omp parallel for private(j)	
	for(j=0; j<size; j++){
		temp[j]=num1[j]-num2[j];
	}
}

void parallel_mul(vector<int>num1 , vector<int>num2 , int size){
	int temp[size];
	int j;
	#pragma omp parallel for private(j)	
	for(j=0; j<size; j++){
		temp[j]=num1[j]*num2[j];
	}
}

// --

int main(){
	vector<double>s_time,p_time;
	vector<int>num1,num2;
	string file1,file2;
	int size,num;	
	double start;
	
	cout<<"Vector Size\t:";
	cin>>num;
	populateFile(num);
	
	file1="numbers_1.txt";
	file2="numbers_1.txt";
	insert(num1,file1);
	insert(num2,file2);
		
	size = num1.size();
	/* difference between current instance , i.e. after function ends[omp_get_wtime()] and start i.e. time before function starts gives 		us execution time*/
	// SERIAL EXECUTION
	start = omp_get_wtime();
	serial_add(num1,num2,size);
	s_time.push_back(omp_get_wtime()-start);
	
	start = omp_get_wtime();
	serial_sub(num1,num2,size);
	s_time.push_back(omp_get_wtime()-start);
	
	start = omp_get_wtime();
	serial_mul(num1,num2,size);
	s_time.push_back(omp_get_wtime()-start);
	// PARALLEL EXECUTION
	start = omp_get_wtime();
	parallel_add(num1,num2,size);
	p_time.push_back(omp_get_wtime()-start);
	
	start = omp_get_wtime();
	parallel_sub(num1,num2,size);
	p_time.push_back(omp_get_wtime()-start);

	start = omp_get_wtime();
	parallel_mul(num1,num2,size);
	p_time.push_back(omp_get_wtime()-start);
	
	cout<<"OPE\tS\t\tP"<<endl;
	cout<<"ADD "<<s_time[0]<<"\t"<<p_time[0]<<endl;
	cout<<"SUB "<<s_time[1]<<"\t"<<p_time[1]<<endl;
	cout<<"MUL "<<s_time[2]<<"\t"<<p_time[2]<<endl;
	return 0;
}
/*
student@student:~$ g++ hpc_vector.cpp -fopenmp
student@student:~$ ./a.out
Number of Numbers :4
OPE	S		P
ADD 2.736e-06	0.00156246
SUB 1.022e-06	5.312e-06
MUL 1.019e-06	3.211e-06
student@student:~$ ./a.out
Number of Numbers :100
OPE	S		P
ADD 4.665e-06	0.00122896
SUB 2.876e-06	6.507e-06
MUL 2.73e-06	4.263e-06
student@student:~$ ./a.out
Number of Numbers :500
OPE	S		P
ADD 2.1755e-05	0.00136457
SUB 9.8e-06	1.0759e-05
MUL 9.538e-06	1.5071e-05
student@student:~$ ./a.out
Number of Numbers :1000
OPE	S		P
ADD 7.3687e-05	0.00122529
SUB 2.8402e-05	1.5737e-05
MUL 2.7755e-05	1.3526e-05
student@student:~$ ./a.out
Number of Numbers :5000
OPE	S		P
ADD 0.000116123	0.000124759
SUB 9.1338e-05	4.6864e-05
MUL 9.6244e-05	4.5924e-05
student@student:~$ ./a.out
Number of Numbers :1000000
OPE	S		P
ADD 0.0197456	0.0130549
SUB 0.0176921	0.00780332
MUL 0.0177125	0.0105666
student@student:~$ 


*/

