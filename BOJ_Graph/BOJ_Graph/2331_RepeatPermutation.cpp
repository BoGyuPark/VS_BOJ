//BOJ_2331_RepeatPermutation
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
int check[236197];
int k, ans;
int ppow(int x)
{
	string str = to_string(x);
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += pow(str[i]-'0', k);
	}
	return sum;
}

void Repeat(int node)
{
	int cnt = 1;
	check[node] = cnt;

	while (1) {
		int next = ppow(node);
		if (check[next] != 0) {
			ans = check[next];
			return;
		}
		else {
			check[next] = ++cnt;
			node = next;
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n >> k;
	Repeat(n);
	cout << ans - 1;
	return 0;
}