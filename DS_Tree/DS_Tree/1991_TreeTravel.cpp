//BOJ_1991_TreeTravel
#include<iostream>
using namespace std;
int Tree[27][2];
void preorder(int root) {
	if (root == -1) return;
	cout << (char)(root + 'A');
	preorder(Tree[root][0]);
	preorder(Tree[root][1]);
}

void inorder(int root) {
	if (root == -1) return;
	inorder(Tree[root][0]);
	cout << (char)(root + 'A');
	inorder(Tree[root][1]);
}

void postorder(int root) {
	if (root == -1) return;
	postorder(Tree[root][0]);
	postorder(Tree[root][1]);
	cout << (char)(root + 'A');
}

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		if (left == '.') {
			Tree[root - 'A'][0] = -1;
		}
		else
			Tree[root - 'A'][0] = left - 'A';
		if (right == '.') {
			Tree[root - 'A'][1] = -1;
		}
		else
			Tree[root - 'A'][1] = right - 'A';
	}
	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';
	return 0;
}