#include<iostream>
#include<stack>
using namespace std;
stack<pair<int, int>> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, temp; cin >> n;
	//index, value
	for (int i = 0; i < n; i++) {
		cin >> temp;
		while (!s.empty()) {
			int sv = s.top().second;
			if (sv > temp) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty() == 1) cout << "0 ";
		s.push(make_pair(i + 1, temp));
	}
}