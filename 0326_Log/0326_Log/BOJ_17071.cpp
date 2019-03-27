#include<iostream>
#include<queue>
using namespace std;
#define MAX 500001
int n, k, c[MAX];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	queue<int> q; q.push(n);
	if (n == k) cout << 0;
	else {
		int cnt = 1;
		int found = false;
		while (true) {
			int Qsize = q.size();
			while (Qsize--) {
				int now = q.front();
				q.pop();
				//잡은 경우
				if (now == k) {
					cout << cnt - 1 << '\n';
					found = true;
					break;
				}
				if (now * 2 < MAX) {
					if (c[now * 2] < cnt + 1) {
						q.push(now * 2);
						c[now * 2] = cnt + 1;
					}
				}
				if (now - 1 >= 0) {
					if (c[now - 1] < cnt + 1) {
						q.push(now - 1);
						c[now - 1] = cnt + 1;
					}
				}
				if (now + 1 < MAX) {
					if (c[now + 1] < cnt + 1) {
						q.push(now + 1);
						c[now + 1] = cnt + 1;
					}
				}
			}
			if (found) break;
			k += cnt;
			if (k > MAX) break;
			cnt++;
		}
		if (!found) cout << -1;
	}
}