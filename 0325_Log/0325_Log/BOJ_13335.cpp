#include<iostream>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, w, l, t;
	cin >> n >> w >> l;
	queue<int> q;
	int cnt = 0, sum = 0;;
	for (int i = 0; i < n; i++) {
		cin >> t;
		while (true) {
			if (q.size() == 0) {
				q.push(t);
				sum += t;
				cnt++;
				break;
			}
			else if (q.size() == w) {
				sum -= q.front();
				q.pop();
			}
			else {
				if (sum + t <= l) {
					sum += t;
					q.push(t);
					cnt++;
					break;
				}
				else {
					q.push(0);
					cnt++;
				}
			}
		}
	}
	cout << cnt + w;
}