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


FrameNode* createFrame(char name[], int duration, char path[]);
void printList(FrameNode* head);
void insertAtEnd(FrameNode** head, FrameNode* newNode);
void deleteNode(FrameNode** head, char* name);
void freeListRecursive(FrameNode** head);
int listLength(FrameNode* head);


#endif
