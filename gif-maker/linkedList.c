#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
Function is creating a new frame and returing a pointer to it
input:
	name of frame
	duration of frame
	path of frame
output:
	a pointer to the new frame
*/
FrameNode* createFrame(char name[], int duration , char path[])
{
	FrameNode* newFrame = (FrameNode*)malloc(sizeof(FrameNode)); //creating a pointer to FrameNode 

	newFrame->frame->name = (char*)malloc(sizeof(char) * strlen(name)); // dynamicly allocating memory for the name in the new frame

	if (newFrame->frame->name == NULL)
	{
		printf("Error! Unable to allocate memory!!\n");
		return 1;
	}

	//needs to add a function to free the name field    free(newFrame->frame->name);


	strcpy(newFrame->frame->name, name); // copying the given name to the new frame
	newFrame->frame->duration = duration; // copying the given duration to the new frame

	newFrame->frame->path = (char*)malloc(sizeof(char) * strlen(path)); // dynamicly allocating memory for the path in the new frame
	if (newFrame->frame->path == NULL)
	{
		printf("Error! Unable to allocate memory!!\n");
		return 1;
	}

	//needs to add a function to free the path field  free(newFrame->frame->path);

	strcpy(newFrame->frame->path, path); // copying the given path to the new frame

	newFrame->next = NULL; // the next field in our new pointer is null
	

	return newFrame; //returning the a pointer to the new frame
}


/*
Function will print a list of songs
input: the list (the first person)
output:
none
*/
void printList(FrameNode* head)
{
	FrameNode* curr = head;

	while (curr) // when curr == NULL, that is the end of the list, and loop will end (NULL is false)
	{
		printf("Name: %s, duration: %d\n", curr->frame->name, curr->frame->duration);
		curr = curr->next;
	}

}


/*
Function will free all memory of a list of songs - RECURSIVELY!
input:
a list of songs
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
		if (0 == strcmp((*head)->name, name))
		{
			*head = (*head)->next;
			free(curr);
		}
		else
		{
			while (curr)
			{
				if ((0 == strcmp(curr->next->name, name))) // waiting to be on the node BEFORE the one we want to delete
				{
					temp = curr->next; // put aside the node to delete
					curr->next = temp->next; // link the node before it, to the node after it
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

int listLength(FrameNode* head)
{
	if (head == NULL)
	{
		return 0;
	}
	return (1 + listLength(head->next));
}

FrameNode* copyList(FrameNode* head)
{
	FrameNode* newHead = NULL;
	FrameNode* curr = head;
	FrameNode* newNode = NULL;
	int i = 0;

	for (i = 0; i < listLength(head); i++)
	{
		newNode = createPerson(curr->name, curr->age);

		insertAtEnd(&newHead, newNode);
		curr = curr->next;

	}


	return newHead;
}