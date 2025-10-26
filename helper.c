
#include "helper.h"

#define MAX_N ((int) 3e5)
#define LR_RANGE ((int) 2e6)

// finds the minimum of two numbers
int min(int a, int b) {
	return (a < b) ? a : b;
}

// dynamically allocates memory for a new node and returns it's address
node *createNode() {
	node *root = (node *) malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	return root;
}

// uses depth first search to find the minimum number of nodes
int dfs(node *root, int *count) {
	if (root == NULL) return 2;
	int l ,r;
	l = dfs(root->left, count);
	r = dfs(root->right, count);

	if (l == 0 || r == 0) {
		(*count)++;
		return 1;
	}
	if (l == 1 || r == 1) return 2;
	return 0;
}

// frees up any memory allocated for the tree
void deleteTree(node *root) {
	if (root->left != NULL) deleteTree(root->left);
	if (root->right != NULL) deleteTree(root->right);
	free(root);
}

// coverts the level order array to a binary tree
node *levelOrderToTree(const int *levelOrder, int n) {
	if (n < 1 || levelOrder[0] == 0) return NULL;
	node **queue = (node **) malloc(n * sizeof(node *));
	node *root = createNode();
	queue[0] = root;
	int front = 0, rear = 1, i = 1;	

	while (front < rear && i < n) {
		node *cur = queue[front++];
		if (i < n) {
			if (levelOrder[i] == 1) {
				cur->left = createNode();
				queue[rear++] = cur->left;
			}
			i++;
		}
		if (i < n) {
			if (levelOrder[i] == 1) {
				cur->right = createNode();
				queue[rear++] = cur->right;
			}
			i++;
		}
	}
	return root;
}

// returns the minimum number of phones needed for the problem
int minPhones(int *arr, int n) {
	if (n == 0) return 0;
	node *root = levelOrderToTree(arr, n);
	int ret = 0;
	int state = dfs(root, &ret);
	if (state == 0) ret++;
	deleteTree(root);
	return ret;
}

// generates primes using the sieve of eratosthenes
int *sieve() {
	char prime[MAX_N];
	int *ret = (int *) malloc(MAX_N * sizeof(int));
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int p = 2; p * p <= MAX_N; p++) {
		if (prime[p] == 1) {
			for (int i = p * p; i <= MAX_N; i += p) prime[i] = 0;
		}
	}
	int j = 0;
	for (int i = 0; i <= MAX_N; i++) if (prime[i] == 1) ret[j++] = i;
	return ret;
}

// calculates the number of invalid pairs outside the range [l, r]
int invalidXorPairs(int n, int l, int r) {
	int *primes = sieve();
	int count = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int cacti = primes[i] ^ primes[j];
			if (cacti < l || cacti > r) count++;
		}
	}
	return count;
}