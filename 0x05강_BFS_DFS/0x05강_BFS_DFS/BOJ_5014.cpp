#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int F, S, G, U, D, dis[1000001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	memset(dis, -1, sizeof(dis));
	queue<int> q;
	q.push(S);
	dis[S] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for (int i : {U, -D}) {
			int next = now + i;
			if (next > 0 && next <= 1000000 && dis[next] == -1) {
				dis[next] = dis[now] + 1;
				q.push(next);
			}
		}
	}
	if (dis[G] == -1) cout << "use the stairs";
	else cout << dis[G];
}
