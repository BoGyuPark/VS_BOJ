/*BOJ 2562 ÃÖ´ñ°ª*/
#include<iostream>
#include<algorithm>
using namespace std;
const int n = 9;
int li[10], order[101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {cin >> li[i]; order[li[i]] = i + 1;}
	sort(li, li + n);
	cout << li[8] << '\n' << order[li[8]];
}