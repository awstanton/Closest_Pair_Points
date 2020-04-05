// Andrew Stanton
// 1207210559

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/time.h>
#include <cmath>
#include <algorithm>
using namespace std;
#include "structures.h"
#include "printer.h"
#include "closestPairAlgo1.h"
#include "closestPairAlgo2.h"
#include "closestPairAlgo2Debug.h"

int main() {
	fstream dataStream;
// Variables needed for input: //
	int nP; // number of points
	int debug; // debug parameter
// Variables needed for closestPair n^2 version: //
	int *Lx, *Ly; // list of x coordinates and list of y coordinates
    	struct simplePair *pair1 = NULL; // closest pair returned by O(n^2) algorithm
	struct timeval startTime1, endTime1, interval1; // used for tracking time
	double time1; // used for printing time
// Variables needed for closestPair nlog(n) version: //
	struct originalPoint *pointList; // list of points used by O(nlog(n)) algorithm
	struct pointPair *pair2 = NULL; // closest pair returned by O(nlog(n)) algorithm
    	struct timeval startTime2, endTime2, interval2; // used for tracking time
	double time2; // used for printing time

// Read in points from file //
	dataStream.open("data", fstream::in); // SET THE FILE TO READ FROM //
    	dataStream >> nP;
    	dataStream >> debug;
	
	Lx = new int[nP];
	Ly = new int[nP];
	
// Fill list for O(n^2) algorithm //
	for (int index = 0; index < nP; ++index) {
		dataStream >> Lx[index];
		dataStream >> Ly[index];
	}

// End input, Start output //	
	dataStream.close();
	outputStream.open("output", fstream::out);
	outputStream.setf(ios_base::showpoint);

// Run O(n^2) algorithm //
	// Note: refer to README.txt for links to sources I used to write the code that keeps track of time
	gettimeofday(&startTime1, NULL);
	pair1 = closestPair1(Lx, Ly, pair1, nP); // compute closest pair using O(n^2) algorithm
	gettimeofday(&endTime1, NULL);
	timersub(&endTime1, &startTime1, &interval1);
	time1 = (interval1.tv_sec * 1000000) + interval1.tv_usec; // get time of O(n^2) algorithm

// Output for O(n^2) algorithm //
	outputStream << "Closest pair by O(n^2) algorithm: (" << Lx[pair1->index1] << ", " << Ly[pair1->index1] << ") (" << Lx[pair1->index2] << ", " << Ly[pair1->index2] << ")" << endl;
	outputStream << "Index1: " << pair1->index1 + 1 << ", Index2: " << pair1->index2 + 1 << endl;
	outputStream << "Distance: " << sqrt((long double) pair1->distance) << endl;
	outputStream << "Time: " << time1 << " microseconds" << endl << endl;

// Fill list for O(nlog(n)) algorithm //
	pointList = new struct originalPoint[nP];
	
	for (int index = 0; index < nP; ++index) {
		pointList[index].xValue = Lx[index];
		pointList[index].yValue = Ly[index];
	}
	
// Run O(nlog(n)) algorithm //	
	if (debug == 0) {
		// Note: refer to README.txt for links to sources I used to write the code that keeps track of time
		gettimeofday(&startTime2, NULL);
		pair2 = findClosestPair(pointList, nP); // compute closest pair using O(nlog(n)) algorithm
		gettimeofday(&endTime2, NULL);
		timersub(&endTime2, &startTime2, &interval2);
		time2 = (interval2.tv_sec * 1000000) + interval2.tv_usec; // get time of O(nlog(n)) algorithm
	}
	else if (debug == 1) {	
		// Note: refer to README.txt for links to sources I used to write the code that keeps track of time
		gettimeofday(&startTime2, NULL);
		pair2 = findClosestPairDebug(pointList, nP); // compute closest pair using O(nlog(n)) algorithm
		gettimeofday(&endTime2, NULL);
		timersub(&endTime2, &startTime2, &interval2);
		time2 = (interval2.tv_sec * 1000000) + interval2.tv_usec; // get time of O(nlog(n)) algorithm
	}
	else {
		outputStream << "debug parameter was entered incorrectly - exiting" << endl;
		exit(1);
	}
	
// Output for O(nlog(n)) algorithm //
	if (pair2->leftPoint->originalIndex < pair2->rightPoint->originalIndex) {
		outputStream << "Closest pair by O(nlog(n)) algorithm: (" << pair2->leftPoint->xValue << ", " << pair2->leftPoint->yValue << ") (" << pair2->rightPoint->xValue << ", " << pair2->rightPoint->yValue << ")" << endl;
		outputStream << "Index1: " << pair2->leftPoint->originalIndex + 1 << ", Index2: " << pair2->rightPoint->originalIndex + 1 << endl;
	}
	else {
		outputStream << endl << "Closest pair by O(nlog(n)) algorithm: (" << pair2->rightPoint->xValue << ", " << pair2->rightPoint->yValue << ") (" << pair2->leftPoint->xValue << ", " << pair2->leftPoint->yValue << ")" << endl;
		outputStream << "Index1: " << pair2->rightPoint->originalIndex + 1 << ", Index2: " << pair2->leftPoint->originalIndex + 1 << endl;
	}
	outputStream << "Distance: " << sqrt((long double) pair2->distance) << endl;
	outputStream << "Time: " << time2 << " microseconds\n" << endl;
	outputStream << "n: " << nP << endl;
	outputStream << "time2/(n*log(n)): " << time2 / (nP * log(nP)) << endl;
	outputStream << "time2/(n*log(n)^2): " << time2 / (nP * pow(log(nP), 2)) << endl << endl;

// Output for O(n^2) algorithm //
	outputStream << "Closest pair by O(n^2) algorithm: (" << Lx[pair1->index1] << ", " << Ly[pair1->index1] << ") (" << Lx[pair1->index2] << ", " << Ly[pair1->index2] << ")" << endl;
	outputStream << "Index1: " << pair1->index1 + 1 << ", Index2: " << pair1->index2 + 1 << endl;
	outputStream << "Distance: " << sqrt((long double) pair1->distance) << endl;
	outputStream << "Time: " << time1 << " microseconds" << endl << endl;

// End output, Return from main //
	outputStream.close();
	return 0;
}
