//BOJ_11656_SuffixArray
#include<bits/stdc++.h>
using namespace std;
int main() {
	char s[1001];	cin >> s;
	vector<string> arr;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		char temp[1001] = { 0, };
		for (int j = 0; j < len - i; j++) {
			temp[j] = s[j + i];
		}
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int vSize = arr.size();
	for (int i = 0; i < vSize; i++)
		cout << arr[i] << "\n";

	return 0;
}