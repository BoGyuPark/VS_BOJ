#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> from(n, -1);
		vector<int> how(n, -1);
		vector<int> dis(n, -1);
		queue<int> q;
		q.push(1 % n);
		dis[1 % n] = 0;
		how[1 % n] = 1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i <= 1; i++) {
				int next = (now * 10 + i) % n;
				if (dis[next] == -1) {
					dis[next] = dis[now] + 1;
					from[next] = now;
					how[next] = i;
					q.push(next);
				}
			}
		}
		if (dis[0] == -1) cout << "BRAK" << '\n';
		else {
			string s = "";
			for (int i = 0; i != -1; i = from[i])
				s = to_string(how[i]) + s;
			cout << s << '\n';
		}
	}
}