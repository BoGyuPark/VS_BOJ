/* BOJ 2661 좋은수열*/
#include<iostream>
#include<string>
using namespace std;
int n,flag;
bool isPossible(string str) {

	string pivot = "";
	int pivotIdx = str.size() - 1;
	pivot += str[pivotIdx];

	int targetIdx = str.size() - 2;
	string target = "";
	target += str[targetIdx];
	int strLen = 1;

	while (true)
	{
		if (pivot == target) return false;
		strLen++;
		pivotIdx--;
		pivot = str[pivotIdx] + pivot;
		target.clear();
		targetIdx = pivotIdx - strLen;
		if (targetIdx < 0) return true;
		for (int i = targetIdx; i < targetIdx + strLen; i++) {
			target += str[i];
		}
	}
}

void go(int index, string s) {
	if (flag) return;	
	if (index == n) {
		cout << s;
		flag = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (s.size()==0 || isPossible(s + to_string(i))) {
			go(index + 1, s + to_string(i));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	go(0,"");
}