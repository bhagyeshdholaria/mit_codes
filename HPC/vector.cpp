
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

void fill_files(int n){
		ofstream file1,file2;
		file1.open("num1.txt");
		file2.open("num2.txt");
		for (int i = 0; i < n; i++)
		{
			file1<<rand()%100<<endl;
			file2<<rand()%100<<endl;
		}
		file1.close();
		file2.close();
	}

void grabinto(vector<int>numvect1,string file1,vector<int>numvect2,string file2){
	string tmp;
	ifstream file1h (file1);
	ifstream file2h (file2);
	
	if(file1h.is_open()){
		while (getline (file1h,tmp)){
			numvect1.push_back(stoi(tmp));
			// cout<<numvect1.back()<<endl;	
		}
	}
	
	if(file2h.is_open()){
		while (getline (file2h,tmp)){
			numvect2.push_back(stoi(tmp));
			// cout<<endl<<numvect2.back()<<endl;
		}
	}

}

void serial_add(vector<int>numvect1 , vector<int>numvect2 , int size){
	int temp[size];
		
	for(int i = 0;i<size;i++){
		temp[i] = numvect1[i]+numvect2[i];
		cout<<"yes";
	}
	cout<<"No";
}

int main() {
	int noe;
	vector<int> v1,v2;

	cout<<"Enter no of elements:";
	cin >> noe;
	fill_files(noe);
	grabinto(v1,"num1.txt",v2,"num2.txt");
	serial_add(v1,v2,noe);
	return 0;
}
