/*BOJ 15971 두 로봇*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, s, e, check[100001], max_len, path[100001], ans, flag;
vector<pair<int, int>> ve[100001];
void go(int num, int depth, int totalLen) {
	if (flag) return;
	if (num == e) {
		//경로중 가장 긴 길이 구하기
		for (int i = 0; i < depth; i++) {
			max_len = max(max_len, path[i]);
		}
		ans = totalLen - max_len;
		flag = true;
		return;
	}
	for (int i = 0; i < ve[num].size(); i++) {
		int next = ve[num][i].first, len = ve[num][i].second;
		if (check[next]) continue;
		check[next] = true;
		path[depth] = len;
		go(next, depth + 1, totalLen + len);
		check[next] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> e;
	for (int i = 0; i < n - 1; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		ve[u].push_back({ v,len });
		ve[v].push_back({ u,len });
	}
	check[s] = true;
	go(s, 0, 0);
	cout << ans;
}