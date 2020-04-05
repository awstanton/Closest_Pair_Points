// Andrew Stanton
// 1207210559


// Used for the calls to sort function //
bool xCompare(struct point p1, struct point p2) {
        return (p1.xValue < p2.xValue);
}
bool yCompare(struct point p1, struct point p2) {
        return (p1.yValue < p2.yValue);
}


// Recursive function //
struct pointPair* findClosestPairRec(struct point *xList, struct point *yList, int startIndex, int size, int nP) {
//	printXList(xList, startIndex, size);
//	printYList(yList, startIndex, size, nP);
	struct pointPair *deltaPair; // Closest pair of points and the distance between them
	if (size == 3) { // Compare distances between each pair of the 3 points and set deltaPair
		deltaPair = new struct pointPair();
		unsigned long distance1 = pow(xList[startIndex].xValue - xList[startIndex + 1].xValue, 2) + pow(xList[startIndex].yValue - xList[startIndex + 1].yValue, 2);
		unsigned long distance2 = pow(xList[startIndex].xValue - xList[startIndex + 2].xValue, 2) + pow(xList[startIndex].yValue - xList[startIndex + 2].yValue, 2);
		unsigned long distance3 = pow(xList[startIndex + 1].xValue - xList[startIndex + 2].xValue, 2) + pow(xList[startIndex + 1].yValue - xList[startIndex + 2].yValue, 2);
		if (distance1 < distance2) {
			if (distance1 < distance3) { // distance1 is smallest
				deltaPair->leftPoint = &xList[startIndex]; // not referring to original list because faster
				deltaPair->rightPoint = &xList[startIndex + 1];
				deltaPair->distance = distance1;
			}
			else { // distance3 is smallest	
				deltaPair->leftPoint = &xList[startIndex + 1]; // not referring to original list because faster
				deltaPair->rightPoint = &xList[startIndex + 2];
				deltaPair->distance = distance3;
			}
		}
		else {
			if (distance2 < distance3) { // distance2 is smallest
				deltaPair->leftPoint = &xList[startIndex]; // not referring to original list because faster
				deltaPair->rightPoint = &xList[startIndex + 2];
				deltaPair->distance = distance2;
			}
			else { // distance3 is smallest	
				deltaPair->leftPoint = &xList[startIndex + 1]; // not referring to original list because faster
				deltaPair->rightPoint = &xList[startIndex + 2];
				deltaPair->distance = distance3;
			}
		}
	}
	else if (size == 2) { // Get the distance between the 2 points
		deltaPair = new struct pointPair();
		unsigned long distance = pow(xList[startIndex].xValue - xList[startIndex + 1].xValue, 2) + pow(xList[startIndex].yValue - xList[startIndex + 1].yValue, 2);
		deltaPair->leftPoint = &xList[startIndex];
		deltaPair->rightPoint = &xList[startIndex + 1];
		deltaPair->distance = distance;
	}
	else if (size == 1) {
		return NULL;
	}
    else {
// Get parameters for recursive calls //
        int leftSize = floor(size / 2.0);
        int rightSize = ceil(size / 2.0);
	int leftStartIndex = startIndex;
        int rightStartIndex = leftStartIndex + leftSize;
        struct pointPair *leftPair;
        struct pointPair *rightPair;
// Get closest pair from left section, Get closest pair from right section //
        leftPair = findClosestPairRec(xList, yList, leftStartIndex, leftSize, nP);
	rightPair = findClosestPairRec(xList, yList, rightStartIndex, rightSize, nP);	

// Get closer pair from the closest pairs from left and right sections, Delete other one //
        if (leftPair->distance <= rightPair->distance) {
        	deltaPair = leftPair;
		delete rightPair; // not setting to NULL to save time
        }
        else {
        	deltaPair = rightPair;
		delete leftPair; // not setting to NULL to save time
        }
//	outputStream << "delta: " << sqrt((long double)deltaPair->distance) << "\n\n";

// Construct Sy: list of candidate points for closest pair, where one point is on left and one point is on right //
        int midPoint = xList[rightStartIndex].xValue;
	int midCount = 0;
	for (int index = startIndex; index < startIndex + size; ++index) { // Determine how much space to allocate
            if (pow(midPoint - xList[index].xValue, 2) < deltaPair->distance) {
                ++midCount;
            }
	}

	struct point **yMidList = new struct point*[midCount];
        int midIndex = 0;
	for (int index = 0; index < nP; ++index) { // If the yList point is one considered in xList and it is close enough to midLine, Add it to Sy
		if (yList[index].xIndex >= startIndex && yList[index].xIndex < startIndex + size && pow(midPoint - yList[index].xValue, 2) < deltaPair->distance) {
			yMidList[midIndex] = &yList[index];
			++midIndex;
		}
	}
//	printMidList(yMidList, midCount);

	int index2;
	unsigned long midDistance;
// Compare candidate pairs of points in Sy to deltaPair, Record the closest pair of points in deltaPair //
	for(int index1 = 0; index1 < midCount; ++index1) { // Traverse Sy, Compare to either the next 11 points or the rest of the points
		index2 = index1 + 1;
		while (index2 < index1 + 11 && index2 < midCount) {
			midDistance = pow(yMidList[index1]->xValue - yMidList[index2]->xValue, 2) + pow(yMidList[index1]->yValue - yMidList[index2]->yValue, 2);
			if (midDistance < deltaPair->distance) {
              			deltaPair->leftPoint = yMidList[index1]; // address of the point in yList
                 		deltaPair->rightPoint = yMidList[index2]; // address of the point in yList
                  		deltaPair->distance = midDistance;
			}
               		++index2;
            	}
	}
}
// Return closest pair of points from either the base case or recursive case //
	return deltaPair;
}

struct pointPair* findClosestPair(struct originalPoint *list, int nP) {
        struct point *xList = new struct point[nP]; // list of points sorted by x-coordinate
        struct point *yList = new struct point[nP]; // list of points sorted by y-coordinate
         
// Fill in information for xList and yList //
        for (int index = 0; index < nP; ++index) {
                xList[index].xValue = list[index].xValue;
		xList[index].yValue = list[index].yValue;
                yList[index].xValue = list[index].xValue;
		yList[index].yValue = list[index].yValue;
		xList[index].originalIndex = index;
		yList[index].originalIndex = index;
        }

// Sort xList and sort yList //
        sort(xList, xList + nP, xCompare); // sort by x-coordinate
        sort(yList, yList + nP, yCompare); // sort by y-coordinate

// Give yList indices into xList //
	for (int index = 0; index < nP; ++index) {
		list[xList[index].originalIndex].xIndex = index;
	}
	for (int index = 0; index < nP; ++index) {
		yList[index].xIndex = list[yList[index].originalIndex].xIndex;
	}

// Return closest pair of points //
    return findClosestPairRec(xList, yList, 0, nP, nP);
}


