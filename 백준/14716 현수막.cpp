#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool mat[251][251] = { false };
bool visited[251][251] = { false };

void DFS(int i, int j) {
	if (mat[i][j] == false) {
		return;
	}
	if (visited[i][j]) {
		return;
	}
	visited[i][j] = true;

	if (i > 0) {
		//visited[i - 1][j] = true; //그냥 위
		DFS(i - 1, j);
		if (j > 0) { //위 왼쪽
			//visited[i - 1][j - 1] = true;
			DFS(i - 1, j - 1);
		}
		if (j < N - 1) { //위 오른쪽
			//visited[i - 1][j + 1] = true;
			DFS(i - 1, j + 1);
		}
	}
	if (i < M - 1) {
		//visited[i + 1][j] = true; // 그냥 아래
		DFS(i + 1, j);
		if (j > 0) { //아래 왼쪽
			//visited[i + 1][j - 1] = true;
			DFS(i + 1, j - 1);
		}
		if (j < N - 1) { //아래 오른쪽
			//visited[i + 1][j + 1] = true;
			DFS(i + 1, j + 1);
		}
	}
	if (j > 0) {
		//visited[i][j - 1] = true; // 그냥 왼쪽
		DFS(i, j - 1);
	}
	if (j < N - 1) {
		//visited[i][j + 1] = true; //그냥 오른쪽
		DFS(i, j + 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		int temp;
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 1) {
				mat[i][j] = true;
			}
			else {
				mat[i][j] = false;
			}
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j]) {

				if (visited[i][j] == false) {
					DFS(i, j);
					cnt++;
					//cout << "i : " << i << ", j : " << j << endl;
				}
			}
			
		}
	}
	cout << cnt;


	return 0;
}