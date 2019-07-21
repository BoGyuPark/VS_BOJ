/*BOJ 1107 리모컨*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, ans, finishFlag;
int sel[7];
bool possibleNumCheck[10];
vector<int> pNum;
void goOne(int index, int maxLen) {
	if (finishFlag == true) return;
	if (index == maxLen) {
		int num_made = 0;
		for (int j = 0; j < maxLen; j++) {
			num_made = num_made * 10 + sel[j];
		}
		ans = min(ans, abs(num_made - n) + maxLen);
		finishFlag = true;
		//cout << num_made << '\n';
		return;
	}
	for (int i = 0; i < pNum.size(); i++) {
		if (pNum[i] == 0 && index == 0) continue;
		sel[index] = pNum[i];
		goOne(index + 1, maxLen);
	}
}
void go(int index, int maxLen) {
	if (index == maxLen) {
		int num_made = 0;
		for (int j = 0; j < maxLen; j++) {
			num_made = num_made * 10 + sel[j];
		}
		ans = min(ans, abs(num_made - n) + maxLen);
		return;
	}
	for (int i = pNum.size() - 1; i >= 0; i--) {
		sel[index] = pNum[i];
		go(index + 1, maxLen);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		possibleNumCheck[temp] = true;
	}
	for (int i = 0; i < 10; i++) if (!possibleNumCheck[i]) pNum.push_back(i);
	ans = 2147483647;
	if (n == 100) {
		cout << 0;
	}
	else {
		//100에서 +,- 만 누른 경우
		ans = min(ans, abs(n - 100));

		//버튼을 누른 후 +,-를 누른 경우
		int temp = n;
		int len = 1;
		while (temp != 0) {
			temp /= 10;
			len++;
		}
		for (int i = 1; i <= len; i++) {
			go(0, i);
		}

		// n의 자릿수 + 1 인 제일작은 숫자에서 -를 하는 개수
		goOne(0, len + 1);
		cout << ans;
	}
}