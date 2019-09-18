/*SWEA 1251 하나로*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<limits.h>
using namespace std;
int T, tc,n, xList[1001], yList[1001];
double e;
int check[1001];
long double sum;
void go(int depth) {
	if (depth == n) return;

	//가장 작은 가중치 (내가 지나온 경로 중에)
	long long mini = LLONG_MAX, idx = -1;
	int now = -1;
	for (int i = 0; i < n; i++) {
		if (check[i] == true) {
			for (int j = 0; j < n; j++) {
				if (check[j] == true) continue;
				long long t1 = abs(xList[i] - xList[j]);
				long long t2 = abs(yList[i] - yList[j]);
				long long dif = t1*t1 + t2 * t2;
				if (mini > dif) {
					mini = dif;
					idx = j;
					now = i;
				}
			}
		}
	}
	
	check[idx] = true;
	sum += mini*e;
	go(depth + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> xList[i];
		for (int i = 0; i < n; i++) cin >> yList[i];
		cin >> e;
		sum = 0;
		check[0] = true;
		go(1);
		memset(check, 0, sizeof(check));
		cout << fixed;
		cout.precision(0);
		cout << '#' << tc << ' ' << round(sum) << '\n';
	}
}