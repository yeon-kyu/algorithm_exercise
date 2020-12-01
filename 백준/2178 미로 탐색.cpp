#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int n, m;
char matrix[101][101];
bool visited[10000];
int cnt[101][101];

void init() {
	cin >> n >> m;
	memset(matrix, '0', sizeof(matrix));
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= m; j++) {
			matrix[i][j] = temp[j - 1];
		}
	}
}

int getNodeNum(int a, int b) {
	return m * (a - 1) + b;
}

void doBFS(int row, int col) {
	int node_num = m * (row - 1) + col;
	visited[node_num] = true;
	queue<pair<int, int> > q;
	q.push(pair<int, int>(row, col));

	cnt[row][col] = 1;

	//cout << "row : " << row << ", col : " << col << endl;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		int r = temp.first;
		int c = temp.second;
		node_num = getNodeNum(r, c);

		//cout << node_num <<" &"<< "row : " << r << ", col : " << c << endl;
		if (node_num == n * m) {
			//cout << "정상종료" << endl;
			break;
		}

		if (matrix[r - 1][c] == '1'&&visited[node_num - m] == false) {
			q.push(pair<int, int>(r - 1, c));
			visited[node_num - m] = true;
			cnt[r - 1][c] = cnt[r][c] + 1;
		}
		if (matrix[r + 1][c] == '1'&&visited[node_num + m] == false) {
			q.push(pair<int, int>(r + 1, c));
			visited[node_num + m] = true;
			cnt[r + 1][c] = cnt[r][c] + 1;
		}
		if (matrix[r][c - 1] == '1'&&visited[node_num - 1] == false) {
			q.push(pair<int, int>(r, c - 1));
			visited[node_num - 1] = true;
			cnt[r][c - 1] = cnt[r][c] + 1;
		}
		if (matrix[r][c + 1] == '1'&&visited[node_num + 1] == false) {
			q.push(pair<int, int>(r, c + 1));
			visited[node_num + 1] = true;
			cnt[r][c + 1] = cnt[r][c] + 1;
		}

	}
}

int main() {
	init();

	doBFS(1, 1);
	cout << cnt[n][m] << endl;
}