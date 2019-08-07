/*BOJ_ 9019 DSLR*/
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
#define MAX 10000
int T, a, b;
int check[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> a >> b;
		queue<pair<int, string>> q;
		memset(check, 0, sizeof(check));
		q.push({ a, "" });
		check[a] = true;
		while (!q.empty()) {
			int now = q.front().first;
			string nowStr = q.front().second;
			q.pop();
			if (now == b) {
				cout << nowStr << '\n';
				break;
			}

			int next;
			//D
			next = (now * 2) % MAX;
			if (check[next] == false) {
				q.push({ next, nowStr + "D" });
				check[next] = true;
			}

			//S
			if (now == 0) next = 9999;
			else next = now - 1;
			if (check[next] == false) {
				q.push({ next, nowStr + "S" });
				check[next] = true;
			}

			//L
			next = (now % 1000) * 10 + (now / 1000);
			if (check[next] == false) {
				q.push({ next, nowStr + "L" });
				check[next] = true;
			}

			//R
			next = (now % 10) * 1000 + (now / 10);
			if (check[next] == false) {
				q.push({ next, nowStr + "R" });
				check[next] = true;
			}
		}
	}
	return 0;
}