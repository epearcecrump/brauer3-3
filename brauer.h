#ifndef BRAUER_H
#define BRAUER_H

#include <map>
#include <string>

/* Used to convert the tensor indices into a flat 2D matrix
 * in row_convert(), col_convert()
 */
const std::map<std::pair<int,int>, int> reindex {
	{{1,1}, 0},
	{{1,2}, 3},
	{{1,3}, 6},
	{{2,1}, 9},
	{{2,2}, 12},
	{{2,3}, 15},
	{{3,1}, 18},
	{{3,2}, 21},
	{{3,3}, 24}
};

int row_convert(int choice, int a, int b, int c);
int col_convert(int choice, int a, int b, int c);

//Number of Brauer Diagrams:
const int MAX_CHOICES = 15;
//$n$-dimensional real vector space:
const int n = 3;
//Tensor power used for this example:
const int k = 3;
//Size of 2D matrix (index starts at 0):
const int DIM = pow(n, k) - 1;

#endif
