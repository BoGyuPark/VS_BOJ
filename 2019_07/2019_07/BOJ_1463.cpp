/*BOJ 1463 1로 만들기*/
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n, ans = 0;
int check[1'000'001];
void cal() {
	memset(check, -1, sizeof(check));
	queue<int> q;
	q.push(n);
	check[n] = 0;
	while (!q.empty()) {
		int qSize = q.size();

		while (qSize--) {
			int now = q.front();
			q.pop();
			//1로 만든 경우
			if (now == 1) {
				ans = check[now];
				//cout << "답 : " << check[now] << '\n';
				return;
				/*ans = min(check[now], ans);
				continue;*/
			}
			int next;
			if (now % 3 == 0) {
				next = now / 3;
				if (check[next] == -1 || check[next] > check[now] + 1 ) {
					q.push(next);
					check[next] = check[now] + 1;
					//cout << 3 << ", " << now << "-> " << next << '\n';
				}
			}

			if (now % 2 == 0) {
				next = now / 2;
				if (check[next] == -1 || check[next] > check[now] + 1) {
					q.push(next);
					check[next] = check[now] + 1;
					//cout << 2 << ", " << now << "-> " << next << '\n';
				}
			}

			next = now - 1;
			if (check[next] == -1 || check[next] > check[now] + 1) {
				q.push(next);
				check[next] = check[now] + 1;
				//cout << -1 << ", " << now << "-> " << next << '\n';
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	if (n == 1) cout << 0;
	else {
		cal();
		cout << ans;
	}
}