#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n, k, check[27], ans = 0;
vector<string> vs;
int go(int index, int cnt) {
	if (cnt == k - 5) {
		int count = 0;
		for (int s = 0; s < n; s++) {
			int flag = 0;
			for (int d = 0; d < vs[s].size(); d++) {
				if (check[vs[s][d] - 'a'] == false) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) count++;
		}
		if (ans < count) ans = count;
		return ans;
	}
	for (int i = index; i < 26; i++) {
		if (check[i] == false) {
			check[i] = true;
			go(i, cnt + 1);
			check[i] = false;
		}
	}
	return ans;
}

int main() {
	cin >> n >> k;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		s = s.substr(4, s.size() - 8);
		vs.push_back(s);
	}
	check['a' - 'a'] = check['c' - 'a'] = check['i' - 'a'] = check['n' - 'a'] = check['t' - 'a'] = true;
	cout << go(0, 0);
}













//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int n, k;
//int count(int mask, vector<int> &words) {
//	int cnt = 0;
//	for (int word : words) {
//		if ((word & ((1 << 26) - 1 - mask)) == 0){
//		cnt += 1;
//		}
//	}
//	return cnt;
//}
//
//int go(int index, int k, int mask, vector<int> &words) {
//	if (k < 0) return 0;
//	if (index == 26) return count(mask, words);
//	int ans = 0;
//	int t1 = go(index + 1, k - 1, mask | (1 << index), words);
//	if (ans < t1) ans = t1;
//	if (index != 'a' - 'a' && index != 'c' - 'a'&&index != 'i' - 'a'&&index != 'n' - 'a'&&index != 't' - 'a') {
//		t1 = go(index + 1, k, mask, words);
//		if (ans < t1) ans = t1;
//	}
//	return ans;
//}
//
//int main() {
//	cin >> n >> k;
//	string s;
//	vector<int> words(n);
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		for (int j = 0; j < s.size(); j++) {
//			words[i] |= (1 << (s[j] - 'a'));
//		}
//	}
//	cout << go(0, k, 0, words);
//}