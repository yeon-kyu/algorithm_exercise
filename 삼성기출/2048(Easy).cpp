#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;
int ans = 0;

void check_big(int mat[21][21]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, mat[i][j]);
		}
	}
}

void do_dfs(int cnt, int mat[21][21]) {

	if (cnt == 5) {
		check_big(mat);
		return;
	}

	//오른쪽, 왼쪽, 위, 아래 돌리기

	int m[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = mat[i][j];
		}
	}
	//오른쪽
	for (int i = 0; i < N; i++) {

		for (int j = N - 2; j >= 0; j--) { //오른쪽으로 미는 작업
			int cur = m[i][j];
			if (cur != 0) { //이 오른쪽에 0이 몇개 있는지
				int zero_cnt = 0;
				for (int k = N - 1; k > j; k--) {
					if (m[i][k] == 0) {
						zero_cnt++;
					}
				}

				if (zero_cnt != 0) {
					m[i][j + zero_cnt] = m[i][j];
					m[i][j] = 0;
				}
				
			}
		}

		for (int j = N-1; j > 0; j--) { //합치는 작업 진행
			int cur = m[i][j]; 

			if (m[i][j] == m[i][j - 1]) {
				m[i][j] = cur * 2;
				m[i][j - 1] = 0;
				j--;
			}
		}

		for (int j = N - 2; j >= 0; j--) { //오른쪽으로 미는 작업
			int cur = m[i][j];
			if (cur != 0) { //이 오른쪽에 0이 몇개 있는지
				int zero_cnt = 0;
				for (int k = N - 1; k > j; k--) {
					if (m[i][k] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i][j + zero_cnt] = m[i][j];
					m[i][j] = 0;
				}
			}
		}
	}
	do_dfs(cnt + 1, m);

	//왼쪽
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = mat[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N - 1; j++) { //왼쪽으로 미는 작업
			int cur = m[i][j];
			if (cur != 0) { //이 왼쪽에 0이 몇개 있는지
				int zero_cnt = 0;
				for (int k = 0; k < j; k++) {
					if (m[i][k] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i][j - zero_cnt] = m[i][j];
					m[i][j] = 0;
				}
			}
		}

		for (int j = 0; j < N-1; j++) { //합치는 작업 진행
			int cur = m[i][j];

			if (m[i][j] == m[i][j + 1]) {
				m[i][j] = cur * 2;
				m[i][j + 1] = 0;
				j++;
			}
		}

		for (int j = 1; j <= N - 1; j++) { //왼쪽으로 미는 작업
			int cur = m[i][j];
			if (cur != 0) { //이 왼쪽에 0이 몇개 있는지
				int zero_cnt = 0;
				for (int k = 0; k < j; k++) {
					if (m[i][k] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i][j - zero_cnt] = m[i][j];
					m[i][j] = 0;
				}
			}
		}
	}
	do_dfs(cnt + 1, m);

	//위로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = mat[i][j];
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 1; i < N; i++) { //올리기
			int cur = m[i][j];
			if (cur != 0) {
				int zero_cnt = 0;
				for (int k = 0; k < i; k++) {
					if (m[k][j] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i - zero_cnt][j] = m[i][j];
					m[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < N - 1; i++) { //합치기
			int cur = m[i][j];

			if (m[i][j] == m[i + 1][j]) {
				m[i][j] = cur * 2;
				m[i + 1][j] = 0;
				i++;
			}
		}

		for (int i = 1; i < N; i++) { //올리기
			int cur = m[i][j];
			if (cur != 0) {
				int zero_cnt = 0;
				for (int k = 0; k < i; k++) {
					if (m[k][j] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i - zero_cnt][j] = m[i][j];
					m[i][j] = 0;
				}
			}
		}
	}
	do_dfs(cnt + 1, m);

	//아래로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = mat[i][j];
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = N - 2; i >= 0; i--) {
			int cur = m[i][j];
			if (cur != 0) {
				int zero_cnt = 0;
				for (int k = N - 1; k > i; k--) {
					if (m[k][j] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i + zero_cnt][j] = m[i][j];
					m[i][j] = 0;	
				}
			}
		}

		for (int i = N - 1; i > 0; i--) {
			int cur = m[i][j];

			if (m[i][j] == m[i - 1][j]) {
				m[i][j] = cur * 2;
				m[i - 1][j] = 0;
				i--;
			}
		}

		for (int i = N - 2; i >= 0; i--) {
			int cur = m[i][j];
			if (cur != 0) {
				int zero_cnt = 0;
				for (int k = N - 1; k > i; k--) {
					if (m[k][j] == 0) {
						zero_cnt++;
					}
				}
				if (zero_cnt != 0) {
					m[i + zero_cnt][j] = m[i][j];
					m[i][j] = 0;
				}
			}
		}
	}
	do_dfs(cnt + 1, m);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int mat[21][21];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	do_dfs(0, mat);

	cout << ans;
}