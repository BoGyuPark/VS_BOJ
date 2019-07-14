/*BOJ 1918 ���� ǥ���*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int order[100];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	stack<char> op;
	order['+'] = order['-'] = 2;
	order['*'] = order['/'] = 1;
	order['('] = 3;
	for (int i = 0; i < s.size(); i++)
	{
		if ('A' <= s[i] && s[i] <= 'Z') cout << s[i];
		else
		{
			if (!op.empty()) {
				// '(' �̸� ������ Ǫ��
				if (s[i] == '(') op.push(s[i]);
				// ')' �� '('���ö����� �Ѹ��� ��
				else if (s[i] == ')') {
					while (!op.empty()) {
						if (op.top() == '(') {
							op.pop();
							break;
						}
						cout << op.top();
						op.pop();
					}
				}
				// ������ �������� ��� ������ �����ʰ�
				// ���� ���� �������� �켱���� >= top�� �켱���� ���� 
				// (�켱������ ���ų� ������ ���� �����ϴ� ���� pop
				else {
					while(!op.empty() && order[s[i]] >= order[op.top()]) {
						cout << op.top();
						op.pop();
					}
					op.push(s[i]);
				}
			}
			else {
				op.push(s[i]);
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
}