#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int T;

void getMinFileSize(int k, vector<int>& file) {
	int dp[501][501];

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = 0;
		}

	}

	for (int i = 1; i < k; i++) {
		for (int j = 0; j < k - i; j++) {
			// 구하고자 하는 것 : dp[j][j+i]
			int mini = INT_MAX;
			
			int sum = 0;
			for (int z = j; z <= j + i; z++) {
				sum += file[z];
			}

			for (int z = j; z < j + i; z++) {
				mini = min(mini, dp[j][z] + dp[z + 1][j + i] + sum);
			}
			dp[j][j + i] = mini;
		}
	}
	cout << dp[0][k - 1] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int k;
		cin >> k;

		vector<int> file;
		for (int i = 0; i < k; i++) {
			int fileSize;
			cin >> fileSize;
			file.push_back(fileSize);
		}
		
		getMinFileSize(k, file);
	}
}