/*BOJ 1158 조세퍼스 문제*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, k;
vector<int> v;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) q.push(i + 1);
	int cnt = 1;
	int idx = k - 1;

	while (!q.empty()) {
		//k칸 이동
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
		cnt++;
		//if (cnt == n) break;
	}
	cout << '<';
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) cout << v[i];
		else cout << v[i] << ", ";
	}
	cout << '>';
}