#ifndef LINKEDLISTH
#define LINKEDLISTH

#define FALSE 0
#define TRUE !FALSE

// Frame struct
typedef struct Frame
{
	char* name;
	unsigned int duration;
	char* path;  
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;


/*
this function will change the duration where the name given match a frame
Input:
	ptr to the head
	name of frame
	new duration

Output:
	NONE
*/
void changeDuration(FrameNode** head, char* name, int newDuration);


/*
Function is creating a new frame and returing a pointer to it
input:
	FrameNode* head -  for checking if the name is already in the list

output:
	a pointer to the new frame
	or NULL if the file in path couldnt be opened
*/
FrameNode* createFrame(FrameNode* head);

/*
Function will print a given list
input: the list head
output:
none
*/
void printList(FrameNode* head);


/*
Function will add a node to the end of the list
input:
ptr to the head of the list 
newNode - the node to be added to the list
output:
none
*/
void insertAtEnd(FrameNode** head, FrameNode* newNode);


/**
Function will delete a specific name from the frame list
the function will ask the user to enter a name and then the function will try to remove the name from the list
if the name does not exist no harm will not be done
input:
	pointer to the head of the list
output:
none
*/
void deleteNode(FrameNode** head);


/*
Function will free all memory of a list the list pointer and the list allocated memory like name and path
input:
a pointer to a head of a list
output:
none
*/
void freeListRecursive(FrameNode** head);

/*
this function will calculate the given list length
Input:
	a pointer to a lists head
Output:
	the given list length
*/
int listLength(FrameNode* head);

/*
function will check if the given name is in the list

input: pointer to head of linked list, string of name to search
output: 1 if the name was found else 0
function search for person in line ---- if find return 1 else 0
*/
int nameInList(FrameNode* head, char name[]);

/*
this function will change the doration for all frames in the list
Input:
	ptr to the head of the list
Output:
	none
*/
void changeDurationAll(FrameNode** head);

/*
this function will change a duration for one frame
Input:
	ptr to the head of the list
Output:
	none
*/
void changeDurationOne(FrameNode** head);

/*
Function will change a index of a frame
input:
	pointer to the head of the list
output:
none
*/
void changeFrameIndex(FrameNode** head);

/*
this function handels "saving" the project to file this means to have to write to file the values in the list so we would be able to read from it
Input:
	ptr to head of list
Output:
	none
*/
int saveProjectToFile(FrameNode** head);

/*
this function handels making a list from a file
Input:
	prt to the head of a list
Output:
	returns null if something bad hapend
*/
int createFrameFromFile(FrameNode** head);
#endif
