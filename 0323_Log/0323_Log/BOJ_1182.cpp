#include<iostream>
using namespace std;
int n, s, a[21], sum = 0, cnt = 0, sel[21], c[21];
void dfs(int index, int sum) {
	if (index == n) {
		if (sum == s) { 	//원하는 값이 나온경우
			cnt++;
			return;
		}
		else return;					//아닌경우 사전에 차단
	}
	dfs(index + 1, sum + a[index]); 	//부분합을 선택한경우
	dfs(index + 1, sum); 				//부분합을 선택하지 않은 경우

}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	dfs(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}