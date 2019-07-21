/*BOJ 16397 탈출*/
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
#define MAX 99999
int n, t, g, ans;
queue<int> q;
int check[1'000'000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t >> g;
	memset(check, -1, sizeof(check));
	q.push(n);
	check[n] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == g || check[now] > t) {
			if (check[now] > t) ans = -1;
			else ans = check[now];
			break;
		}
		
		int next;
		//A버튼 누른 경우, +1 증가
		next = now + 1;
		if (check[next] == -1 || check[next] > check[now] + 1) {
			q.push(next);
			check[next] = check[now] + 1;
		}

		//B버튼 누른 경우
		next = now * 2;
		if (next < MAX) {
			if (next == 0) continue;
			string s = to_string(next);
			s[0] = s[0] - 1;
			next = stoi(s);
			if (check[next] == -1 || check[next] > check[now] + 1) {
				q.push(next);
				check[next] = check[now] + 1;
			}
		}
	}

	if (ans == -1) cout << "ANG";
	else cout << ans;
}
