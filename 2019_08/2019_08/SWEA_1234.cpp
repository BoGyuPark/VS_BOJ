/*1234. [S/W 문제해결 기본] 10일차 - 비밀번호*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int tc, n;
stack<char> s;
string ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (tc = 1; tc <= 10; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			if (s.empty()) s.push(c);
			else {
				if (s.top() == c) s.pop();
				else s.push(c);
			}
		}
		ans = "";
		while(!s.empty()){
			ans = s.top() + ans;
			s.pop();
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}