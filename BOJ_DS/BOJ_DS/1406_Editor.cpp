//BOJ_1406_Editor
#include<bits/stdc++.h>
using namespace std;
int main() {
	char arr[600001]; cin >> arr;
	int N, i = 0; cin >> N;
	stack<char> left,right; int len = strlen(arr);
	while (len--) {
		left.push(arr[i]);
		i++;
	}
	while (N--) {
		char c, temp; cin >> c;
		if (c == 'L' && !left.empty()) {
			right.push(left.top());
			left.pop();
		}
		else if (c == 'D' && !right.empty()) {
			left.push(right.top());
			right.pop();
		}
		else if (c == 'B' && !left.empty()) {
			left.pop();
		}
		else if (c == 'P') {
			cin >> temp;
			left.push(temp);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}








//�ð����⵵�� O(N^2)�̱� ������ �ȵȴ�.
//�ѱ��̰� 60���̱� ������ �� 3600�� -> 1���� 1�ʶ� �� ��� 1�ð� �ɸ�....
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	string s; cin >> s;
//	int N; cin >> N;
//	int cursor;
//	cursor= s.length();
//	for (int i = 0; i < N; i++) {
//		char c; cin >> c;
//		if (c == 'L' && cursor != 0) {
//			cursor--;
//		}
//		else if (c == 'D' && s[cursor] != NULL) {
//			cursor++;
//		}
//		else if (c == 'B' && cursor != 0) {
//			cursor--;
//			s.erase(cursor, 1);
//		}
//		else if (c == 'P'){
//			string temp;
//			cin >> temp;
//			s.insert(cursor, temp);
//			cursor++;
//		}
//	}
//	cout << s;
//	return 0;
//}