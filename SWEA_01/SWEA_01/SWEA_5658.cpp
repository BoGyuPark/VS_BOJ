#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;
int T, t, n, k;
bool cmp(string a, string b) {
	return (a > b);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (t = 1; t <= T; t++) {
		vector<string> ans;
		cin >> n >> k;
		char a[30];
		for (int i = 0; i < n; i++) cin>>a[i];
		int temp = n / 4;
		while (temp--) {
			//string 벡터에 저장
			for (int i = 0; i < n; i += n / 4) {
				string s = "";
				for (int j = 0; j < n / 4; j++) {
					s += a[i + j];
				}
				ans.push_back(s);
			}
			if (temp == 0) break;
			//rotate
			char tt = a[n - 1];
			for (int z = n - 1; z > 0; z--) a[z] = a[z - 1];
			a[0] = tt;
		}
		sort(ans.begin(), ans.end(), greater<string>());
		//sort(ans.begin(), ans.end(), cmp);
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		//k번째 10진수로 변환
		string s = ans[k - 1];
		long long sum = 0, mul = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if(s[i]>='0' && s[i]<='9')	sum += mul * (s[i]-'0');
			else sum += mul * (s[i] - 'A' + 10);
			mul *= 16;
		}
		cout << '#' << t << ' ' << sum << '\n';
	}
}
