/*BOJ 16943 A->B*/
#include<iostream>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
int A, B, ans = -1;
set<ll> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;
	queue<pair<ll,ll>> q;
	q.push({ A,1 });
	s.insert(A);
	while (!q.empty()) {
		ll now = q.front().first, dist = q.front().second;
		q.pop();
		if (now == B) {
			ans = dist;
			break;
		}
		for (ll next : {now * 2, now * 10 + 1}) {
			if (next <= B && s.find(next) == s.end()) {
				q.push({ next,dist + 1 });
				s.insert(next);
			}
		}
	}
	cout << ans;
}