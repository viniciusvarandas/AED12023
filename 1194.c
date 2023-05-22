#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* buildTree(char* preorder, char* inorder, int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return node;

    int inIndex;
    for (inIndex = start; inIndex <= end; inIndex++) {
        if (inorder[inIndex] == node->value)
            break;
    }

    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

void postorderTraversal(Node* node) {
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%c", node->value);
}

void freeTree(Node* node) {
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    int numCases;
    scanf("%d", &numCases);

    for (int i = 0; i < numCases; i++) {
        int numNodes;
        scanf("%d", &numNodes);

        char preorder[53];
        char inorder[53];
        scanf("%s %s", preorder, inorder);

        int preIndex = 0;
        Node* root = buildTree(preorder, inorder, 0, numNodes - 1, &preIndex);

        postorderTraversal(root);
        printf("\n");

        freeTree(root);
    }

    return 0;
}