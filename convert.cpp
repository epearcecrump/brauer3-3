#include "brauer.h"

/* row_convert(), col_convert():
 * 
 * These are functions that are used to convert the tensor indices 
 * coming from the 15 Brauer diagrams in $B_3(3)$ into their "flat" 
 * 2D matrix form
 */

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
