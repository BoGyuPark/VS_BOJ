#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAX 1'000'001
int F, S, G, U, D;
int arr[1'000'001];
int check[MAX];
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	memset(check, -1, sizeof(check));
	check[S] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == G) break;
		for (int i : {U, -D}) {
			int next = now + i;
			if (next<0 || next>F) continue;
			if (check[next] != -1) continue;
			check[next] = check[now] + 1;
			q.push(next);
		}
	}
	if (check[G] == -1) cout << "use the stairs";
	else cout << check[G];
}