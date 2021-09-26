#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
int mat[501][501];

int ans = 4;

void check_type1() { //가로 1자
	//원형 그대로
	for (int i = 0; i < N; i++) {
		for (int j = 3; j < M; j++) {
			int sum = mat[i][j - 3] + mat[i][j - 2] + mat[i][j - 1] + mat[i][j];
			ans = max(sum, ans);
		}
	}

	//90도 회전
	for (int i = 3; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sum = mat[i - 3][j] + mat[i - 2][j] + mat[i - 1][j] + mat[i][j];
			ans = max(sum, ans);
		}
	}
}

void check_type2() { // 2x2 사각형
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int sum = mat[i - 1][j] + mat[i - 1][j - 1] + mat[i][j - 1] + mat[i][j];
			ans = max(sum, ans);
		}
	}
}

void check_type3() { //ㄴ자 사각형
	//원형 그대로
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int sum = mat[i - 2][j - 1] + mat[i - 1][j - 1] + mat[i][j-1] + mat[i][j];
			ans = max(sum, ans);
		}
	}

	//원형에서 좌우 대칭
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int sum = mat[i - 2][j] + mat[i - 1][j] + mat[i][j] + mat[i][j - 1];
			ans = max(sum, ans);
		}
	}

	// ..: 모양
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int sum = mat[i - 1][j] + mat[i][j - 2] + mat[i][j - 1] + mat[i][j];
			ans = max(sum, ans);
		}
	}

	// :.. 모양
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int sum = mat[i - 1][j - 2] + mat[i][j - 2] + mat[i][j - 1] + mat[i][j];
			ans = max(sum, ans);
		}
	}

	// :'' 모양
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int sum = mat[i - 1][j - 2] + mat[i - 1][j - 1] + mat[i - 1][j] + mat[i][j - 2];
			ans = max(sum, ans);
		}
	}

	// '': 모양
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int sum = mat[i - 1][j - 2] + mat[i - 1][j - 1] + mat[i - 1][j] + mat[i][j];
			ans = max(sum, ans);
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int sum = mat[i - 2][j - 1] + mat[i - 2][j] + mat[i - 1][j - 1] + mat[i][j - 1];
			ans = max(sum, ans);

			sum = mat[i - 2][j - 1] + mat[i - 2][j] + mat[i - 1][j] + mat[i][j];
			ans = max(sum, ans);
		}
	}
}

void check_type4() {
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int sum = mat[i - 2][j - 1] + mat[i - 1][j - 1] + mat[i - 1][j] + mat[i][j];
			ans = max(sum, ans);

			sum = mat[i - 2][j] + mat[i - 1][j - 1] + mat[i - 1][j] + mat[i][j - 1];
			ans = max(sum, ans);
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int sum = mat[i][j - 2] + mat[i][j - 1] + mat[i - 1][j - 1] + mat[i - 1][j];
			ans = max(sum, ans);

			sum = mat[i - 1][j - 2] + mat[i - 1][j - 1] + mat[i][j - 1] + mat[i][j];
			ans = max(sum, ans);
		}
	}
}

void check_type5() {
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int sum = mat[i - 1][j - 2] + mat[i - 1][j - 1] + mat[i - 1][j] + mat[i][j - 1];
			ans = max(sum, ans);

			sum = mat[i][j - 2] + mat[i][j - 1] + mat[i][j] + mat[i - 1][j - 1];
			ans = max(sum, ans);
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 1; j < M; j++) {
			int sum = mat[i - 2][j - 1] + mat[i - 1][j - 1] + mat[i][j - 1] + mat[i - 1][j];
			ans = max(sum, ans);

			sum = mat[i - 2][j] + mat[i - 1][j] + mat[i][j] + mat[i - 1][j - 1];
			ans = max(sum, ans);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	check_type1();
	check_type2();
	check_type3();
	check_type4();
	check_type5();

	cout << ans;
	
}