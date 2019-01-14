//BOJ_10799_IronRod
#include<bits/stdc++.h>
using namespace std;
int main() {
	stack<char> s;
	string arr; cin >> arr;
	int sum = 0;
	for (int i = 0; i < arr.length(); i++) {
		if (arr[i] == '(') {
			s.push(arr[i]);
		}
		else if (arr[i] == ')' && arr[i-1]=='(') {
			s.pop();
			sum += s.size();
		}
		else if (arr[i] == ')' && s.top() == '(') {
			s.pop();
			sum++;
		}
	}
	cout << sum;
	return 0;
}