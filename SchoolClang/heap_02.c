/*
�ǽ���:heap_02_�ǽ�!!
������ ����: �ڿ��� ������
�ǽ���: 2020 05 27
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS	256

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

typedef char VtxData;
/*  �׷��� ������ ������ �������� �ڷ���
 */
int adj[MAX_VTXS][MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];		/* ������ ������ ������ �迭
*/
int is_empty_graph() { return (vsize == 0); }
int is_full_graph() { return (vsize >= MAX_VTXS); }
void init_graph()
{
	int i, j;
	vsize = 0;
	for (i = 0; i < MAX_VTXS; i++)
		for (j = 0; j < MAX_VTXS; j++)
			adj[i][j] = 0;
}
void insert_vertex(VtxData name)
{
	if (is_full_graph())
		error("Error: �׷��� ������ ���� �ʰ�\n");
	else
		vdata[vsize++] = name;
}
void insert_edge(int u, int v, int val)
{
	adj[u][v] = val;
}
void insert_edge2(int u, int v, int val)
{
	adj[u][v] = adj[v][u] = val;
}

void print_graph(char* msg)
{
	int i, j;
	printf("%s", msg);
	printf("%d\n", vsize);
	for (i = 0; i < vsize; i++) {
		printf("%c  ", vdata[i]);
		for (j = 0; j < vsize; j++)
			printf(" %3d", adj[i][j]);
		printf("\n");
	}
}
void load_graph(char* filename)
{
	int i, j, val, n;
	char	str[80];
	FILE* fp = fopen(filename, "r");
	if (fp != NULL) {
		init_graph();
		fscanf(fp, "%d", &n);
		for (i = 0; i < n; i++) {
			fscanf(fp, "%s", str);
			insert_vertex(str[0]);
			for (j = 0; j < n; j++) {
				fscanf(fp, "%d", &val);
				if (val != 0)
					insert_edge(i, j, val);
			}
		}
		fclose(fp);
	}
}
void print_graph2(FILE* fp, char* msg)
{
	int i, j;
	fprintf(fp, "%s", msg);
	fprintf(fp, "%d\n", vsize);
	for (i = 0; i < vsize; i++)
	{
		fprintf(fp, "%c  ", vdata[i]);
		for (j = 0; j < vsize; j++)
			fprintf(fp, " %3d", adj[i][j]);
		fprintf(fp, "\n");
	}
}

void store_graph(char* filename)
{
	FILE* fp = fopen(filename, "w");
	if (fp != NULL) {
		print_graph2(fp, "");
		fclose(fp);
	}
}


int main(void)
{
	int i;

	init_graph();
	for (i = 0; i < 4; i++)
		insert_vertex('A' + i);

	insert_edge2(0, 1, 1);
	insert_edge2(0, 3, 1);
	insert_edge2(1, 2, 1);
	insert_edge2(1, 3, 1);
	insert_edge2(2, 3, 1);
	print_graph("�׷���(�������)\n");

	store_graph("graph.txt");
	load_graph("graph.txt");
	print_graph("�׷���(�������)\n");

	return 0;
}

