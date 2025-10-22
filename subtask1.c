
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node *left;
	struct Node *right;
	int dp[2];	// dp[0]- min phones in the subtree if the node is given a phone
} node;			// dp[1]- min phones in the subtree if the node is not given a phone

node *createNode() {
	node *root = (node *) malloc(sizeof(node));
	return root;
}

node *levelOrderToTree(const int *levelOrder, int n) {
	if (n < 1) return NULL;
	
	node **queue = (node **) malloc(n * sizeof(node*));
	int front = -1, rear = -1;
	
	if (levelOrder[0] == 1) node *root = createNode();
	else return NULL;
	queue[++front] = root; rear = front+1;
	
	int i = 0;
	while (rear-front > 0) {
		root = queue[front];
		if (levelOrder[front] == 1) {
			
		}
	}
}

void print(node *root) {
	if (root == NULL) {
		printf("0 ");
		return;
	}
	printf("1 ");
	print(root->left);
	print(root->right);
}

int main() {
	int n;
	scanf("%d", &n);
	int *arr = (int *) malloc(n * sizeof(int));
	for (int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	node *root = levelOrderToTree(arr, n);
	print(root);
	return 0;
}
