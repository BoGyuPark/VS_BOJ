#include <iostream>
#include <queue>
using namespace std;
int a[200001], check[200001];
int main(void) {
	int c, b;
	cin >> c >> b;
	//코닌의 위치를 다 저장해놓는다.
	int num = 1;
	queue<int> q;
	q.push(b);
	check[b] = 1;
	int ans = -1;
	int found = false;
	while (true) {
		//코니 움직임
		int prev;
		prev = c;
		a[c] = c;
		c += num;
		num++;
		if (c > 200001) break;

		int QSize = q.size();
		while (QSize--){
			int now = q.front();
			q.pop();
			if (now == prev) {
				ans = check[now];
				found = true;
				break;
			}
			if (now - 1 >= 0) {
				int nx = now - 1;
				if (check[nx] == false) {
					check[nx] = check[now] + 1;
					q.push(now - 1);
				}
			}
			if (now + 1 <= 200000) {
				int nx = now + 1;
				if (check[nx] == false) {
					check[nx] = check[now] + 1;
					q.push(now + 1);
				}
			}
			if (now * 2 <= 200000) {
				int nx = now * 2;
				if (check[nx] == false) {
					check[nx] = check[now] + 1;
					q.push(now * 2);
				}
			}
		}
		if (found) break;
	}
	cout << (ans == -1 ? -1 : ans - 1);
	return 0;
}