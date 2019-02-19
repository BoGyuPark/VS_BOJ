#include<iostream>
#include<string>
const int s = 8;
using namespace std;
int n, m;
char a[51][51];
string W[] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string B[] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};
int check(int x, int y) {
	//temp배열에 s*s배열로 옮긴다.
	char temp[51][51] = { 0, };
	int rend = x + s, cend = y + s, difW = 0, difB = 0;
	for (int i = x; i < rend; i++) 
		for (int j = y; j < cend; j++) 	temp[i - x][j - y] = a[i][j];
	//W로 시작할때와 B로 시작할때 비교
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (temp[i][j] == W[i][j]) difW++;
			if (temp[i][j] == B[i][j]) difB++;
		}
	}
	return (difW > difB ? difB : difW);
}
int main() {
	//n:행, m:열
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	// s*s를 탐색하기위한 범위 지정
	int ans = 2147483647;
	for (int i = 0; i <= n - s; i++)
		for (int j = 0; j <= m - s; j++) {
			int t = check(i, j);
			if (ans > t) ans = t;
		}
	cout << ans;
}