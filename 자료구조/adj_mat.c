#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
	Node* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		g->adj_list[r] = NULL;
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

Node* create_node(int v) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->vertex = v;
	node->next = NULL;
	return node;
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;

	Node* node = create_node(end);
	if (g->adj_list[start] == NULL) {
		g->adj_list[start] = node;
	}
	else {
		Node* last = g->adj_list[start];
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = node;
	}
}

void print_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void print_adj_list(GraphType* g) {
	for (int v = 0; v < g->n; v++) {
		Node* node = g->adj_list[v];
		printf("Adjacency list of vertex %d\n", v);
		while (node) {
			printf(" -> %d", node->vertex);
			node = node->next;
		}
		printf("\n");
	}
}

void main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 5; i++) // ���� �߰� (5��)
		insert_vertex(g, i);

	// �־��� ���� ��Ŀ� ���� ���� �߰�
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 4);

	insert_edge(g, 1, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);

	insert_edge(g, 2, 1);
	insert_edge(g, 2, 4);

	insert_edge(g, 3, 1);
	insert_edge(g, 3, 4);

	insert_edge(g, 4, 0);
	insert_edge(g, 4, 2);
	insert_edge(g, 4, 3);

	printf("���� ���:\n");
	print_adj_mat(g);

	printf("\n���� ����Ʈ:\n");
	print_adj_list(g);

	free(g);
}