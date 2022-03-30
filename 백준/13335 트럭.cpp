#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, W, L;
queue<int> ready;
queue<int> going;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> W >> L;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		ready.push(temp);
	}

	for (int i = 0; i < W; i++) {
		going.push(0);
	}

	int answer = 0;

	int weight = 0;
	while (!ready.empty()) {
		int out = going.front();
		going.pop();

		weight -= out;
		if (weight + ready.front() <= L) {
			weight += ready.front();
			going.push(ready.front());
			ready.pop();
		}
		else {
			going.push(0); //트럭 대신 공기를 넣는다
		}
		answer++;
	}
	answer += W;

	cout << answer;
}