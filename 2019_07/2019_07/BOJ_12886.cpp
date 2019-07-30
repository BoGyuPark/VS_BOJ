/*BOJ 12886 µ¹ ±×·ì*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct {
	int A, B, C;
}info;
int check[1001][1001];
int trans[3][3] = { {0,1,2},{0,2,1},{1,2,0} };
void visit_check(int t1, int t2, int t3) {
	check[t1][t2] = check[t2][t1] = t3; 
}

bool isPossible(int t1, int t2, int t3) {
	if (check[t1][t2] == t3)	return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a[3] = { 0, };
	int ans = 0;
	cin >> a[0] >> a[1] >> a[2];
	queue<info> q;
	sort(a, a + 3);
	q.push({ a[0], a[1], a[2] });
	visit_check(a[0], a[1], a[2]);
	while (!q.empty()) {
		int arr[3] = { 0, };
		arr[0] = q.front().A, arr[1] = q.front().B, arr[2] = q.front().C;
		q.pop();
		int a = arr[0], b = arr[1], c = arr[2];
		if (a == b && a == c && b == c) {
			ans = 1;
			break;
		}
		for (int i = 0; i < 3; i++) {
			//012 021 120
			int num1 = arr[trans[i][0]], num2 = arr[trans[i][1]], num3 = arr[trans[i][2]];
			if (num1 != num2) {
				int maxNum = max(num1, num2);
				int minNum = min(num1, num2);
				int next[3] = { 0, };
				maxNum -= minNum;
				minNum *= 2;
				if (maxNum > 0 && minNum > 0) {
					next[0] = minNum, next[1] = maxNum, next[2] = num3;
					sort(next, next + 3);
					if (isPossible(next[0], next[1], next[2])) {
						visit_check(next[0], next[1], next[2]);
						q.push({ next[0], next[1], next[2] });
					}
				}
			}
		}
	}
	cout << ans;
}