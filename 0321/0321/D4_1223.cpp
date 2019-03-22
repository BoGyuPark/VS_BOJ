#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		int n; cin >> n;
		char a[200];
		stack<char> op;
		stack<int> cal;
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<char> v;
		//후위식으로 바꾸기
		for (int i = 0; i < n; i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) v.push_back(a[i]);
			else {
				if (op.size() == 0) op.push(a[i]);
				else {
					char t = op.top();
					if (t == '+') {
						//연산자가 비거나 '+' 일때까지 pop
						if (a[i] == '+') {
							while (!op.empty()) {
								v.push_back(op.top());
								op.pop();
							}
							op.push(a[i]);
						}
						else {
							op.push(a[i]);
						}
					}
					//스택연산자가 '*'
					else {
						if (a[i] == '+') {
							while (!op.empty()) {
								v.push_back(op.top());
								op.pop();
							}
							op.push(a[i]);
						}
						//우선순위가 같으면 낮은게 나올때까지 pop하고 push
						else {
							while (op.top() == '+') {
								v.push_back(op.top());
								op.pop();
							}
							op.push(a[i]);
						}
					}
				}
			}
		}
		while (!op.empty()) {
			v.push_back(op.top());
			op.pop();
		}

		//계산
		for (auto i : v) {
			if (i - '0' >= 0 && i - '0' <= 9) cal.push(i - '0');
			else {
				int t1, t2;
				t2 = cal.top();
				cal.pop();
				t1 = cal.top();
				cal.pop();
				if (i == '+') 	cal.push(t1 + t2);
				else cal.push(t1 * t2);
			}
		}

		cout << '#' << tc << ' ' << cal.top() << '\n';
	}
}