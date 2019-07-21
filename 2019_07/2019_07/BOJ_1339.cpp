/*BOJ 1339 단어 수학*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<string> str_arr;
vector<char> alpha;
bool check[30];
int sel[11], visited[11];
int value[30];
long long ans = 0;
void go(int index) {
	if (index == alpha.size()) {
		//해당하는 알파벳의 값 부여
		for (int j = 0; j < index; j++) {
			value[alpha[j] - 'A'] = sel[j];
		}

		long long sum = 0;
		for (int j = 0; j < str_arr.size(); j++) {
			long long temp = 0;
			for (int z = 0; z < str_arr[j].size(); z++) {
				temp *= 10;
				temp += value[str_arr[j][z] - 'A'];
			}
			sum += temp;
		}
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		sel[index] = i;
		go(index + 1);
		visited[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str_arr.push_back(s);
		for (int j = 0; j < s.size(); j++) {
			if (check[s[j] - 'A'] == true) continue;
			check[s[j] - 'A'] = true;
			alpha.push_back(s[j]);
		}
	}
	go(0);
	cout << ans;
}
