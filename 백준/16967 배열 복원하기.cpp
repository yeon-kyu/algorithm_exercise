#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int H, W;
int X, Y;

vector<vector<int>> A;
int B[601][601];

void showA() {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W >> X >> Y;

	for (int i = 0; i < H + X; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> B[i][j];
		}
	}

	A.resize(H);
	for (int i = 0; i < H; i++) {
		A[i].resize(W);
	}

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < W; j++) {
			A[i][j] = B[i][j];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < Y; j++) {
			A[i][j] = B[i][j];
		}
	}

	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			A[i][j] = B[i][j] - A[i - X][j - Y];
		}
	}

	showA();
}