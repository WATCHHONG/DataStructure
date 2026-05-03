#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct folderNode {
    char name[30];
    int size;
    struct folderNode *left;
    struct folderNode *right;
} folderNode;

folderNode* makeFolderNode(char *name, int size, folderNode *left, folderNode *right);
int getFolderSize(folderNode *root);
