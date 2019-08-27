/*5658. [모의 SW 역량테스트] 보물상자 비밀번호*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int T, tc, n, k, pivot;
char arr[29];
vector<string> v;
string s;

void insertPassward() {
	for (int i = 0; i < n; i += pivot) {
		s = "";
		for (int j = i; j < i + pivot; j++) s += arr[j];
		v.push_back(s);
	}
}

void RotatePassword() {
	char temp = arr[n - 1];
	for (int i = n - 1; i >0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> arr[i];
		pivot = n / 4;
		for (int i = 0; i < pivot; i++) {
			insertPassward();	
			if (i != pivot - 1)	RotatePassword();
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		string ans = v[v.size() - k];
		int sum = 0, mul = 1;
		for (int i = ans.size() - 1; i >= 0; i--) {
			char c = ans[i];
			if (isdigit(c)) sum += mul * (c - '0');
			else sum += mul * (c - 'A' + 10);
			mul *= 16;
		}
		cout << '#' << tc << ' ' << sum << '\n';
		v.clear();

	}
}