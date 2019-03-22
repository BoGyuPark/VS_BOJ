#include<iostream>
#include<stack>
using namespace std;
int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int n; cin >> n;
		stack<char> s;
		int flag = false;
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			if (!flag) {
				if (c == '(' || c == '[' || c == '{' || c == '<') s.push(c);
				else {
					if (s.empty()) flag = true;
					if (c == ')') {
						if (s.top() == '(') s.pop();
						else flag = true;
					}
					else if (c == ']') {
						if (s.top() == '[') s.pop();
						else flag = true;
					}
					else if (c == '}') {
						if (s.top() == '{') s.pop();
						else flag = true;
					}
					else if (c == '>') {
						if (s.top() == '<') s.pop();
						else flag = true;
					}
				}
			}
		}
		if (s.size() > 0) flag = true;
		cout << '#' << tc << ' ' << !flag << '\n';
	}
}