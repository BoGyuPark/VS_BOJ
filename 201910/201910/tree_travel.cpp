#include<iostream>
using namespace std;
struct TreeNode {
	int data;
	struct TreeNode *left, *right;
};
void preorder(TreeNode *ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void inorder(TreeNode *ptr) {
	if (ptr) {
		inorder(ptr->left);
		cout << ptr->data << ' ';
		inorder(ptr->right);
	}
}

void postorder(TreeNode *ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << ' ';
	}
}
int main() {
	TreeNode nodes[16];
	for (int i = 1; i < 16; i++) {
		nodes[i].data = i;
		nodes[i].left = nodes[i].right = NULL;
	}
	for (int i = 1; i <= 7; i++) {
		nodes[i].left = &nodes[i * 2];
		nodes[i].right = &nodes[i * 2 + 1];
	}
	preorder(&nodes[1]); cout << '\n';
	inorder(&nodes[1]); cout << '\n';
	postorder(&nodes[1]); cout << '\n';
}