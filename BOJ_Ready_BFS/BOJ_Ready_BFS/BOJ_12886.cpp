#include<iostream>
#include<queue>
using namespace std;
int a, b, c, sum;
int check[1500][1500];
void bfs(int x, int y) {
	queue<pair<int,int>> q;
	check[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int nowx = q.front().first, nowy = q.front().second;
		q.pop();
		int info[] = { nowx,nowy,sum - nowx - nowy };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (info[i] < info[j] && check[info[i]][info[j]]==false) {
					int t[] = { nowx,nowy,sum - nowx - nowy };
					t[i] += info[i];
					t[j] -= info[i];
					q.push({ t[0],t[1] });
					check[t[0]][t[1]] = true;
				}
			}
		}
	}
}
int main() {
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0) cout << 0;
	if (a == b == c) cout << 1;
	else {
		bfs(a, b);
		if (check[sum / 3][sum / 3]) cout << 1;
		else cout << 0;
	}
}