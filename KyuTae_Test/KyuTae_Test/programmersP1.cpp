#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	map<string, int> m;
	int answer = 1;
	int rowCnt = clothes.size();
	for (int i = 0; i < rowCnt; i++) {
		m[clothes[i][1]]++;
	}
	for (auto &i : m) {
		answer *= (i.second + 1);
	}
	answer--;
	return answer;
}

int main() {
	int n;
	cin >> n;
	string clothName, cate;
	vector<vector<string>> clothes;
	
	for (int i = 0; i < n; i++) {
		cin >> clothName >> cate;
		clothes.push_back(vector<string>());
		clothes[i].push_back(clothName);
		clothes[i].push_back(cate);
	}
	cout << solution(clothes);
}