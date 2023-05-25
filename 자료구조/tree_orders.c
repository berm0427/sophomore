#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct TreeNode
{
    element key;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* createNode(element key)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(TreeNode* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("[%c] ", root->key);
        inorder(root->right);
    }
}

void preorder(TreeNode* root)
{
    if (root != NULL)
    {
        printf("[%c] ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("[%c] ", root->key);
    }
}

int main()
{
    TreeNode* root = createNode('+');
    root->left = createNode('*');
    root->right = createNode('E');
    root->left->left = createNode('*');
    root->left->right = createNode('D');
    root->left->left->left = createNode('/');
    root->left->left->right = createNode('C');
    root->left->left->left->left = createNode('A');
    root->left->left->left->right = createNode('B');

    printf("이진 탐색 트리 중위 순회 결과\n");
    inorder(root);
    printf("\n");

    printf("이진 탐색 트리 전위 순회 결과\n");
    preorder(root);
    printf("\n");

    printf("이진 탐색 트리 후위 순회 결과\n");
    postorder(root);
    printf("\n");

    return 0;
}
