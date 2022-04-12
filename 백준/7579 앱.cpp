#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
vector<int> A;
vector<int> C;

int dp[101][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// An : 사용하는 메모리
	// Cn : 다시 실행할 때 들어가는 비용

	// M : 필요한 메모리
	// Cn의 합을 최소화하여 메모리를 확보해야한다.

	cin >> N >> M;

	A.resize(N);
	C.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 10001; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		int a = A[i - 1];
		int c = C[i - 1];

		for (int j = 0; j < c; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		for (int j = c; j < 10001; j++) {
			dp[i][j] = max(dp[i - 1][j - c] + a, dp[i - 1][j]);
		}
	}

	for (int j = 0; j < 10001; j++) {
		if (dp[N][j] >= M) {
			cout << j;
			break;
		}
	}
}