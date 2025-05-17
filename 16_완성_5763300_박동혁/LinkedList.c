#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList_h* createList(void) {
	LinkedList_h* list = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	if (list != NULL) {
		list->head = NULL;
	}
	return list;
}

void destroyList(LinkedList_h* list) {
	ListNode* cur = list->head;
	while (cur != NULL) {
		ListNode* tmp = cur;
		cur = cur->link;
		free(tmp);
	}
	list->head = NULL;
	free(list);
}

int PrintList(LinkedList_h* list) {
	ListNode* cur = list->head;
	int count = 0;

	while (cur != NULL) {
		count++;
		cur = cur->link;
	}

	if (count == 0) {
		printf("리스트가 비었습니다.\n");
		return 0;
	}

	printf("Linked List(%d): ", count);

	cur = list->head;
	while (cur != NULL) {
		printf("[%d]", cur->data);
		cur = cur->link;
	}
	printf("\n");
	return count;
}



void insertFirst(LinkedList_h* list, elementType data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->link = list->head;
	list->head = newNode;
}

void insertLast(LinkedList_h* list, elementType data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->link = NULL;
	if (list->head == NULL) {
		list->head = newNode;
		return;
	}
	ListNode* cur = list->head;
	while (cur->link != NULL) {
		cur = cur->link;
	}
	cur->link = newNode;
}

void insertMiddle(LinkedList_h* lsit, elementType data, ListNode* pre) {
	ListNode* cur = lsit->head;
	while (cur != NULL && cur->data != pre)
		cur = cur->link;
	if (cur == NULL) {
		printf("해당 값이 없습니다.\n");
		return;
	}
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->link = cur->link;
	cur->link = newNode;
}

void insertNthNode(LinkedList_h* lsit, int loc, elementType item) {
	if (loc <= 1) {
		insertFirst(lsit, item);
		return;
	}
	ListNode* cur = lsit->head;
	for (int i = 1; i < loc - 1 && cur != NULL; i++) {
		cur = cur->link;
	}
	if (cur == NULL) {
		printf("해당 위치에 삽입할 수 없습니다.\n");
		return;
	}
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = item;
	newNode->link = cur->link;
	cur->link = newNode;
}
void deleteNode(LinkedList_h* list, int data) {
	ListNode* cur = list->head, * prev = NULL;
	while (cur != NULL && cur->data != data) {
		prev = cur;
		cur = cur->link;
	}
	if (cur == NULL) {
		printf("해당 값이 없습니다.\n");
		return;
	}
	if (prev == NULL)
		list->head = cur->link;
	else
		prev->link = cur->link;
	free(cur);
	cur = NULL;
	printf("삭제 완료!\n");
}


void printHeadTail(LinkedList_h* list) {
	if (list->head == NULL) {
		printf("리스트가 비었습니다.\n");
		return;
	}
	ListNode* cur = list->head;
	while (cur->link != NULL)
		cur = cur->link;
	printf("Head: %d, Tail: %d\n", list->head->data, cur->data);
}