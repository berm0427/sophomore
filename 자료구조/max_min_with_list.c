#define MAX_LIST_SIZE 100 // 리스트의 최대크기
#include <stdio.h>
#include <stdlib.h>

typedef int element; //항목 정의

typedef struct ListNode
{
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
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
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete_node(ListNode* head, ListNode* pre)
{
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
    {
        fprintf(stdout, "%d->", p->data);
    }
    printf("NULL \n");
}
void find_max_min(ListNode* head, element* max, element* min)
{
    ListNode* p = head;
    *max = p->data; //데이터 가져옴 (마지막에 넣은 데이터)
    *min = p->data;//데이터 가져옴 (마지막에 넣은 데이터)
    p = p->link; // 포인터에 첫번째거 넣음 
    while (p != NULL)
    {
        if (p->data > *max) *max = p->data; // 크면 넣음
        if (p->data < *min) *min = p->data; // 작으면 넣음
        p = p->link; // 다음꺼 가져옴
    }
}

int main()
{
    ListNode* head = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = insert_first(head, i);
        print_list(head);
    }
    element max, min;
    find_max_min(head, &max, &min);
    printf("최댓값: %d, 최솟값: %d\n",max,min);
    for (int i = 0; i < 5; i++)
    {
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}
