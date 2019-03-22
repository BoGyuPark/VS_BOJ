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
		//���������� �ٲٱ�
		for (int i = 0; i < n; i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) v.push_back(a[i]);
			else {
				if (op.size() == 0) op.push(a[i]);
				else {
					char t = op.top();
					if (t == '+') {
						//�����ڰ� ��ų� '+' �϶����� pop
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
					//���ÿ����ڰ� '*'
					else {
						if (a[i] == '+') {
							while (!op.empty()) {
								v.push_back(op.top());
								op.pop();
							}
							op.push(a[i]);
						}
						//�켱������ ������ ������ ���ö����� pop�ϰ� push
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

		//���
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