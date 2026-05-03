#include "traversalBT.h"

int main(void) {
    // A*B-C/D 수식에 대한 이진 트리 구성
    treeNode *n7 = makeRootNode('D', NULL, NULL);
    treeNode *n6 = makeRootNode('C', NULL, NULL);
    treeNode *n5 = makeRootNode('B', NULL, NULL);
    treeNode *n4 = makeRootNode('A', NULL, NULL);
    treeNode *n3 = makeRootNode('/', n6, n7);
    treeNode *n2 = makeRootNode('*', n4, n5);
    treeNode *n1 = makeRootNode('-', n2, n3);

    printf("전위 순회: ");
    preorderTraversal(n1);
    printf("\n");

    printf("중위 순회: ");
    inorderTraversal(n1);
    printf("\n");

    printf("후위 순회: ");
    postorderTraversal(n1);
    printf("\n");

    return 0;
}
