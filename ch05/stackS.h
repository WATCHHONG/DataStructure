#pragma once
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;

extern element stack[STACK_SIZE];
extern int top;

int isStackEmpty();
int isStackFull();
void push(element item);
element pop();
element peek();
void printStack();
