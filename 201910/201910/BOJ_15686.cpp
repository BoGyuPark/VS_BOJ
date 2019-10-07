//BOJ_15686 치킨 배달
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, ans, map[51][51], sel[20], c[255];
vector<pair<int, int>> house, v;
void cal() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int mini = 2147483647;
		for (int j = 0; j < m; j++) {
			int x = v[sel[j]].first, y = v[sel[j]].second;
			int dif = abs(house[i].first - x) + abs(house[i].second - y);
			mini = min(mini, dif);
		}
		sum += mini;
	}
	ans = min(ans, sum);
}
void go(int index,int start) {
	if (index == m) {
		cal();
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			else if (map[i][j] == 2) v.push_back({ i,j });
		}
	}
	ans = 2147483647;
	go(0,0);
	cout << ans;
}