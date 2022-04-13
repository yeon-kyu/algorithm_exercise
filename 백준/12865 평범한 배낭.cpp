#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;

vector<int> w;
vector<int> v;

int dp[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	w.resize(N);
	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}

	for (int j = 0; j <= K; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i <= N; i++) {
		int weight = w[i - 1];
		int value = v[i - 1];

		for (int j = 0; j < weight; j++) {
			dp[i][j] = dp[i - 1][j];
		}

		for (int j = weight; j <= K; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
		}
	}

	cout << dp[N][K];
}