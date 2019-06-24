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
	int frameIndex = 0;


	FrameNode* frameList = NULL;
	FrameNode* newFrame = NULL;
	
		while (editMode != 0)
		{
			if (projectMode == 0)
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

					changeFrameIndex(&frameList);


					break;


				case CHANGE_DURATION:
					changeDurationOne(&frameList);
			
					break;
		
				case CHANGE_DURATION_ALL:

					changeDurationAll(&frameList);

					break;

				case LIST_FRAMES:

					printList(frameList);
					break;


				case PLAY_LIST:
			
					play(frameList);
					break;

				case SAVE_PROJECT:
					saveProjectToFile(&frameList);
					break;
		

				default:
					printf("bye!");
					break;

				}

		
			}
			else
			{
				if (!createFrameFromFile(&frameList))
				{
					projectMode = 0;
				}
				else
				{
					projectMode = 1;
				}
				
			}

		}

	
	freeListRecursive(&frameList);
	getchar();
	return 0;
}


