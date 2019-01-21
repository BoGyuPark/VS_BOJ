//BOJ_1167_TreeDiameter
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int check[100001];
vector<pair<int, int> > a[100001];
void bfs(int node) {
	queue<pair<int, int> > q;
	q.push(make_pair(node, 0));
	check[node] = true;
	int x, xw;
	while (!q.empty()) {
		x = q.front().first; xw = q.front().second;
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int next = a[x][i].first;
			if (check[next] == 0) {
				check[next] = a[x][i].second + xw;
				q.push(make_pair(next, a[x][i].second + xw));
			}
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int v; cin >> v;
	int vert, dest, w;
	for (int i = 1; i <= v; i++) {
		cin >> vert;
		while (1) {
			cin >> dest;
			if (dest == -1)
				break;
			cin >> w;
			a[vert].push_back(make_pair(dest, w));
		}
	}
	bfs(1);
	int max = 0, maxV;
	for (int i = 1; i <= v; i++) {
		if (max < check[i]) {
			max = check[i];
			maxV = i;
		}
	}
	memset(check, 0, sizeof(check));
	bfs(maxV);
	int ans = 0;
	for (int i = 1; i <= v; i++) {
		if (ans < check[i]) {
			ans = check[i];
		}
	}
	cout << ans;
	return 0;
}