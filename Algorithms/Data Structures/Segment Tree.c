#include <stdio.h>

#define SIZE 100000


int nums[SIZE], tree[SIZE * 3];


void init(int b, int e, int node)
{
	if (b == e) {
		tree[node] = nums[b];
		return;
	}

	int leftSubNode = 2 * node;
	int rightSubNode = 2 * node + 1;
	int mid = (b + e) / 2;

	init(b, mid, leftSubNode);
	init(mid + 1, e, rightSubNode);

	tree[node] = tree[leftSubNode] + tree[rightSubNode];
}


int query(int b, int e, int i, int j, int node)
{
	if (b >= i && e <= j) return tree[node];
	else if (b > j || e < i) return 0;

	int leftSubNode = 2 * node;
	int rightSubNode = 2 * node + 1;
	int mid = (b + e) / 2;

	int leftSum = query(b, mid, i, j, leftSubNode);
	int rightSum = query(mid + 1, e, i, j, rightSubNode);

	return leftSum + rightSum;
}


void update(int b, int e, int i, int newNum, int node)
{
	if (b == e) {
		tree[node] = newNum;
		return;
	} else if (b > i || e < i) return;

	int leftSubNode = 2 * node;
	int rightSubNode = 2 * node + 1;
	int mid = (b + e) / 2;

	update(b, mid, i, newNum, leftSubNode);
	update(mid + 1, e, i, newNum, rightSubNode);

	tree[node] = tree[leftSubNode] + tree[rightSubNode];
}


int main()
{
    freopen("Input - Segment Tree.txt", "r", stdin);

    int i = 1;

    while (scanf("%d", &nums[i]) != EOF)
    	i++;

    i--;	// i is the total number of numbers (means i is the length of input array)

    init(1, i, 1);
    printf("Sum from number 2 to 7 = %d where i = %d\n", query(1, i, 2, 7, 1), i);
    for (int p = 1; p < 3*i; p++) printf("%d\t", tree[p]);
    printf("\n");

    update(1, i, 6, 9, 1);
    for (int p = 1; p < 3*i; p++) printf("%d\t", tree[p]);
    printf("\n");
    printf("Updated node 6 to number 9.\nSum from number 2 to 7 = %d\n", query(1, i, 2, 7, 1));

    //printf("%d\n", i);

    return 0;
}
