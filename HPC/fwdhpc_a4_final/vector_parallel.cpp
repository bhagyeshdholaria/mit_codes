#include<iostream>
#include<fstream>
#include<omp.h>
#include<vector>
#include <string>
using namespace std;

void insert(vector<int>numbers , string file){
	string number;
	ifstream myfile (file);
	if(myfile.is_open()){
		while(getline (myfile,number)){
			numbers.push_back(stoi(number));
		}
	}

}

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
	
	// serial
	start = omp_get_wtime();
	serial_add(num1,num2,size);
	s_time.push_back(omp_get_wtime()-start);
	
	start = omp_get_wtime();
	serial_sub(num1,num2,size);
	s_time.push_back(omp_get_wtime()-start);
	
	// parallel
	start = omp_get_wtime();
	parallel_add(num1,num2,size);
	p_time.push_back(omp_get_wtime()-start);
	
	start = omp_get_wtime();
	parallel_sub(num1,num2,size);
	p_time.push_back(omp_get_wtime()-start);

	
	cout<<"OPE\tS\t\tP"<<endl;
	cout<<"ADD "<<s_time[0]<<"\t"<<p_time[0]<<endl;
	cout<<"SUB "<<s_time[1]<<"\t"<<p_time[1]<<endl;
	return 0;
}

