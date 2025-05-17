#include <stdio.h>
#include "linkedlist.h"

int main() {
    LinkedList_h* list = createList();
    int menu, data, prev, n;

    while (1) {
        printf("==== Linked_List Menu =====\n");
        printf("1) insertFirst  (리스트의 제일 앞에 삽입)\n");
        printf("2) insertLast   (리스트의 제일 뒤에 삽입)\n");
        printf("3) insertMiddle (특정 값 뒤에 삽입)\n");
        printf("4) insertNthNode(N번째 위치에 삽입)\n");
        printf("6) deleteNode   (특정 값 삭제)\n");
        printf("7) printHead/Tail(첫/마지막 노드)\n");
        printf("0) Program Stop\n");
        printf("Select menu ▶ ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            printf("삽입할 값 입력: ");
            scanf_s("%d", &data);
            insertFirst(list, data);
            PrintList(list);
            break;
        case 2:
            printf("삽입할 값 입력: ");
            scanf_s("%d", &data);
            insertLast(list, data);
            PrintList(list);
            break;
        case 3:
            printf("앞에 올 값 입력: ");
            scanf_s("%d", &prev);
            printf("삽입할 값 입력: ");
            scanf_s("%d", &data);
            insertMiddle(list, prev, data);
            PrintList(list);
            break;
        case 4:
            printf("삽입할 위치(N) 입력: ");
            scanf_s("%d", &n);
            printf("삽입할 값 입력: ");
            scanf_s("%d", &data);
            insertNthNode(list, n, data);
            PrintList(list);
            break;
        case 6:
            printf("삭제할 값 입력: ");
            scanf_s("%d", &data);
            deleteNode(list, data);
            PrintList(list);
            break;
        case 7:
            printHeadTail(list);
            break;
        case 0:
            printf("프로그램 종료\n");
            destroyList(list);
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
        }
        printf("\n");
    }
    return 0;
}
