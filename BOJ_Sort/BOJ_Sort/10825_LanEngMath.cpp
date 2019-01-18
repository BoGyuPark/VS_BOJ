//BOJ_10825_LanEngMath
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Person {
	string name;
	int lan, eng, math;
};
bool cmp(const Person &a, const Person &b)
{
	if (a.lan > b.lan) {
		return true;
	}
	else if (a.lan == b.lan) {
		if (a.eng < b.eng) {
			return true;
		}
		else if (a.eng == b.eng) {
			if (a.math > b.math) {
				return true;
			}
			else if (a.math == b.math) {
				return a.name < b.name;
			}
		}
	}
	return false;
}

int main()
{
	int n; cin >> n;
	vector<Person> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].lan >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), cmp);
	for (auto &p : v)
		cout << p.name << '\n';
	return 0;
}