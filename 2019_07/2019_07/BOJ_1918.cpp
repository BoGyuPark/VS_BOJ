/*BOJ 1918 후위 표기식*/
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
				// '(' 이면 무조건 푸쉬
				if (s[i] == '(') op.push(s[i]);
				// ')' 면 '('나올때까지 뿌리고 팝
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
				// 나머지 연산자인 경우 스택이 비지않고
				// 현재 읽은 연산자의 우선순위 >= top의 우선순위 까지 
				// (우선순위가 같거나 나보다 빨리 빼야하는 것을 pop
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