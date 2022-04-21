#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int A, B, C;

vector<int> v;

int getUnique(vector<int> v) {
	return v[0] * 250000 + v[1] * 500 + v[2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	int sum = A + B + C;

	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}

	queue<vector<int>> q;
	set<int> s;

	vector<int> temp = { A, B, C };
	sort(temp.begin(), temp.end());

	q.push(temp);
	s.insert(getUnique(temp));

	int answer = 0;
	
	while(q.empty() == false) {
		vector<int> cur = q.front();
		q.pop();

		if (cur[0] == cur[1] && cur[1] == cur[2]) {
			answer = 1;
			break;
		}

		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 3; j++) {
				int a = cur[i];
				int b = cur[j];
				if (a != b) {
					if (a < b) { 
						b -= a;
						a += a;
					}
					else if (a > b) {
						a -= b;
						b += b;
					}

					int c = sum - a - b;
					vector<int> temp = { a, b, c };
					sort(temp.begin(), temp.end());

					int id = getUnique(temp);
					if (s.find(id) == s.end()) {
						q.push(temp);
						s.insert(id);
					}
				}
			}
		}
	}
	cout << answer;
}