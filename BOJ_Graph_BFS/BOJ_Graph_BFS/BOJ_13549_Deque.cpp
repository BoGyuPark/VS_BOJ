#include<iostream>
#include<deque>
#define MAX 1000000
using namespace std;
deque<int> dq;
int check[MAX], dis[MAX];
int main() {
	int n, k; cin >> n >> k;
	dq.push_back(n);
	check[n] = true; dis[n] = 0;
	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		if (cur * 2 < MAX && check[cur * 2] == false) {
			check[cur * 2] = true;
			dis[cur * 2] = dis[cur];
			dq.push_front(cur * 2);
		}
		if (cur + 1 < MAX && check[cur + 1] == false) {
			check[cur + 1] = true;
			dis[cur + 1] = dis[cur] + 1;
			dq.push_back(cur + 1);
		}
		if (cur - 1 >= 0 && check[cur - 1] == false) {
			check[cur - 1] = true;
			dis[cur - 1] = dis[cur] + 1;
			dq.push_back(cur - 1);
		}
	}
	cout << dis[k];
	return 0;
}