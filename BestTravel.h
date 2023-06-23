#pragma once

typedef struct travelInfo {
	int maxDistance;
	int maxNumberOfCities;
	int *distances;
	int distancesSize;
} travelInfo;

void fillWithFirstIndexes(int indexes[], int maxNumberOfCities);
travelInfo fillTravelInfo(int maxDistance, int maxNumberOfCities, int distances[], int distancesSize);
void chooseMaxPossibleSum(travelInfo info, int indexes[], int *maxSum);
int isLastIndexWithinBoundaries(int indexes[], travelInfo info);
int calculateSumWithCurrentIndexes(int indexes[], travelInfo info);
int isSumABetterFit(int tempSum, int maxSum, int maxDistance);
void updateIndexes(int indexes[], travelInfo info);
