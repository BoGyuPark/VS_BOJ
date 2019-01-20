//BOJ_1707_BipartiteGraph
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int check[20001];
vector<int> a[20001];
int ans = 1;
void dfs(int node, int c)
{
	check[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next, 3 - c);
		}
		else if (check[next] == c) {
			ans = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, v, e; cin >> k;
	while (k--) {
		cin >> v >> e;
		for (int i = 1; i <= e; i++) {
			int t1, t2; cin >> t1 >> t2;
			a[t1].push_back(t2);
			a[t2].push_back(t1);
		}
		for (int i = 1; i <= v; i++) {
			if (check[i] == false) {
				dfs(i, 1);
			}
		}
		cout << (ans == 1 ? "YES\n" : "NO\n");
		memset(check, 0, sizeof(check));
		ans = 1;
		for (int i = 1; i <= v; i++) {
			a[i].erase(a[i].begin(), a[i].end());
		}
	}
	return 0;
}