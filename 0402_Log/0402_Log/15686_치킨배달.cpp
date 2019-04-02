#include<iostream>
#include<vector>
using namespace std;
int n, m, t;
vector<pair<int, int>> house, ch, NewCh;
int sel[14], c[14], ans = 2147483647;
void dfs(int index, int start, int dest) {
	if (index == dest) {
		for (int j = 0; j < dest; j++) NewCh.push_back({ ch[sel[j]].first ,ch[sel[j]].second });
		int sum = 0, temp;
		for (int x = 0; x < house.size(); x++) {
			temp = 0;
			for (int y = 0; y < NewCh.size(); y++) {
				int dist = abs(house[x].first - NewCh[y].first) + abs(house[x].second - NewCh[y].second);
				if (temp == 0 || dist < temp) temp = dist;
			}
			sum += temp;
		}
		if (ans > sum) ans = sum;
		NewCh.clear();
		return;
	}
	for (int i = start; i < ch.size(); i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1, i, dest);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t;
			if (t == 1) house.push_back({ i,j });
			if (t == 2) ch.push_back({ i,j });
		}
	}
	dfs(0, 0, m);
	//for (int i = 1; i <= m; i++) dfs(0, 0, i);
	cout << ans;
}