

void printXList(struct point *xList, int startIndex, int size) { // prints out points in the x-list, used for debugging
	outputStream << "pX(Lx) is :\n";
	for (int index = startIndex; index < startIndex + size; ++index) {
		outputStream << xList[index].originalIndex + 1 << ": " << xList[index].xValue << " " << xList[index].yValue << "\n";
	}
	outputStream << "\n";
}

void printYList(struct point *yList, int startIndex, int size, int nP) { // prints out points in the y-list, used for debugging
	outputStream << "pY(Ly) is :\n";
	for (int index = 0; index < nP; ++index) {
		if (yList[index].xIndex >= startIndex && yList[index].xIndex < startIndex + size) {
			outputStream << yList[index].originalIndex + 1 << ": " << yList[index].xValue << " " << yList[index].yValue << "\n";
		}
	}
	outputStream << "\n";
}

void printMidList(struct point **midList, int midCount) { // prints out points in Sy
	outputStream << "Ly_strip:\n";
	for (int index = 0; index < midCount; ++index) {
		outputStream << midList[index]->originalIndex + 1 << ": " << midList[index]->xValue << " " << midList[index]->yValue << "\n";
	}
	outputStream << "\n";
}

/*
void printYListXIndices(struct point *yList, int startIndex, int size, int nP) { // for personal use for debugging
	outputStream << "Ly x indices:\n";
	for (int index = 0; index < nP; ++index) {
		if (yList[index].xIndex >= startIndex && yList[index].xIndex < startIndex + size) {
			outputStream << yList[index].xIndex << "\n";
		}
	}
	outputStream << "\n";
}
*/
