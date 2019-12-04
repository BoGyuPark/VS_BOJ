#include<iostream>
using namespace std;
int parent[1001];

int findParent(int x) {
	if (parent[x] == x) return x;
	return findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[a] = b;
}