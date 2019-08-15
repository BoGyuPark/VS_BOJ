/*BOJ 17394 ÇÎ°Å ½º³À*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 100'001
int T, prime[MAX], n, a, b, check[1'000'001], ans;
vector<int> v;
void findPrime(int s, int e) {
	for (int i = s; i <= e; i++) {
		if (prime[i]) continue;
		v.push_back(i);
	}
}
void checkNext(int now,int next, queue<int> &q) {
	if (check[next] == -1) {
		q.push(next);
		check[next] = check[now] + 1;
	}
}
void bfs(int n){
	queue<int> q;
	memset(check, -1, sizeof(check));
	q.push(n);
	check[n] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		int next;
		
		next = now / 2;
		checkNext(now, next, q);

		next = now / 3;
		checkNext(now, next, q);
		
		if (now < MAX) {
			next = now + 1;
			checkNext(now, next, q);
		}

		if (now > 0) {
			next = now - 1;
			checkNext(now, next, q);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= n) {
			if (ans > check[v[i]]) ans = check[v[i]];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) continue;
		for (int j = i * 2; j < MAX; j += i) prime[j] = true;
	}
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> a >> b;
		v.clear();
		if (a <= n && n <= b && !prime[n]) cout << 0 << '\n';
		else {
			findPrime(a, b);
			if (v.size() == 0) cout << -1 << '\n';
			else {
				ans = 2147483647;
				for (int i = 0; i < v.size(); i++) {
					int cnt = -1;
					if (v[i] > n) cnt = v[i] - n;
					if (cnt!= -1 && ans > cnt) ans = cnt;
				}
				bfs(n);
				if (ans == 2147483647) cout << -1 << '\n';
				else cout << ans << '\n';
			}
		}
	}
}