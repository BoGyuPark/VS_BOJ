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
	//temp�迭�� s*s�迭�� �ű��.
	char temp[51][51] = { 0, };
	int rend = x + s, cend = y + s, difW = 0, difB = 0;
	for (int i = x; i < rend; i++) 
		for (int j = y; j < cend; j++) 	temp[i - x][j - y] = a[i][j];
	//W�� �����Ҷ��� B�� �����Ҷ� ��
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (temp[i][j] == W[i][j]) difW++;
			if (temp[i][j] == B[i][j]) difB++;
		}
	}
	return (difW > difB ? difB : difW);
}
int main() {
	//n:��, m:��
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	// s*s�� Ž���ϱ����� ���� ����
	int ans = 2147483647;
	for (int i = 0; i <= n - s; i++)
		for (int j = 0; j <= m - s; j++) {
			int t = check(i, j);
			if (ans > t) ans = t;
		}
	cout << ans;
}