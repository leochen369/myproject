#include<stdio.h>
#include<stdlib.h>

#define ISSUE 5
#define RATINGS 10

void recordresponse(int issue, int ratings);
void highestratings();
void lowestratings();
float averagerating();
void displayresult();
int responses[ISSUE][RATINGS];
const char *topic[ISSUE] = { "global warming ","the economy",
                             "war","health care","education" };
int main() {
	int response, i;
	do
	{
		printf("please rate the following topic on a scale from 1-10""\n 1 = least important,10 = most importnat\n");
		for (i = 0; i < ISSUE; i++)
		{
			do {
				printf("%s?", topic[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordresponse(i, response);
		}
		printf("enter 1 to stop.enter 0 to rate the issue again.");
		scanf_s("%d", &response);
	} while (response != 1);
	displayresult();
	system("pause");
	return 0;
}
void recordresponse(int issue, int ratings)
{
	responses[issue][ratings - 1]++;
}
void highestratings()
{
	int highrating = 0;
	int hightopic = 0;
	int i, j;
	for (i = 0; i < ISSUE; i++)
	{
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++)
		{
			topicrating += responses[i][j] * (j + 1);
		}
		if (highrating < topicrating)
		{
			highrating = topicrating;
			hightopic = i;

		}
	}
	printf("the highest rated topic was");
	printf("%s", topic[hightopic]);
	printf("with a total rating of %d\n ", highrating);
}
void lowestratings()
{
	int lowrating = 0;
	int lowtopic = 0;
	int i, j;
	for (i = 0; i < ISSUE; i++)
	{
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++)
		{
			topicrating += responses[i][j] * (j + 1);
		}
		if (i == 0)
		{
			lowrating = topicrating;
		}
		if (lowrating > topicrating)
		{
			lowrating = topicrating;
			lowrating = i;
		}
		
	}
	printf("the lowest rated topic was");
	printf("%s", topic[lowtopic]);
	printf("with a total rating of %d\n ", lowrating);
}
float averagerating(int issue)
{
	float total = 0;
	int counter = 0;
	int i;
	for (i = 0; i < RATINGS; i++)
	{
		if (responses[issue][i] != 0)
		{
			total += responses[issue][i] * (i + 1);
			counter += responses[issue][i];
		}
	}
	return total / counter;
}
void displayresult()
{
	int i, j;
	printf("%20s","TOPIC");
	for (i = 1; i <= RATINGS; i++)
	{
		printf("%4d", i);
	}
		printf("%20s", "average rating");
	for (i = 0; i <= ISSUE; i++)
	{
		printf("%20s",topic[i]);
		
		for (j = 0; j < RATINGS; j++)
		{
			printf("%4d", responses[i][j]);
		}
		printf("%20.2f", averagerating(i));
	}
	highestratings();
	lowestratings();
}