/*BOJ 3015 오아시스 재결합*/
//스택을 사용하자아!
#include<iostream>
#include<stack>
using namespace std;
int n, t;
long long ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> t;
	stack<int> s; s.push(t);
	for (int i = 1; i < n; i++) {
		cin >> t;
		if (s.top() < t) {
			ans += s.size();

			while (true) {
				if (s.empty()) break;
				if (s.top() > t) break;
				s.pop();
			}
			s.push(t);
		}
		else {
			ans += s.size();
			s.push(t);
		}
	}
	cout << ans;
}