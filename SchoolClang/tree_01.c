/*
�ǽ���: Ʈ�� ������ Ȱ���Ͽ� ���� , ���� , ���� ��ȸ ( 8 - 1 )
������ ����: �ڿ��� ������
�ǽ���: 2020 05 11
�а� : ��Ƽ �̵�� �а�
�й� : 201610309
�̸� : ������
*/
#include <stdio.h>
#include <stdlib.h>

//_____________________________________________
//| leftstructNode |  data  | rightstructNode |
//---------------------------------------------
typedef char TElements;
typedef struct BinTrNode {
	TElements data;
	struct BinTrNode* left;
	struct BinTrNode* right;
} TNode;

TNode* root;

void init_tree() { root = NULL; }

int is_empty() { return root = NULL; }

TNode* get_root() { return root; }

TNode* create_tree(TElements val, TNode* l, TNode* r) {
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

void preOrder(TNode *n) {
	if (n != NULL) {
		printf("[%c] ", n->data);
		preOrder( n->left);
		preOrder( n->right);
	}
}

void inOrder(TNode *n) {
	if (n != NULL) {
		inOrder(n->left);
		printf("[%c] ", n->data);
		inOrder(n->right);
	}
}

void postOrder(TNode* n) {
	if (n != NULL) {
		postOrder(n->left);
		postOrder(n->right);
		printf("[%c] ", n->data);
	}
}

int count_node(TNode *n) {
	if (n == NULL) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n) {
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n) {
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

int main() {
	TNode* b, * c, * d, * e, * f;
	init_tree();
	d = create_tree('D', NULL, NULL);
	e = create_tree('E', NULL, NULL);
	b = create_tree('B', d, e);
	f = create_tree('F', NULL, NULL);
	c = create_tree('C', f, NULL);
	root = create_tree('A', b, c);

	printf("\n In-Order : ");
	inOrder(root);
	
	printf("\n Pre-Order : ");
	preOrder(root);
	
	printf("\n Post-Order : ");
	postOrder(root);
	printf("\n");

	printf("����� ���� =  %d \n", count_node(root));
	printf("�ܸ��� ���� =  %d \n", count_leaf(root));
	printf("Ʈ���� ���� =  %d \n", calc_height(root));

	return 0;
}


