/* 2617�� - ���� ã�� */
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m, larger[101], smaller[101], check[101][101];
vector<vector<int>> la(100), sm(100);

void go(int idx, int now) {
	
	for (int i = 0; i < la[now].size(); i++) {
		int next = la[now][i];
		if (check[idx][next]) continue;
		larger[idx]++;
		check[idx][next] = true;
		go(idx, next);
	}

}

void goSmall(int idx, int now) {

	for (int i = 0; i < sm[now].size(); i++) {
		int next = sm[now][i];
		if (check[idx][next]) continue;
		smaller[idx]++;
		check[idx][next] = true;
		goSmall(idx, next);
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		la[t2].push_back(t1);
		sm[t1].push_back(t2);
	}

	//ū �� Ž��
	for (int i = 1; i <= n; i++) go(i, i);
	memset(check, 0, sizeof(check));
	//������ Ž��
	for (int i = 1; i <= n; i++) goSmall(i, i);
	
	int ans = 0;
	// in �� out �� �ϳ��� 0�̰� out �� in�� (n + 1) / 2 �̻��� ����
	for (int i = 1; i <= n; i++) {
		if (larger[i] >= (n + 1) / 2 || smaller[i] >= (n + 1) / 2) ans++;
	}
	cout << ans;
}