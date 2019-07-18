/*BOJ 15661 링크와 스타트*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, arr[20][20];
vector<int> st, li;
int ans = 2147483647;
int stSum = 0, liSum = 0;
void go(int index) {
	if (index == n) {
		ans = min(ans, abs(stSum - liSum));
		return;
	}
	if (st.size() < n - 1) {
		for (int a = 0; a < st.size(); a++) {
			stSum += (arr[st[a]][index] + arr[index][st[a]]);
		}
		st.push_back(index);
		go(index + 1);
		for (int a = 0; a < st.size() - 1; a++) {
			stSum -= (arr[st[a]][index] + arr[index][st[a]]);
		}
		st.pop_back();
	}
	
	if (li.size() < n - 1) {
		for (int a = 0; a < li.size(); a++) {
			liSum += (arr[li[a]][index] + arr[index][li[a]]);
		}
		li.push_back(index);
		go(index + 1);
		for (int a = 0; a < li.size() - 1; a++) {
			liSum -= (arr[li[a]][index] + arr[index][li[a]]);
		}
		li.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	go(0);
	cout << ans;
}