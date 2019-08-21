/*BOJ 16937 두 스티커*/
#include<iostream>
#include<vector>
using namespace std;
int n, m, k, c[204], sel[2], ans;
typedef struct {
	int x, y, idx;
}info;
vector<info> v;	// 스티커 집합
void go(int index,int start) {
	if (index == 2) {
		int area = 0;
		int r1 = v[sel[0]].x, c1 = v[sel[0]].y, idx1 = v[sel[0]].idx;
		int r2 = v[sel[1]].x, c2 = v[sel[1]].y, idx2 = v[sel[1]].idx;

		if (idx1 == idx2) return;
		//가로로 붙은 경우
		if (c1 + c2 <= m && r1 <= n && r2 <= n) area = r1 * c1 + r2 * c2;
		
		//세로로 붙은 경우
		if (r1 + r2 <= n && c1 <= m && c2 <= m) area = r1 * c1 + r2 * c2;
		
		if (ans < area) ans = area;

		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		v.push_back({ r,c,i });
		if (r != c)	v.push_back({ c,r,i });	//회전
	}
	go(0, 0);
	cout << ans;
}