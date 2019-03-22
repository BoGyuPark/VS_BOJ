#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int n; cin >> n;
		stack<char> op;
		vector<char> post;
		for (int i = 0; i < n; i++) {
			char a;	cin >> a;
			if (a - '0' >= 0 && a - '0' <= 9) post.push_back(a);
			else {
				if (op.empty()) op.push(a);
				else {
					if (a == '(') op.push(a);
					else if (a == ')') {
						while (op.top() != '(') {
							post.push_back(op.top());
							op.pop();
						}
						op.pop();
					}
					else {
						if (op.top() == '+') {
							if (a == '+') {
								while (op.top() != '(') {
									post.push_back(op.top());
									op.pop();
								}
								op.push(a);
							}
							else {
								op.push(a);
							}
						}
						//스택연산자가 *
						else {
							if (a == '+') {
								while (op.top() != '(') {
									post.push_back(op.top());
									op.pop();
								}
								op.push(a);
							}
							else {
								while (op.top() == '*') {
									post.push_back(op.top());
									op.pop();
								}
								op.push(a);
							}
						}
					}
				}
			}
		}
		while (!op.empty()) {
			post.push_back(op.top());
			op.pop();
		}
		//계산
		stack<int> cal;
		for (auto i : post) {
			if (i - '0' >= 0 && i - '0' <= 9) cal.push(i - '0');
			else {
				int t1, t2;
				t2 = cal.top(); cal.pop();
				t1 = cal.top(); cal.pop();
				if (i == '*') cal.push(t1*t2);
				else cal.push(t1 + t2);
			}
		}
		cout << '#' << tc << ' ' << cal.top() << '\n';
	}
}