/*BOJ 16508 Àü°øÃ¥*/
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
string T;
struct info {
	int cost;
	string name;
	int alpha[33];
	bool isAlive;
};
bool cmp(info a, info b) {
	return a.cost < b.cost;
}
int n, sel[17], targetAlpha[32], ans;
vector<info> v;
set<int> se;
void simulate() {
	int remainCnt = T.size();

	for (int Total = 0; Total < n; Total++) {
		int maxiIdx = -1, maxi = 0;
		for (int i = 0; i < v.size(); i++) {
			int sameCnt = 0;
			if (!v[i].isAlive) continue;
			for (int j = 0; j < 32; j++) {
				if (targetAlpha[j] == 0) continue;
				int dif = v[i].alpha[j] - targetAlpha[j];
				if (dif >= 0) {
					sameCnt += targetAlpha[j];
				}
			}

			if (maxi < sameCnt) {
				maxi = sameCnt;
				maxiIdx = i;
			}
		}

		if (maxiIdx != -1) {
			ans += v[maxiIdx].cost;
			v[maxiIdx].isAlive = false;
			string t = v[maxiIdx].name;
			for (int j = 0; j < t.size(); j++) {
				if (targetAlpha[t[j] - 'A'] > 0) {
					targetAlpha[t[j] - 'A']--;
					remainCnt--;
				}
			}
		}
		if (remainCnt == 0) return;
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
		v[i].isAlive = true;
	}
	sort(v.begin(), v.end(),cmp);
	ans = 0;
	simulate();
	if (ans == 0) ans = -1;
	cout << ans;
}