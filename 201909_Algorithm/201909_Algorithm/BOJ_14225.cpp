/*BOJ 14225 부분수열의 합*/
#include<iostream>
using namespace std;
#define MAX 100001 * 20
bool check[MAX];
int n, ans, arr[21], sel[21];
void go(int index, int sum) {
	if (index == n) {
		check[sum] = true;
		return;
	}
	for (int i = 0; i < 2; i++) {
		if(i==1) go(index + 1, sum + arr[index]);
		else go(index + 1, sum);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	go(0, 0);
	for (int i = 1; i <= MAX; i++) 
		if (!check[i]) {ans = i; break;}
	cout << ans;
}