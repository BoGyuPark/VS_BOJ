/*BOJ 15971 두 로봇*/
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int n, startNum, endNum, ans = 2147483647;
vector<pair<int, int>> v[100001];
int se[100001], es[100001];
int check[100001];
int flag = false;
int maxLen;
string str[100001];
//path : 누적 길이
void go(int index, int s, int e, int Len, int path[100001]) {
	int now = s;
	for (int i = 0; i < v[s].size(); i++) {
		int next = v[s][i].first, nextLen = v[s][i].second + Len;
		if (check[next] == 0) {
			path[index] = nextLen;

			str[index + 1] = to_string(next);

			if (next == e) {
				if (ans > Len) ans = Len;
				flag = true;
				maxLen = index + 1;
				return;
			}
			check[next] = true;
			go(index + 1, next, e, nextLen, path);
			if (flag) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> startNum >> endNum;
	for (int i = 0; i < n - 1; i++) {
		int U, V, len;
		cin >> U >> V >> len;
		v[U].push_back({ V, len });
		v[V].push_back({ U,len });
	}

	check[endNum] = true;
	go(0, endNum, startNum, 0, es);
	memset(check, 0, sizeof(check));
	
	flag = false;
	check[startNum] = true;
	go(0, startNum, endNum, 0, se);

	str[0] = to_string(startNum);
	for (int i = 0; i < maxLen; i++) {
		int u = stoi(str[i]);
		int pivot = 0;
		for (int j = 0; j < v[u].size(); j++) {
			if (v[u][j].first == stoi(str[i + 1])) {
				pivot = v[u][j].second;
				break;
			}
		}
		if (ans > se[i] + es[maxLen - i - 1] - pivot * 2) 
			ans = se[i] + es[maxLen - i - 1] - pivot * 2;
	}
	cout << ans;
}