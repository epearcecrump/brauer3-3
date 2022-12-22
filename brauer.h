#ifndef BRAUER_H
#define BRAUER_H

#include <map>
#include <string>

//Used to convert the tensor indices into a flat 2D matrix
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

#endif
