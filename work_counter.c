#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <math.h>

int main()
{
	double workingTime = 0;
	double* ID;

	printf("Welcome to the Code Hawkins Time Counter\n");
	sleep(2);

	printf("Please input your worker ID: ");
	scanf("%d", &ID);
	printf("Type start to start the timer, pause to pause the timer, stop to stop the timer and check to check worked hours: ");

	char* command = "";

	scanf("%s", &command);
		
	if (strcmp(&command, "start") == 0)
	{
		workingTime = Timer();
	}

	printf("Worker ID: %d\n", ID);
	printf("Please store this time with a screen capture in the Google Sheets File \n");

}

int Timer()
{
	time_t startTime, endTime, deltaTime, totalTime;
	char* command = "";
	totalTime = 0;


	system("clear");

	printf("The timer has started!\n");
	
	bool shouldRun = true;
	
	startTime = time(NULL);
	
	bool repeatPause = true;
	bool repeatResume = false;

	while (shouldRun == true)
	{
		printf("Command: ");
		scanf("%s", &command);

		system("clear");
		printf ("Debug output: %s\n", &command);

		if (strcmp(&command, "pause") == 0 && repeatPause == true)
		{
			printf("Pause timer command\n");
			endTime = time(NULL);
			deltaTime = endTime - startTime;
			totalTime += deltaTime;
			printf("Your current time is: %ld h, %ld mins and %ld sec\n", (totalTime/3600), (totalTime/60), totalTime);
			printf("The timer has been paused, type start to resume: \n");
			startTime = time(NULL);
			repeatPause = false;
			repeatResume = true;

		}
		else if (strcmp(&command, "stop") == 0)
		{
			printf("Stop timer command\n");
			endTime = time(NULL);
			deltaTime = endTime - startTime;
			totalTime += deltaTime;
			printf("You worked %d h, %d mins and %d secs \n", totalTime/3600, totalTime/60, totalTime);
			return totalTime;
			shouldRun = false;
		}
		else if (strcmp(&command, "start") == 0 && repeatResume == true)
		{
			printf("Resume timer command \n");
			startTime = time(NULL);
			repeatResume = false;
			repeatPause = true;
		}
	}
}

	
