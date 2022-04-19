#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int A[37][5][5];
int mat[5][5];
int ans[37][5][5];

vector<int> getCalcPosition(long long B) {
	vector<int> position;
	int cur = 0;
	while (B > 0) {
		if (B % 2 == 1) {
			position.push_back(cur);
		}

		cur++;
		B = B / 2;
	}
	return position;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long B;

	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	vector<int> position = getCalcPosition(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[0][i][j] = mat[i][j];
		}
	}

	int end = position[position.size() - 1];
	for (int k = 1; k <= end; k++) {
		// 구하고자 하는 것 : A[k][][]
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				A[k][i][j] = 0;
				for (int a = 0; a < N; a++) {
					A[k][i][j] += A[k - 1][i][a] * A[k - 1][a][j];
				}
				A[k][i][j] %= 1000;
			}
		}
	}

	reverse(position.begin(), position.end());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[0][i][j] = A[position[0]][i][j] % 1000;
		}
	}
	
	int size = position.size();
	for (int k = 1 ; k < size; k++) {
		// 구하고자 하는 것 : ans[k][][]
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[k][i][j] = 0;
				for (int a = 0; a < N; a++) {
					ans[k][i][j] += ans[k - 1][i][a] * A[position[k]][a][j];
				}
				ans[k][i][j] %= 1000;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[size - 1][i][j] << ' ';
		}
		cout << endl;
	}
}