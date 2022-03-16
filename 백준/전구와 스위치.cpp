#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> initial;
vector<int> target;

int INF = 100001;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	string initialString;
	string targetString;

	cin >> initialString;
	cin >> targetString;

	for (int i = 0; i < N; i++) {
		initial.push_back(initialString[i] - '0');
		target.push_back(targetString[i] - '0');
	}

	int cntWhenFirstIndexClicked = 0;
	int cntWhenFirstIndexNotClicked = 0;

	// 0번 idx 클릭했을 때
	vector<int> current = initial;
	current[0] = !current[0];
	current[1] = !current[1];
	cntWhenFirstIndexClicked++;

	for (int i = 1; i < N; i++) {
		if (current[i - 1] != target[i - 1]) { //클릭해야함
			current[i - 1] = !current[i - 1];
			current[i] = !current[i];
			if (i + 1 < N) {
				current[i + 1] = !current[i + 1];
			}
			cntWhenFirstIndexClicked++;
		}
	}
	if (current[N - 1] != target[N - 1]) {
		cntWhenFirstIndexClicked = INF;
	}

	// 0번 idx 클릭 안했을 때
	current = initial;
	for (int i = 1; i < N; i++) {
		if (current[i - 1] != target[i - 1]) { //클릭해야함
			current[i - 1] = !current[i - 1];
			current[i] = !current[i];
			if (i + 1 < N) {
				current[i + 1] = !current[i + 1];
			}
			cntWhenFirstIndexNotClicked++;
		}
	}
	if (current[N - 1] != target[N - 1]) {
		cntWhenFirstIndexNotClicked = INF;
	}

	int answer = min(cntWhenFirstIndexClicked, cntWhenFirstIndexNotClicked);
	if (answer == INF) {
		answer = -1;
	}

	cout << answer;
}