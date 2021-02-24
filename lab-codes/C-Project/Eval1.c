//Muhammad Abdullah, 2015-EE-166

#include <stdio.h>

struct time
{
	int hours;
	int minutes;
	int seconds;
};

void printTime(struct time* currTime)
{
	printf("Time is (hh:mm:ss): %d:%d:%d\n", currTime->hours, currTime->minutes, currTime->seconds);
}

void updateTime(struct time* currTime, const struct time timeToAdd)
{
	int additionalTime, currentTime, newTime;
	additionalTime = timeToAdd.seconds + (timeToAdd.minutes * 60) + (timeToAdd.hours * 3600);
	currentTime = currTime->seconds + (currTime->minutes * 60) + (currTime->hours * 3600);
	newTime = currentTime + additionalTime;
	currTime->hours = newTime / 3600;
	currTime->minutes = (newTime % currTime->hours) / 60;
	currTime->seconds = (newTime % currTime->minutes);
}

struct time maxTime(struct time* arrayTime, int size)
{
	int i, j;
	int largest = 0;
	int index = 0;

	int secondsArray[size];

	for(i = 0; i < size; i++)
	{
		secondsArray[i] = arrayTime[i].seconds + (arrayTime[i].minutes * 60) + (arrayTime[i].hours * 3600);
	}

	largest = secondsArray[0];

	for(j = 0; j < size; j++)
	{
		if(secondsArray[j] > largest)
		{
			largest = secondsArray[j];
			index = j;
		}
	}

	return arrayTime[index];
}

int main(void)
{
	struct time Time1 = {12, 24, 36};
	struct time Time2 = {1, 2, 3};

	printf("Time1:\n");
	printTime(&Time1);
	printf("Time2:\n");
	printTime(&Time2);

	updateTime(&Time1, Time2);
	printf("New Time1:\n");
	printTime(&Time1);

	struct time TimeM;
	struct time TimeArr[] = {Time1, Time2};

	TimeM = maxTime(TimeArr, 2);

	printf("Max Time:\n");
	printTime(&TimeM);

	return 0;
}
