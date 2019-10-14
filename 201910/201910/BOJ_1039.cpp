/* BOJ 1039 ±³È¯*/
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int k, check[1'000'001];
string s, ans = "0";
queue<string> q;
void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int Qsize = q.size();
		memset(check, 0, sizeof(check));
		if (cnt == k) return;
		while (Qsize--) {
			string now = q.front(); q.pop();
			if (check[stoi(now)]) continue;
			check[stoi(now)] = true;
			for (int i = 0; i < now.size() - 1; i++) {
				for (int j = i + 1; j < now.size(); j++) {
					string next = now;
					swap(next[i], next[j]);
					if (next[0] == '0') continue;
					if (cnt + 1 == k) ans = max(ans, next);
					q.push(next);
				}
			}
		}
		cnt++;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> k;
	q.push(s);
	check[stoi(s)] = true;
	bfs();
	if (ans == "0") ans = "-1";
	cout << ans;
}