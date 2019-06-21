#include "editProject.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
this function prints the GUI to the user 
Input:none
Output:none
*/
int editGUI()
{
	int mode = 0;
	printf("What would you like to do?\n[0] Exit\n[1] Add	new Frame\n[2] Remove a Frame\n[3] Change frame index\n[4] Change frame duration\n[5] Change duration of all frames\n[6] List frames\n[7] Play movie!\n[8] Save project\n");
	scanf("%d", &mode);
	getchar();
	while ((mode < 0) || (mode > 8))
	{
		printf("You should type one of the options - 0-8!\n");
		mode = editGUI();
	}
	printf("\n");
	return mode;

}

/*
this function will print the gui of the poject mode to the user like a new project or load an existing one
Input:
Output:
*/
int projectSelectGUI()
{
	int projectMode = -1;
	printf("Welcome to Magshimim Movie Maker! what would you like to do?\n[0] Create a new project\n[1] Load existing project\n");
	while ((projectMode != 1) && (projectMode != 0))
	{
		scanf("%d", &projectMode);
		getchar();
		
	}
	
	return projectMode;
}