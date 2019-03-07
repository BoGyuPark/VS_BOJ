#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, a[51][51], chcnt, sel[13], c[13], ans = 2137483647;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> h, ch, wait;
int cal() {
	int chSum = 0;
	for (int i = 0; i < h.size(); i++) {
		int dif, mini = 2137483647;
		for (int j = 0; j < wait.size(); j++) {
			dif = abs(h[i].first - wait[j].first) + abs(h[i].second - wait[j].second);
			if (mini > dif) mini = dif;
		}
		chSum += mini;
	}
	return chSum;
}

void dfs(int index, int start) {
	if (index == m) {
		wait = vector<pair<int, int>>();
		for (int j = 0; j < m; j++)
			wait.push_back({ ch[sel[j]].first,ch[sel[j]].second });
		int temp = cal();
		if (ans > temp) ans = temp;
		return;
	}
	for (int i = start; i < chcnt; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1,i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) h.push_back({ i,j });
			else if (a[i][j] == 2) {
				ch.push_back({ i,j });
				a[i][j] = 0;
			}
		}
	}
	chcnt = ch.size();
	dfs(0,0);
	cout << ans;
}