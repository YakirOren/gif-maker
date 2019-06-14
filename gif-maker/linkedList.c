#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_NAME 100
#define SIZE_OF_PATH 100



/*
function will check if the given name is in the list

input: pointer to head of linked list, string of name to search
output: 1 if the name was found else 0
function search for person in line ---- if find return 1 else 0
*/
int nameInList(FrameNode* head, char name[])
{
	int found = FALSE;
	if (head != NULL)
	{
		if (strcmp(name, head->frame->name) == 0)
		{
			found = TRUE;
		}
		else if (head->next != NULL)
		{
			found = searchPerson(head->frame->name, name);
		}
		else
		{
			found = FALSE;
		}
	}
	return found;

}


/*
Function is creating a new frame and returing a pointer to it
input:
	FrameNode* head -  for checking if the name is already in the list

output:
	a pointer to the new frame
	or NULL if the file in path couldnt be opened
*/
FrameNode* createFrame(FrameNode* head)
{
	FrameNode* newFrame = (FrameNode*)malloc(sizeof(FrameNode)); //creating a pointer to FrameNode 
	char name[SIZE_OF_NAME] = { 0 };
	int duration = 0;
	char path[SIZE_OF_PATH] = { 0 };

	
	printf("*** Creating new frame ***\NPlease insert frame path:\n");//asking the user for the path of the frame
	fgets(path, SIZE_OF_PATH, stdin);
	path[strcspn(path, "\n")] = '\0'; // Getting rid of \n
	
	FILE* path_file = fopen(path, "r");
	if (path_file != NULL)
	{
		fclose(path_file);
		newFrame->frame->path = (char*)malloc(sizeof(char) * strlen(path)); // dynamicly allocating memory for the path in the new frame
		if (newFrame->frame->path == NULL)
		{
			printf("Error! Unable to allocate memory!!\n");
			return NULL;
		}

		strcpy(newFrame->frame->path, path); // copying the given path to the new frame		

	}
	else
	{
		fclose(path_file);
		free(newFrame);
		newFrame = NULL; //if the the file in the given path can be opened we free the allocated memory and assign the newFrame to NULL 
	}
	


	printf("Please insert frame duration(in miliseconds):\n");//asking the user for duration of the frame 
	scanf("%d", &duration);
	getchar();	
	if (newFrame != NULL)
	{
		newFrame->frame->duration = duration; // copying the given duration to the new frame
	}
	
	

	printf("Please choose a name for that frame:\n"); //asking the user for a frame name
	fgets(name, SIZE_OF_NAME, stdin);
	name[strcspn(name, "\n")] = '\0'; // Getting rid of \n

	if ((newFrame != NULL))
	{

		while (nameInList(head , name))
		{
			printf("The name is already taken, please enter another name\n"); //asking the user for a frame name
			fgets(name, SIZE_OF_NAME, stdin);
			name[strcspn(name, "\n")] = '\0'; // Getting rid of \n
		}

		if (!(nameInList(head , name)))
		{
			newFrame->frame->name = (char*)malloc(sizeof(char) * strlen(name)); // dynamicly allocating memory for the name in the new frame

			if (newFrame->frame->name == NULL)
			{
				printf("Error! Unable to allocate memory!!\n");
				return NULL;
			}

			strcpy(newFrame->frame->name, name); // copying the given name to the new frame		
		}

		newFrame->next = NULL; // the next field in our new pointer is null
	}

	
	if (newFrame == NULL)
	{
		printf("Can't find file! Frame will not be added");
	}
	
	return newFrame; //returning the a pointer to the new frame or NULL if the file in path couldnt be opened
}


/*
Function will print a given list
input: the list head
output:
none
*/
void printList(FrameNode* head)
{
	FrameNode* curr = head;

	printf("                Name            Duration        Path");
	while (curr) // when curr == NULL, that is the end of the list, and loop will end (NULL is false)
	{
		printf("                %s               %d ms          %s", curr->frame->name, curr->frame->duration , curr->frame->path);
		curr = curr->next;
	}

}


/*
Function will free all memory of a list the list pointer and the list allocated memory like name and path 
input:
a pointer to a head of a list
output:
none
*/
void freeListRecursive(FrameNode** head)
{
	if (*head != NULL) // if list not empty
	{
		if ((*head)->next != NULL) // end condition
		{
			freeListRecursive(&((*head)->next));
		}
		
		free((*head)->frame->name); //freeing the name field
		free((*head)->frame->path); // freeing the path field
		free(*head); // after freeing the other allocated 

	}
}


/*
Function will add a person to the list
input:
firstNode - the first node of the lisr
newNode - the new person to add to the list
output:
none
*/
void insertAtEnd(FrameNode** head, FrameNode* newNode)
{
	FrameNode* curr = *head;
	if (!*head) // empty list!
	{
		*head = newNode;
	}
	else
	{
		while (curr->next) // while the next is NOT NULL (when next is NULL - that is the last node)
		{
			curr = curr->next;
		}

		curr->next = newNode;
		newNode->next = NULL;
	}
}

/**
Function will delete a specific person from a list of persons
input:
the list (the first person), the person to delete
output:
none
*/
void deleteNode(FrameNode** head, char* name)
{
	FrameNode* curr = *head;
	FrameNode* temp = NULL;

	// if the list is not empty (if list is empty - nothing to delete!)
	if (*head)
	{
		// the first node should be deleted?
		if (0 == strcmp((*head)->frame->name, name))
		{
			*head = (*head)->next;
			free(curr);
		}
		else
		{
			while (curr)
			{
				if ((0 == strcmp(curr->next->frame->name, name))) // waiting to be on the node BEFORE the one we want to delete
				{
					temp = curr->next; // put aside the node to delete
					curr->next = temp->next; // link the node before it, to the node after it

					free(temp->frame->name); // free the allocated name 
					free(temp->frame->path); // free the allocated path
					free(temp); // delete the node

				}
				else
				{
					curr = curr->next;
				}
			}
		}
	}
}

/*
this function will calculate the given list length
Input:
	a pointer to a lists head
Output:
	the given list length
*/
int listLength(FrameNode* head)
{
	if (head == NULL)
	{
		return 0;
	}
	return (1 + listLength(head->next));
}
