/* A program that prints the image of the surjective map 
 * $B_3(3) -> End_{O(3)}((\mathbb{R}^{3})^{\otimes 3})$
 * as a flat 2D matrix expressed in the standard basis of 
 * $\mathbb{R}^{3}$.
 *
 * Technically, the output of the program is a 2D matrix where 
 * each cell returns a list of indices. 
 * 
 * For each cell of the matrix of 
 * $End_{O(3)}((\mathbb{R}^{3})^{\otimes 3})$, we want to take
 * the list of indices and replace it by a sum of parameters
 * where the indexing set for the sum is this list. 
 */

#include <iostream>
#include <vector>
#include "brauer.h"

int main() {
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
					//1: Based on choice (and a,b,c), 
					//lookup correct cell entry.	
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
