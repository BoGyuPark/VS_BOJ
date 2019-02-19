#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n;	deque<int> q; cin >> n;
	for (int i = 1; i <= n; i++) q.push_back(i);
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop_front();
		if (q.empty()) break;
		q.push_back(q.front());
		q.pop_front();
	}
}