/*BOJ 3108 로고*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, check[1001], ans, flag;
struct info {
	int x1, y1, x2, y2;
};
vector<info> v;
queue<int> q;
bool isOverlap(int a, int b) {
	//안에 포함되거나
	if (v[a].x1<v[b].x1 && v[b].x2<v[a].x2 && v[a].y1<v[b].y1 && v[b].y2 < v[a].y2) 
		return false;
	
	//외부인 경우
	if (v[a].x1 > v[b].x1 && v[b].x2 > v[a].x2 && v[a].y1 > v[b].y1 && v[b].y2 > v[a].y2) 
		return false;
	//b가 오른쪽, 왼쪽, 아래, 위
	if (v[b].x1 > v[a].x2 || v[b].x2<v[a].x1 || v[a].y1 > v[b].y2 || v[b].y1 > v[a].y2)
		return false;
	
	return true;
}
void solve() {
	for (int i = 0; i < v.size(); i++) {
		if (check[i]) continue;
		if (i != 0) ans++;
		q.push(i);
		check[i] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int j = 0; j < v.size(); j++) {
				if (check[j]) continue;
				if (isOverlap(now,j)) {
					check[j] = true;
					q.push(j);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.push_back({ 0,0,0,0 });
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1,y1,x2,y2 });
	}
	solve();
	cout << ans;
}