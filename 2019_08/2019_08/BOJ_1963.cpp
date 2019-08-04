/*BOJ 1963 소수 경로*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#define MAX 10000
using namespace std;
bool arr[10001];
int check[10001];
int T;
vector<int> findNextPrime(int num) {
	vector<int> temp;
	string origin = to_string(num);
	string str;
	for (int i = 0; i < 4; i++) {
		str = origin;
		for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) continue;
			if (origin[i] == (j + '0')) continue;
			str[i] = (j + '0');
			int next = stoi(str);
			if (arr[next] == false) temp.push_back(next);
		}
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j < MAX; j += i) arr[j] = true;
	}
	cin >> T;
	int s, dest;
	for (int tc = 0; tc < T; tc++) {
		cin >> s >> dest;
		if (s == dest) cout << 0 << '\n';
		else {
			memset(check, -1, sizeof(check));
			queue<int> q;
			q.push(s);
			check[s] = 0;
			while (!q.empty()) {
				int now = q.front(); q.pop();
				vector<int> possibleList = findNextPrime(now);
				for (auto & next : possibleList) {
					if (check[next] == -1) {
						q.push(next);
						check[next] = check[now] + 1;
					}
				}
			}
			cout << check[dest] << '\n';
		}
	}
	return 0;
}