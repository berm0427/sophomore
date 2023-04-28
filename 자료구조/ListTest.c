#define MAX_LIST_SIZE 100 // 리스트의 최대크기
#include <stdio.h>
typedef int element; //항목 정의

typedef struct ListNode
{
	element data;
	struct ListNode* link;
}ListNode;

ListNode* head = NULL;

ListNode* insert_first(ListNode* head, int value)
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p!= NULL; p = p->link)
	{
		fprintf(stdout,"%d->",p->data);
	}
	printf("NULL \n");
}

int main()
{
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, &i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++)
	{
		head = delete_first(head, i);
		print_list(head);
	}
	return 0;
}
