#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "view.h"
#include "linkedList.h"
#include "editProject.h"
#define SIZE_OF_NAME 100

int main(void)
{
	int editMode = -1;
	int projectMode = projectSelectGUI();
	char frameName[SIZE_OF_NAME] = { 0 };
	int newDuration = 0;

	FrameNode* frameList = NULL;
	FrameNode* newFrame = NULL;
	
	while (editMode != 0)
	{
		editMode = editGUI();

		switch (editMode)
		{

		case 0:
			printf("Bye!\n");
			break;

		case 1:

			newFrame = createFrame(frameList);

			if (newFrame != NULL)
			{
				insertAtEnd(&frameList, newFrame);
				printf("added!\n");
				printList(frameList);
			}
			break;

		case 2:
			printf("Enter the name of the frame you wish to erase\n");
			fgets(frameName, SIZE_OF_NAME, stdin);
			frameName[strcspn(frameName, "\n")] = '\0'; // Getting rid of \n

			if (!nameInList(frameList, frameName))
			{
				printf("The frame was not found");
			}
			else
			{
				deleteNode(&frameList, frameName);
			}
			break;


		case 3:
			//needs to add a function for changing the index of a frame
			break;


		case 4:
			printf("enter the name of the frame\n");
			fgets(frameName, SIZE_OF_NAME, stdin);
			frameName[strcspn(frameName, "\n")] = '\0'; // Getting rid of \n
			printf("Enter the new duration\n");
			scanf("%d", &newDuration);
			getchar();

			changeDuration(&frameList , frameName , newDuration);
			
			break;
		
		case 5:


			break;

		case 6:

			printList(frameList);
			break;
		}

		
	}

	
	
	getchar();
	return 0;
}


