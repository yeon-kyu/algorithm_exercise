#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int M;
int N;

int mat[701][701];

int getMax(int a, int b, int c) {
	int temp = max(a, b);
	return max(temp, c);
}

void growOthers() {
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			mat[i][j] = getMax(mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			mat[i][j] = 1;
		}
	}

	vector<int> v(2 * M - 1, 0);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a] += 1;
		v[a + b] += 1;
	}

	vector<int> sumV(2 * M);
	sumV[0] = 0;
	for (int i = 0; i < v.size(); i++) {
		sumV[i + 1] = sumV[i] + v[i];
	}

	for (int j = 0; j < M; j++) {
		mat[M - 1 - j][0] += sumV[j+1];
	}
	for (int j = 1; j < M; j++) {
		mat[0][j] += sumV[M + j];
	}

	growOthers();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << mat[i][j]<<' ';
		}
		cout << endl;
	}
}