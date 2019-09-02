/* BOJ 2606 바이러스*/
#include<iostream>
#include<vector>
using namespace std;
int n, m, check[101], cnt;
vector<vector<int>> ve(101);
void go(int num) {
	for (int i = 0; i < ve[num].size(); i++) {
		int next = ve[num][i];
		if (check[next]) continue;
		check[next] = true;
		cnt++;
		go(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ve[v].push_back(u);
		ve[u].push_back(v);
	}
	check[1] = true;
	go(1);
	cout << cnt;
}