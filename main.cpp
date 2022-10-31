#include <iostream>
#include <vector>
#include "brauer.h"

int row_convert(int choice, int a, int b, int c){
	switch (choice){
		case 1: case 2: case 3: case 4: case 5: case 6:
			return reindex.at(std::make_pair(a,b)) + c - 1;
		case 7: case 11: case 15:
			return reindex.at(std::make_pair(a,a)) + b - 1;
		case 8: case 10: case 14:
			return reindex.at(std::make_pair(a,b)) + b - 1;
		case 9: case 12: case 13:
			return reindex.at(std::make_pair(a,b)) + a - 1;
		default:
			return -1;
	}
}

int col_convert(int choice, int a, int b, int c){
	switch (choice){
		case 1:
			return reindex.at(std::make_pair(a,b)) + c - 1;
		case 2:
			return reindex.at(std::make_pair(b,a)) + c - 1;
		case 3:
			return reindex.at(std::make_pair(c,a)) + b - 1;
		case 4:
			return reindex.at(std::make_pair(a,c)) + b - 1;
		case 5:
			return reindex.at(std::make_pair(c,b)) + a - 1;
		case 6:
			return reindex.at(std::make_pair(b,c)) + a - 1;
		case 7: case 13:
			return reindex.at(std::make_pair(c,c)) + b - 1;
		case 8:
			return reindex.at(std::make_pair(a,c)) + c - 1;
		case 9: case 15:
			return reindex.at(std::make_pair(c,b)) + c - 1;
		case 10:
			return reindex.at(std::make_pair(c,c)) + a - 1;
		case 11: case 12:
			return reindex.at(std::make_pair(b,c)) + c - 1;
		case 14:
			return reindex.at(std::make_pair(c,a)) + c - 1;
		default:
			return -1;
	}
}

int main() {
	const int MAX_CHOICES = 15;
	const int n = 3;
	const int k = 3;
	const int DIM = pow(n, k) - 1;

	//Step 1: Prepare the memory of the 3d matrix;
	std::vector<std::vector<std::vector<int>>> vec_3d;
	for(int i = 0; i <= DIM; ++i){
		std::vector<std::vector<int>> vec_2d;
		for(int j = 0; j <= DIM; ++j){
			std::vector<int> vec_1d;
			vec_2d.push_back(vec_1d);
		}
		vec_3d.push_back(vec_2d);
	}

	//Step 2: Add the number of the Brauer Algebra to the correct cell.
	for(int choice = 1; choice <= MAX_CHOICES; ++choice){
		for(int a = 1; a <= n; ++a){
			for(int b = 1; b <= n; ++b){
				for(int c = 1; c <= n; ++c){
					//1: Based on choice (and a,b,c), lookup correct cell entry.	
					int i = row_convert(choice, a, b, c);
					int j = col_convert(choice, a, b, c);
					//2: Push_back into correct place.
					vec_3d[i][j].push_back(choice);
				}
			}
		}
	}

	//Step 3: Print the matrix!		
	for (int i = 0; i < vec_3d.size(); ++i){
        	for (int j = 0; j < vec_3d[i].size(); ++j){
			std::cout << "[" << " ";
			for (int k = 0; k < vec_3d[i][j].size(); ++k){
				std::cout << vec_3d[i][j][k] << ",";
			}
			std::cout << "]" << " ";
        	}    
		std::cout << std::endl; 
	}

	return 0;
}
