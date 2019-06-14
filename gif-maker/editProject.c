#include "editProject.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
this function prints the GUI to the user 
Input:none
Output:none
*/
void printGUI()
{
	printf("What would you like to do?\n[0] Exit\n[1] Add	new Frame\n[2] Remove a Frame\n[3] Change frame index\n[4] Change frame duration\n[5] Change duration of all frames\n[6] List frames\n[7] Play movie!\n[8] Save project\n");
}

int projectSelectGUI()
{
	int projectMode = -1;
	printf("Welcome to Magshimim Movie Maker! what would you like to do?\n[0] Create a new project\n[1] Load existing project\n");
	while ((projectMode != 1 )|| (projectMode != 0))
	{
		scanf("%d", &projectMode);
		getchar();
	}
	return projectMode;
}