#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 200001
int from[MAX], dist[MAX], check[MAX], n, k;
int main() {
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	check[n] = true;
	dist[n] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur - 1 >= 0) {
			if (check[cur - 1] == false) {
				check[cur - 1] = true;
				dist[cur - 1] = dist[cur] + 1;
				from[cur - 1] = cur;
				q.push(cur - 1);
			}
		}
		if (cur +1 < MAX) {
			if (check[cur + 1] == false) {
				check[cur + 1] = true;
				dist[cur + 1] = dist[cur] + 1;
				from[cur + 1] = cur;
				q.push(cur + 1);
			}	
		}
		if (cur *2 < MAX) {
			if (check[cur * 2] == false) {
				check[cur * 2] = true;
				dist[cur * 2] = dist[cur] + 1;
				from[cur * 2] = cur;
				q.push(cur * 2);
			}
		}
	}
	cout << dist[k] << "\n";
	vector<int> v;
	int temp = k;
	v.push_back(temp);
	while (temp != n) {
		temp = from[temp];
		v.push_back(temp);
	}
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << ' ';
}