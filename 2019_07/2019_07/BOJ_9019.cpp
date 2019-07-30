/*BOJ 9019 DSLR/*/
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int T, A, B, check[10001], instLog[10001];
char inst[10001];
int main() {
	cin >> T;
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		memset(check, -1, sizeof(check));
		memset(instLog, 0, sizeof(instLog));
		memset(inst, 0, sizeof(inst));
		queue<int> q;
		q.push(A);
		check[A] = 0;
		while (!q.empty()) {
			int now = q.front();	q.pop();
			if (now == B) {
				string ans = "";
				while (A != B) {
					ans = inst[B] + ans;
					B = instLog[B];
				}
				cout << ans << '\n';
				break;
			}
			int next;
			//D
			next = (now * 2) % 10000;
			if (check[next] == -1) {
				check[next] = check[now] + 1;
				q.push(next);
				instLog[next] = now;
				inst[next] = 'D';
			}
			//S
			next = now - 1;
			if (next < 0) next = 9999;
			if (check[next] == -1) {
				check[next] = check[now] + 1;
				q.push(next);
				instLog[next] = now;
				inst[next] = 'S';
			}
			//L
			next = (now % 1000) * 10 + now / 1000;
			if (check[next] == -1) {
				check[next] = check[now] + 1;
				q.push(next);
				instLog[next] = now;
				inst[next] = 'L';
			}
			//R
			next = (now / 10) + (now % 10) * 1000;
				if (check[next] == -1) {
				check[next] = check[now] + 1;
				q.push(next);
				instLog[next] = now;
				inst[next] = 'R';
			}
		}
	}
}