#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int n;

struct point {
	int pos;
	int power;
	int dp; //사는 비콘 수
};
vector<struct point> p;

bool compare(struct point a, struct point b) {
	return a.pos < b.pos;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//n개의 스위치
	//i번째 스위치는 pos_i포지션..pos는서로 다름
	//pow_i의 파워
	//beacon이 켜지면 모든 왼쪽에있는 beacon이 파괴된다.
	//(그 beacon의 파워만큼 거리(inclusive하게))
	//하지만 그 beacon은 살아있음
	//최소로 죽는 beacon의 수를 구해라

	cin >> n;
	struct point temp;
	p.push_back(temp);
	for (int i = 1; i <= n; i++) {
		cin >> temp.pos >> temp.power;
		p.push_back(temp);
	}
	sort(p.begin(), p.end(),compare);

	p[0].dp = 0; p[0].pos = INT_MIN;
	for (int i = 1; i <= n; i++) {
	
		int bar = p[i].pos - p[i].power;
		for (int z = 1; z <= i; z++) {
			if (p[i - z].pos >= bar) {//죽어야함
				//cout << "dead" << endl;
			}
			else {
				p[i].dp = p[i - z].dp + 1;
				break;
			}
		}

	}
	int min = n;
	for (int i = 1; i <= n; i++) {
		int temp; //오른쪽부터 i번째까지만 살렸을 때 죽은놈 수
		temp = (n - p[i].dp);
		if (temp < min) {
			min = temp;
		}
	}
	cout << min;

}