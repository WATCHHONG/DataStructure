#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InsertLinkedList.h"

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;  // 공백 리스트이므로 NULL로 설정
    return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = L->head;
    L->head = newNode;
}

// 노드 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (L->head == NULL) {
        newNode->link = NULL;
        L->head = newNode;
    }
    else if (pre == NULL) {
        newNode->link = L->head;
        L->head = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    temp = L->head;
    while (temp->link != NULL) temp = temp->link;
    temp->link = newNode;
}
