#include<ifstream>
#include<vector>
#include<setw>
#include<iostream>
using Matrix = std::vector<std::vector<int>>
//problem 1: File Read in
int mat_read() {
	char filename[256];
	std::cout << "Enter the name of an existing text file: ";
  	std::cin.get (filename,256);
	std:ifstream ifs (filename);

	int n = 0;
	ifs >> n;
	
	Matrix mat1(n, std::vector<int>(n, 0));
    	Matrix mat2(n, std::vector<int>(n, 0));
	
	for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < n; ++j) {
            		file >> mat1[i][j];
        }}

	for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        file >> mat2[i][j];
        }}


return 0;

