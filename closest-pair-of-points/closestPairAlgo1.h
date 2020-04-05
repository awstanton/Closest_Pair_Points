


struct simplePair* closestPair1(int *Lx, int *Ly, struct simplePair *pair1, int nP) {	
	unsigned long minDistance = pow(Lx[0] - Lx[1], 2) + pow(Ly[0] - Ly[1], 2); // distance between first two points
	int minIndex1 = 0; // index of first point
	int minIndex2 = 1; // index of second point
	unsigned long newDistance; // used in comparison with the minDistance

// Get distance between first point and all other points //
	for (int index = 1; index < nP; ++index) {
		newDistance = pow(Lx[0] - Lx[index], 2) + pow(Ly[0] - Ly[index], 2);
		if (newDistance < minDistance) {
			minDistance = newDistance;
			// minIndex1 does not change
			minIndex2 = index;		
		}
	}

// Get distance between each point other than the first point and all other points other than the first point //	
	for (int index1 = 1; index1 < nP - 1; ++index1) {
		
		for (int index2 = index1 + 1; index2 < nP; ++index2) {	
			newDistance = pow(Lx[index1] - Lx[index2], 2) + pow(Ly[index1] - Ly[index2], 2);
			if (newDistance < minDistance) {
				minDistance = newDistance;
				minIndex1 = index1;
				minIndex2 = index2;
			}
		}
		
	}

// Fill in information about the closest pair of points and return the closest pair of points	
	pair1 = new struct simplePair();
	pair1->index1 = minIndex1;
	pair1->index2 = minIndex2;
	pair1->distance = minDistance;
	
	return pair1;
}

