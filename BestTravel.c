#include "BestTravel.h"

int chooseBestSum(int maxDistance, int maxNumberOfCities, int distances[], int distancesSize) {
    int maxSum = -1;
	int indexes[maxNumberOfCities];

	travelInfo info = fillTravelInfo(maxDistance, maxNumberOfCities, distances, distancesSize);
    fillWithFirstIndexes(indexes, maxNumberOfCities);
    chooseMaxPossibleSum(info, indexes, &maxSum);

    return maxSum;
}

travelInfo fillTravelInfo(int maxDistance, int maxNumberOfCities, int distances[], int distancesSize) {
	travelInfo info;

	info.maxDistance = maxDistance;
	info.maxNumberOfCities = maxNumberOfCities;
	info.distances = distances;
	info.distancesSize = distancesSize;

	return info;
}

void fillWithFirstIndexes(int indexes[], int maxNumberOfCities) {
    for (int i = 0; i < maxNumberOfCities; ++i)
        indexes[i] = i;
}

void chooseMaxPossibleSum(travelInfo info, int indexes[], int *maxSum) {
    while (isLastIndexWithinBoundaries(indexes, info)) {
        int tempSum = calculateSumWithCurrentIndexes(indexes, info);
        if (isSumABetterFit(tempSum, *maxSum, info.maxDistance))
           *maxSum = tempSum;
        updateIndexes(indexes, info);
    }
}

int isLastIndexWithinBoundaries(int indexes[], travelInfo info) {
	return indexes[info.maxNumberOfCities - 1] < info.distancesSize;
}

int calculateSumWithCurrentIndexes(int indexes[], travelInfo info) {
    int tempSum = 0;
    for (int i = 0; i < info.maxNumberOfCities; ++i)
        tempSum += info.distances[indexes[i]];
    return tempSum;
}

int isSumABetterFit(int tempSum, int maxSum, int maxDistance) {
    return (tempSum <= maxDistance && maxSum < tempSum);
}

void updateIndexes(int indexes[], travelInfo info) {
    int i = info.maxNumberOfCities - 1;

    while (i > 0 && indexes[i] == info.distancesSize + i - info.maxNumberOfCities)
        --i;
    for (++indexes[i], i++; i < info.maxNumberOfCities; ++i)
        indexes[i] = indexes[i - 1] + 1;
}

