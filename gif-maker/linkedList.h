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


void changeDuration(FrameNode** head, char* name, int newDuration);
FrameNode* createFrame(FrameNode* head);
void printList(FrameNode* head);
void insertAtEnd(FrameNode** head, FrameNode* newNode);
void deleteNode(FrameNode** head);
void freeListRecursive(FrameNode** head);
int listLength(FrameNode* head);
int nameInList(FrameNode* head, char name[]);
void changeDurationAll(FrameNode** head);
void changeDurationOne(FrameNode** head);
void changeFrameIndex(FrameNode** head);
#endif
