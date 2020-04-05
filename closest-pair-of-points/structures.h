

struct originalPoint { // represents points in the original, unsorted list
	int xValue;
	int yValue;
	int xIndex; // index of point in xList
//	int yIndex; // index of point in yList - never used
};

struct point { // represents points in lists other than the original list
	int xValue;
	int yValue;
	int originalIndex; // index of point in original list
	int xIndex; // lets y-list access x list
};

struct simplePair { // used by O(n^2) algorithm
	int index1;
	int index2;
	unsigned long distance;
};

struct pointPair { // used by O(nlog(n)) algorithm
	struct point *leftPoint;
	struct point *rightPoint;
	unsigned long distance;
};

fstream outputStream; // used for outputting to "output" file

