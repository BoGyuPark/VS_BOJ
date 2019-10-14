/*BOJ 10552 DOM */
#include<iostream>
#include<vector>
using namespace std;
int n, m, startNum;
int favourite[100'001], check[100'001];
vector<int> hate[100'001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	cin >> n >> m >> startNum;
	for (int i = 1; i <= n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		favourite[i] = t1;
		hate[t2].push_back(i);
	}
	
	int cnt = 0, cycleFlag = false;
	while (true)
	{
		if (hate[startNum].empty()) {
			break;
		}
		cnt++;
		int next = hate[startNum][0];
		if (check[next]) {
			cycleFlag = true;
			break;
		}
		check[next] = true;
		startNum = favourite[next];
	}
	if (cycleFlag) cnt = -1;
	cout << cnt;
}