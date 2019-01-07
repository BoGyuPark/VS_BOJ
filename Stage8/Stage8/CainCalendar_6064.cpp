//BOJ_Cain Calendar_6064
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	int x, y, M, N, cnt;
	int Sx, Sy;
	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		cin >> M >> N >> Sx >> Sy;
		int tcnt = 0;
		//마지막 해인 k번째를 찾는다.
		if (M > N) 
		{
			y = N;
			x = y;
			tcnt += y;

			while (1)
			{
				if (x == M) {
					break;
				}
				tcnt += N;
				x = x + N - M;
				if (x <= 0)
					x += M;
			}
		}
		else
		{
			x = M;
			y = x;
			tcnt += x;
			while (1)
			{
				if (y == N) {
					break;
				}
				tcnt += M;
				y = y + M - N;
				if (y <= 0)
					y += N;
			}
		}


		if (M > N) 
		{
			y = Sy;
			x = y;
			cnt += y;

			while (1)
			{
				if (x == Sx) {
					cout << cnt << "\n";
					break;
				}
				//x가 x번째의 해, x + M * 여러번 으로 계산
				cnt += N;
				x = x + N - M;
				if (x <= 0)
					x += M;

				if (tcnt < cnt) {
					cout << -1 << "\n";
					break;
				}
			}
		}
		else
		{
			x = Sx;
			y = x;
			cnt += x;

			while (1)
			{
				if (y == Sy) {
					cout << cnt << "\n";
					break;
				}
				//x가 x번째의 해, x + M * 여러번 으로 계산
				cnt += M;
				y = y + M - N;
				if (y <= 0)
					y += N;

				if (tcnt < cnt) {
					cout << -1 << "\n";
					break;
				}
			}
		}
	}
	return 0;
}