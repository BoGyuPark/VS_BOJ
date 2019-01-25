#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int> > q;
int check[1001][1001], cnt[1001][1001], S;
void bfs(int node) {
	check[node][0] = true;
	q.push(make_pair(node, 0));
	cnt[node][0] = 0;
	while (!q.empty()) {
		int s, c;
		s = q.front().first; c = q.front().second;
		q.pop();
		if (check[s][s] == false) {
			check[s][s] = true;
			q.push(make_pair(s,s));
			cnt[s][s] = cnt[s][c] + 1;
		}
		if (s + c <= S &&check[s + c][c] == false) {
			check[s + c][c] = true;
			q.push(make_pair(s + c, c));
			cnt[s+c][c] = cnt[s][c] + 1;
		}
		if (s - 1 >= 0 &&check[s - 1][c] == false) {
			check[s - 1][c] = true;
			q.push(make_pair(s - 1, c));
			cnt[s-1][c] = cnt[s][c] + 1;
		}
	}
}

int main() {
	cin >> S;
	bfs(1);
	int ans = cnt[S][1];
	for (int i = 2; i < 1001; i++) {
		if (ans > cnt[S][i] && cnt[S][i] != 0)
			ans = cnt[S][i];
	}
	cout << ans;
	return 0;
}