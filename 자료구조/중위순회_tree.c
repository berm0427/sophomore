#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode
{
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->key)
	{
		root->left = delete_node(root->left, key);
	}

	else if (key > root->key)
	{
		root->right = delete_node(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}

	return root;
}
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	//트리가 공백이면 새로운 노드 반환
	if (node == NULL) return new_node(key);

	//그렇지 않으면 순환적으로 트리를 내려간다.
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	//변경된 루트 포인터를 반환
	return node;
}
void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

int main()
{
	TreeNode* root = NULL;
	TreeNode* temp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	printf("\n");
	if (search(root, 30) != NULL)
	{
		printf("이진 탐색 트리에서 30을 발견함\n");

	}
	else
	{
		printf("이진 탐색 트리에서 30을 발견못함\n");
	}
}
