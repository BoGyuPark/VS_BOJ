/*BOJ 16928 뱀과 사다리 게임*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, teleport[101], check[101];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int x, y;
		cin >> x >> y;
		teleport[x] = y;
	}
	memset(check, -1, sizeof(check));
	q.push(1);
	check[1] = 0;
	while (!q.empty()) {
		int now = q.front();	q.pop();
		if (now == 100) break;
		for (int i : {1, 2, 3, 4, 5, 6}) {
			int next = now + i;
			if (next > 100) continue;
			if (check[next] == -1 || check[next] > check[now] + 1) {
				if (teleport[next] == 0) {
					q.push(next);
					check[next] = check[now] + 1;
				}
				else {
					next = teleport[next];
					if (check[next] == -1 || check[next] > check[now] + 1) {
						q.push(next);
						check[next] = check[now] + 1;
					}
				}
			}
		}
	}
	cout << check[100];
}