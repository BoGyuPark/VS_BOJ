//BOJ_10451_PermutationCycle
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> a[1001];
int check[1001];
int ans = 0;
void dfs(int node)
{
	check[node] = true;
	int next = a[node][0];
	if (check[next] == false)
		dfs(next);
	else
		ans++;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int temp; cin >> temp;
			a[i].push_back(temp);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == false)
				dfs(i);
		}
		cout << ans << '\n';
		memset(check, 0, sizeof(check));
		for (int i = 1; i <= n; i++) {
			a[i].erase(a[i].begin(), a[i].end());
		}
		ans = 0;
	}
	return 0;
}