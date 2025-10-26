
#ifndef HELPER_H
#define HELPER_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node{
	struct Node *left;
	struct Node *right;
} node;

int min(int a, int b);
node *createNode();
int dfs(node *root, int *count);
void deleteTree(node *root);
node *levelOrderToTree(const int *levelOrder, int n);
int minPhones(int *arr, int n);
int *sieve();
int invalidXorPairs(int n, int l, int r);

#endif