#include<iostream>
#include<queue>
using namespace std;
int bottle[3], check[201][201], ans[201];
int from[] = { 2,2,1,1,0,0 };
int to[] = { 1,0,2,0,2,1 };
int main() {
	cin >> bottle[0] >> bottle[1] >> bottle[2];
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	ans[bottle[2]] = true;
	while (!q.empty()) {
		int abc[3];
		abc[0] = q.front().first;
		abc[1] = q.front().second;
		abc[2] = bottle[2] - abc[0] - abc[1];
		q.pop();
		for (int i = 0; i < 6; i++) {
			int now = abc[from[i]];
			int next = abc[to[i]];
			next += now;
			if (next > bottle[to[i]]) {
				now = next - bottle[to[i]];
				next = bottle[to[i]];
			}
			else {
				now = 0;
			}
			int nx = abc[0], ny = abc[1];
			if (from[i] == 0) nx = now;
			else if (to[i] == 0) nx = next;
			if (from[i] == 1) ny = now;
			else if (to[i] == 1) ny = next;
			if (check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				if (nx == 0) ans[bottle[2] - nx - ny] = true;
			}
		}
	}
	for (int i = 0; i < 201; i++)
		if (ans[i] == true) cout << i << ' ';
}