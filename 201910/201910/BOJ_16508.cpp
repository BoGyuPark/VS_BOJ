/*BOJ 16508 Àü°øÃ¥*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, sel[17], targetAlpha[32], c[17], ans;
string T;
struct info {
	int cost;
	string name;
	int alpha[33];
};
vector<info> v;
void go(int remainCnt, int Sum) {
	if (remainCnt == 0) {
		ans = min(ans, Sum);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (c[i]) continue;
		int sameCnt = 0;
		int check[33] = { 0, };
		for (int j = 0; j < T.size(); j++) {
			if (v[i].alpha[T[j] - 'A'] > 0 && targetAlpha[T[j] - 'A'] > 0) {
				targetAlpha[T[j] - 'A']--;
				v[i].alpha[T[j] - 'A']--;
				check[T[j] - 'A']++;
				sameCnt++;
			}
		}

		if (sameCnt > 0) {
			c[i] = true;
			go(remainCnt - sameCnt, Sum + v[i].cost);
			for (int j = 0; j < 32; j++) {
				targetAlpha[j] += check[j];
				v[i].alpha[j] += check[j];
			}
			c[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T >> n;
	for (int i = 0; i < T.size(); i++) targetAlpha[T[i]- 'A']++;
	
	for (int i = 0; i < n; i++) {
		int t1; string t2;
		cin >> t1 >> t2;
		v.push_back({ t1,t2 });
	}

	//count alpha
	for (int i = 0; i < n; i++) {
		string s = v[i].name;
		for (int j = 0; j < s.size(); j++) v[i].alpha[s[j] - 'A']++;
	}
	ans = 2147483647;
	go(T.size(),0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}