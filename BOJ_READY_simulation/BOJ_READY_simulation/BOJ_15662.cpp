#include<iostream>
#include<vector>
using namespace std;
int k, num, dir, arr[1001],tc;
char t[1001][8];
void NormalRotate(int index) {
	char temp = t[index][7];
	for (int i = 7; i > 0; i--) t[index][i] = t[index][i - 1];
	t[index][0] = temp;
}
void ReverseRotate(int index) {
	char temp = t[index][0];
	for (int i = 0; i < 8; i++) t[index][i] = t[index][i + 1];
	t[index][7] = temp;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (int i = 0; i < tc; i++)
		for (int j = 0; j < 8; j++) cin >> t[i][j];
	cin >> k;
	while (k--) {
		vector<int> v;
		cin >> num >> dir;
		//�̸� �� ��Ϲ����� ������ ���Ѵ�.
		for (int i = 0; i < tc; i++) {
			if (i % 2 == (num - 1) % 2) arr[i] = dir;
			else arr[i] = -dir;
		}

		//��Ϲ��� ���̿� ������ ������ �Ǵ�.
		for (int i = 0; i < tc - 1; i++) {
			if (t[i][2] == t[i + 1][6]) v.push_back(0);
			else v.push_back(1);
		}
		int c[1001] = { 0, };
		//��Ϲ����� �������Ѵٸ� ������.
		if (arr[num - 1] == 1) NormalRotate(num - 1);
		else ReverseRotate(num - 1);
		c[num - 1] = true;
		int left = num - 2, right = num - 1;
		while (left >= 0) {
			if (v[left] == 1) {
				//i�� i+1��° ��ϸ� ������.
				if (c[left] == false) {
					if (arr[left] == 1) NormalRotate(left);
					else ReverseRotate(left);
					c[left] = true;
				}
				if (c[left + 1] == false) {
					if (arr[left + 1] == 1) NormalRotate(left + 1);
					else ReverseRotate(left + 1);
					c[left + 1] = true;
				}
			}
			else break;
			left--;
		}
		while (right < tc - 1) {
			if (v[right] == 1) {
				//i�� i+1��° ��ϸ� ������.
				if (c[right] == false) {
					if (arr[right] == 1) NormalRotate(right);
					else ReverseRotate(right);
					c[right] = true;
				}
				if (c[right + 1] == false) {
					if (arr[right + 1] == 1) NormalRotate(right + 1);
					else ReverseRotate(right + 1);
					c[right + 1] = true;
				}
			}
			else break;
			right++;
		}
	}
	int sum = 0;
	//��Ϲ����� ������ ������ ���Ѵ�.
	for (int i = 0; i < tc; i++) if (t[i][0] == '1') sum++;
	cout << sum;
}