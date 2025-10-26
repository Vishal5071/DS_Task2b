
#include <stdio.h>
#include "helper.h"

int main() {
	//Input handling
	int n;
	scanf("%d", &n);

	int *arr = (int *) malloc(n * sizeof(int));
	for (int i=0; i<n; i++) scanf("%d", arr+i);

	int l, r;
	scanf("%d %d", &l, &r);

	// Output handling
	int m =  minPhones(arr, n);
	printf("%d\n", m);
	printf("%d\n", invalidXorPairs(m, l, r));

	return 0;
}