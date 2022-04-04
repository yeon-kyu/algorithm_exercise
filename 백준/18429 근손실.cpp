#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, K;
int w[51];
bool visited[51] = { false };
int answer = 0;

void increaseCounterIfAlwaysOver(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (w[v[i]] - K);
		if (sum < 0) {
			return;
		}
	} 
	answer++;
}

void brute(int pos, vector<int> v) {
	v.push_back(pos);

	if (v.size() == N) {
		increaseCounterIfAlwaysOver(v);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			brute(i, v);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < N; i++) {
		vector<int> v;
		visited[i] = true;
		brute(i, v);
		visited[i] = false;
	}

	cout << answer;
}