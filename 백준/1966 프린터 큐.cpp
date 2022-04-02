#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int T;
int N, M;

bool isFrontPoppable(vector<pair<int, int>>& v) {
	int size = v.size();
	for (int i = 1; i < size; i++) {
		if (v[i].first > v[0].first) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		// N : 문서의 갯수
		// M : 궁금한 문서 위치
		vector<pair<int, int>> v;
		for (int j = 0; j < N; j++) {
			int priority;
			cin >> priority;
			v.push_back(make_pair(priority, j));
		}

		int ans = 0;
		while (true) {
			if (isFrontPoppable(v)) {
				ans++;
				if (v[0].second == M) {
					break;
				}
				v.erase(v.begin());
			}
			else {
				v.push_back(v[0]);
				v.erase(v.begin());
			}
		}
		cout << ans << '\n';
	}
}