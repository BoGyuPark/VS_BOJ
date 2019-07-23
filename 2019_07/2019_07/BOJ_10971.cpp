/*BOJ 10971 ���ǿ� ��ȸ 2 */
/* N���� ����, �� ���ÿ��� ����� N���� ���� ��� ���� �ٽ� ����
���÷� , �� ���� ���ô� �ٽ� ����., �ּҺ������*/
/* 0���� �����ϳ� 1���� �����ϳ� �����ϹǷ� 0������ �������*/
#include<iostream>
using namespace std;
int n, ans = 2147483647;
int w[11][11], sel[11], check[11];
void go(int index) {
	if (index == n) {
		int sum = 0;
		for (int j = 0; j < n-1; j++)
		{
			if (w[sel[j]][sel[j + 1]] == 0) return;
			sum += w[sel[j]][sel[j + 1]];
		}
		if (w[sel[n - 1]][0] == 0) return;
		sum += w[sel[n - 1]][0];
		if (ans > sum) ans = sum;
		return;
	}
	for (int i = 1; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = i;
		go(index + 1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> w[i][j];
	go(1);
	cout << ans;
}