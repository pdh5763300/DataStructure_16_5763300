#pragma once
typedef int elementType;

typedef struct ListNode {
	elementType data;
	struct ListNode* link;
} ListNode;

typedef struct LinkedList {
	ListNode* head;
	ListNode* tail;
	int follow;
} LinkedList_h;

LinkedList_h* createList(void);
int PrintList(LinkedList_h* list);
void destroyList(LinkedList_h* list);

extern void insertFirst(LinkedList_h* list, elementType data);
extern void insertLast(LinkedList_h* list, elementType data);
extern void insertMiddle(LinkedList_h* lsit, elementType data, ListNode* pre);
extern void insertNthNode(LinkedList_h* lsit, int loc, elementType item);
extern void deleteNode(LinkedList_h* list, ListNode* p);
extern void printHeadTail(LinkedList_h* lsit);
extern void freeList(LinkedList_h* list); 
