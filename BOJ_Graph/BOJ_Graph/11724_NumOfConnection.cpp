//BOJ_11724_NumOfConnection
#include<iostream>
#include<vector>
using namespace std;
int check[1001];
vector<int> a[1001];
void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int t1, t2; cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}