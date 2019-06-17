#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "view.h"
#include "linkedList.h"
#include "editProject.h"
#define SIZE_OF_NAME 100

#define EXIT 0 
#define NEW_FRAME 1
#define REMOVE_FRAME 2 
#define CHANGE_INDEX 3
#define CHANGE_DURATION 4
#define CHANGE_DURATION_ALL 5
#define LIST_FRAMES 6
#define PLAY_LIST 7
#define SAVE_PROJECT 8

int main(void)
{
	int editMode = -1;
	int projectMode = projectSelectGUI();
	int newDuration = 0;
	char frameName[SIZE_OF_NAME] = { 0 };

	FrameNode* frameList = NULL;
	FrameNode* newFrame = NULL;
	
	while (editMode != 0)
	{
		editMode = editGUI();

		switch (editMode)
		{

		case EXIT:
			printf("Bye!\n");
			break;

		case NEW_FRAME:

			newFrame = createFrame(frameList);

			if (newFrame != NULL)
			{
				insertAtEnd(&frameList, newFrame);
				printf("added!\n");
			}
			break;

		case REMOVE_FRAME:
			deleteNode(&frameList);
			
			break;


		case CHANGE_INDEX:
			//needs to add a function for changing the index of a frame
			break;


		case CHANGE_DURATION:
			printf("enter the name of the frame\n");
			fgets(frameName, SIZE_OF_NAME, stdin);
			frameName[strcspn(frameName, "\n")] = '\0'; // Getting rid of \n
			printf("Enter the new duration\n");
			scanf("%d", &newDuration);
			getchar();

			changeDuration(&frameList , frameName , newDuration);
			
			break;
		
		case CHANGE_DURATION_ALL:

			

			break;

		case LIST_FRAMES:

			printList(frameList);
			break;


		case PLAY_LIST:
			
			play(frameList);
			break;

		case SAVE_PROJECT:

			break;


		default:
			printf("bye!");
			break;

		}

		
	}

	
	freeListRecursive(&frameList);
	getchar();
	return 0;
}


