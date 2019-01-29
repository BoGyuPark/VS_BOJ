#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, alphaNum, sum = 0, tempsum = 0;
vector<string> vs;
vector<char> vc;
string temp;
vector<int> vnum;
char c[256];
int main() {
	cin >> n; ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < n; i++) {
		cin >> temp;	vs.push_back(temp);
		for (int j = 0; j < temp.size(); j++)
			vc.push_back(temp[j]);
	}
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());
	alphaNum = vc.size();
	int ans = 0;
	for (int i = 9; i > 9 - alphaNum; i--) 	vnum.push_back(i);
	sort(vnum.begin(), vnum.end());
	do {
		tempsum = 0;
		for (int i = 0; i < alphaNum; i++)	c[vc[i]] = vnum[i];
		for (int i = 0; i < n; i++) {
			int now = 0;
			for (int j = 0; j < vs[i].size(); j++) {
				now = now * 10 + c[vs[i][j]];
			}
			tempsum += now;
		}
		if (ans < tempsum)	ans = tempsum;
	} while (next_permutation(vnum.begin(), vnum.end()));
	cout << ans << "\n";
}