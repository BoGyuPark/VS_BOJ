/*BOJ 1252 이진수 덧셈*/
#include<iostream>
#include<string>
#include<stack>
#include<cstring>
using namespace std;
stack<char> st1, st2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) st1.push(s1[i]);
	for (int i = 0; i < s2.size(); i++) st2.push(s2[i]);

	int carry = 0;
	string ans = "";
	int t1 = 0, t2 = 0;
	int st1Flag = false, st2Flag = false;
	while (true) {
		if (!st1.empty()) {
			t1 = st1.top() - '0';
			st1.pop();
		}
		else {
			t1 = 0;
			st1Flag = true;
		}

		if (!st2.empty()) {
			t2 = st2.top() - '0';
			st2.pop();
		}
		else {
			t2 = 0;
			st2Flag = true;
		}
		if (st1Flag&&st2Flag) break;

		int sum = t1 + t2 + carry;
		if (sum == 3) {
			carry = 1;
			ans = '1' + ans;
		}
		else if (sum == 2) {
			carry = 1;
			ans = '0' + ans;
		}
		else {
			ans = (char)(sum + '0') + ans;
			carry = 0;
		}
	}
	if (carry == 1) { ans = '1' + ans; }

	int flag = false;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == '1') flag = true;
	}

	if (flag == false) cout << 0;
	else {
		//앞에 0제거
		int idx = -1;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == '1') {
				idx = i;
				break;
			}
		}
		ans = ans.substr(idx);
		cout << ans;
	}
}