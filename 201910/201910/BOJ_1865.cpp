/* BOJ 1865 ¿úÈ¦ */
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define INF 2147483647
typedef pair<int, int> p;
struct info {
	int s, e, t;
};
int Tc, N, M, W, S, E, T;
int check[501][501];
vector<info> node,warmHall;
vector<vector<p>> g;
vector<int> Upper;
void createGraph() {
	g.clear();
	g.resize(N + 1);
	for (int i = 0; i < warmHall.size(); i++) {
		int s = warmHall[i].s, e = warmHall[i].e, cost = warmHall[i].t;
		g[s].push_back({ e,cost });
		check[s][e] = true;
	}

	for (int i = 0; i < node.size(); i++) {
		int s = node[i].s, e = node[i].e, cost = node[i].t;
		if (check[e][s]) {
			g[s].push_back({ e,cost });
		}
		else if (check[s][e]) {
			g[e].push_back({ s,cost });
		}
		else {
			g[s].push_back({ e,cost });
			g[e].push_back({ s,cost });
		}
	}
}
bool bellmanFord(int nodeNum) {
	Upper.clear();
	for (int i = 0; i <= N; i++) Upper.push_back(INF);
	Upper[nodeNum] = 0;
	bool minusCycle = false;
	for (int i = 1; i <= N; i++) {
		for (int now = 1; now <= N; now++) {
			for (int j = 0; j < g[now].size(); j++) {
				int next = g[now][j].first;
				int cost = g[now][j].second;
				if (Upper[now] != INF && Upper[next] > cost + Upper[now]) {
					Upper[next] = cost + Upper[now];
					if (i == N) minusCycle = true;
				}
			}
		}
	}
	return minusCycle;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Tc;
	for (int tc = 0; tc < Tc; tc++) {
		memset(check, 0, sizeof(check));
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			node.push_back({ S,E,T });
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			warmHall.push_back({ S,E,-T });
		}

		createGraph();
		cout << (bellmanFord(1) ? "YES" : "NO") << '\n';
		node.clear();
		warmHall.clear();
	}
}