#include "folderSize.h"

folderNode* makeFolderNode(char *name, int size, folderNode *left, folderNode *right) {
    folderNode *node = (folderNode *)malloc(sizeof(folderNode));
    strncpy(node->name, name, sizeof(node->name) - 1);
    node->name[sizeof(node->name) - 1] = '\0';
    node->size = size;
    node->left = left;
    node->right = right;
    return node;
}

// 후위 순회로 폴더 전체 용량 계산
int getFolderSize(folderNode *root) {
    if (root == NULL) return 0;

    int leftSize = getFolderSize(root->left);
    int rightSize = getFolderSize(root->right);
    int totalSize = root->size + leftSize + rightSize;

    printf("[%s] 전체 용량 = %dMB\n", root->name, totalSize);
    return totalSize;
}
