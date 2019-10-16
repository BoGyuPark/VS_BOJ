/*BOJ 2422 한윤정이 이탈리아에 가서 아이스크림을 사먹는데*/
#include<iostream>
using namespace std;
int n, m, check[201][201] , sel[4], c[201], cnt;
void go(int index, int start) {
	if (index == 3) {
		cnt++;
		return;
	}
	for (int i = start; i <= n; i++) {
		if (c[i]) continue;
		int flag = false;
		for (int j = 0; j < index; j++) {
			if (check[i][sel[j]]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		check[t1][t2] = check[t2][t1] = true;
	}
	go(0, 1);
	cout << cnt;
}