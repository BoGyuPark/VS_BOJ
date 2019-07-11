/*BOJ 1406 에디터 투 스택, 링크드 리스트*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s >> n;
	stack<char> curser_Left, curser_Right;
	for (int i = 0; i < s.size(); i++) {
		curser_Left.push(s[i]);
	}

	for (int i = 0; i < n; i++) {
		char cm;
		cin >> cm;
		if (cm == 'L') {
			if (!curser_Left.empty()) {
				curser_Right.push(curser_Left.top());
				curser_Left.pop();
			}
		}
		else if (cm == 'D') {
			if (!curser_Right.empty()) {
				curser_Left.push(curser_Right.top());
				curser_Right.pop();
			}
		}
		else if (cm == 'B') {
			if (!curser_Left.empty()) {
				curser_Left.pop();
			}
		}
		else {
			char temp;
			cin >> temp;
			curser_Left.push(temp);
		}
	}

	while (!curser_Left.empty()) {
		curser_Right.push(curser_Left.top());
		curser_Left.pop();
	}
	while (!curser_Right.empty()) {
		cout << curser_Right.top();
		curser_Right.pop();
	}
}
