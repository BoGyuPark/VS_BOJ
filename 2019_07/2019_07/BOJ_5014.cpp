/*BOJ 5014 스타트링크*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int F, S, G, U, D, check[1'000'001];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	memset(check, -1, sizeof(check));
	D = -D;
	q.push(S);
	check[S] = 0;
	while (!q.empty()) {
		int now = q.front();	q.pop();
		for (int i : {U, D}) {
			int next = now + i;
			if (next <= F && next >= 1) {
				if (check[next] == -1) {
					q.push(next);
					check[next] = check[now] + 1;
				}
			}
		}
	}
	if (check[G] == -1) cout << "use the stairs";
	else cout << check[G];
}
