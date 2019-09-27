/*BOJ 2263 Ʈ���� ��ȸ*/
#include<iostream>
using namespace std;
int n,postOrder[100'002], inOrder[100'002], inOrderIdx[100'002];
/*
 *
 *
	 inorder ����, �� , postorder ���� ��
	 inorder�� ������ �´� postorder������ ����
*/
void getPreOrder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int rootNum = postOrder[pe];
	cout << rootNum << ' ';
	int rootIdx = inOrderIdx[rootNum];
	int leftSize = rootIdx - is;
	//left subtree
	getPreOrder(is, rootIdx - 1, ps, ps + leftSize - 1);
	//right subtree
	getPreOrder(rootIdx + 1, ie, ps + leftSize, pe - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inOrder[i];
		inOrderIdx[inOrder[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> postOrder[i];
	getPreOrder(0, n - 1, 0, n - 1);
}