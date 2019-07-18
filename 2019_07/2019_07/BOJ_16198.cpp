/*BOJ 16198 에너지 모으기*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, w[10], sel[10], cpy[10], ans;
void go(int index) {
	if (index == n - 2) {
		int result = 0;
		for (int j = 0; j < index; j++) {
			result += w[sel[j] - 1] * w[sel[j] + 1];
			//w를 옮겨주기
			for (int z = sel[j] + 1; z < n; z++) {
				w[z - 1] = w[z];
			}
		}
		ans = max(ans, result);
		//weight 원상 복귀
		for (int i = 0; i < n; i++) w[i] = cpy[i];
		return;
	}
	for (int i = 1; i < n - (1 + index); i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		cpy[i] = w[i];
	}
	ans = -1;
	go(0);
	cout << ans;
}