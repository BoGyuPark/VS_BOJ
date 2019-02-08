#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define MAX 100001
int t, check[MAX], dis[MAX], from[MAX];
char how[MAX];
void bfs(int A, int B) {
	queue<int> q;
	q.push(A);
	check[A] = true;
	dis[A] = 0;
	while (!q.empty()) {
		int cur = q.front();
		int next;
		q.pop();
		next = (cur * 2) % 10000;
		if (check[next] == false) {
			check[next] = true;
			q.push(next);
			dis[next] = dis[cur] + 1;
			how[next] = 'D';
			from[next] = cur;
		}
		next = (cur - 1);
		if (next < 0)	next = 9999;
		if (check[next] == false) {
			check[next] = true;
			q.push(next);
			dis[next] = dis[cur] + 1;
			how[next] = 'S';
			from[next] = cur;
		}
		next = (cur % 1000) * 10 + cur / 1000;
		if (check[next] == false) {
			check[next] = true;
			q.push(next);
			dis[next] = dis[cur] + 1;
			how[next] = 'L';
			from[next] = cur;
		}
		next = (cur / 10) + (cur % 10) * 1000;
		if (check[next] == false) {
			check[next] = true;
			q.push(next);
			dis[next] = dis[cur] + 1;
			how[next] = 'R';
			from[next] = cur;
		}
	}
	vector<int> v;
	int temp = B;
	while (A != temp) {
		v.push_back(temp);
		temp = from[temp];
	}
	for (int i = v.size() - 1; i >= 0; i--)		cout << how[v[i]];
	cout << "\n";
	memset(dis, 0, sizeof(dis));
	memset(check, 0, sizeof(check));
	memset(how, 0, sizeof(how));
	memset(from, 0, sizeof(from));
}
int main() {
	cin >> t;
	while (t--) {
		int A, B;
		cin >> A >> B;
		bfs(A, B);
	}
}