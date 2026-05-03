#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
    element data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode* makeRootNode(element data, treeNode *leftNode, treeNode *rightNode);
void preorderTraversal(treeNode *root);
void inorderTraversal(treeNode *root);
void postorderTraversal(treeNode *root);
