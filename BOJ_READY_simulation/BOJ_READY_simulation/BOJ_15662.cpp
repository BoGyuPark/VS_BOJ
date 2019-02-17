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
		//미리 각 톱니바퀴의 방향을 정한다.
		for (int i = 0; i < tc; i++) {
			if (i % 2 == (num - 1) % 2) arr[i] = dir;
			else arr[i] = -dir;
		}

		//톱니바퀴 사이에 돌릴지 말지를 판단.
		for (int i = 0; i < tc - 1; i++) {
			if (t[i][2] == t[i + 1][6]) v.push_back(0);
			else v.push_back(1);
		}
		int c[1001] = { 0, };
		//톱니바퀴를 돌려야한다면 돌린다.
		if (arr[num - 1] == 1) NormalRotate(num - 1);
		else ReverseRotate(num - 1);
		c[num - 1] = true;
		int left = num - 2, right = num - 1;
		while (left >= 0) {
			if (v[left] == 1) {
				//i와 i+1번째 톱니를 돌린다.
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
				//i와 i+1번째 톱니를 돌린다.
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
	//톱니바퀴를 돌린후 개수를 구한다.
	for (int i = 0; i < tc; i++) if (t[i][0] == '1') sum++;
	cout << sum;
}